//
// Created by kir on 04.07.19.
//

#include "../Logger.h"
#include "../network/TcpSocket.h"
#include "SpectatorsDispatcher.h"
#include "packages/GameContextPackage.h"
#include "Game.h"

using namespace std::string_literals;

SpectatorsDispatcher::SpectatorsDispatcher(Game *game, TcpServer *server) :
        _game{ game },
        _server(server)
{
    Logger::getInstace().log("Initializing connection point for spectators.");
    server->setConnectionAcceptedListener(this);
    server->listen(11555);
}

SpectatorsDispatcher::~SpectatorsDispatcher()
{
    Logger::getInstace().log("Connection point for spectators is closed.");
    _server->close();
    for (auto spec : _spectators) {
        delete spec;
    }
}

void SpectatorsDispatcher::onConnectionAccepted(const TcpServer *server, TcpSocket *socket)
{
    Logger::getInstace().info("New spectator joined.");
    socket->setConnectionClosedListener(this);
    socket->setDataArrivedListener(this);
    _spectators.push_back(socket);
}

void SpectatorsDispatcher::broadcast(const nlohmann::json &json)
{
    for (auto spec : _spectators) {
        spec->write(json);
    }
}

void SpectatorsDispatcher::onConnectionClosed(const TcpSocket *socket)
{
    Logger::getInstace().info("Spectator disconnected.");
    auto it = std::remove(_spectators.begin(), _spectators.end(), socket);
    std::for_each(it, _spectators.end(),
            [](TcpSocket *socket) {
                delete socket;
            });
    _spectators.erase(it, _spectators.end());
}

void SpectatorsDispatcher::onDataArrived(TcpSocket *socket, nlohmann::json &json)
{
    Logger::getInstace().log("Spectator sent some data... ");
    if (!json.contains("requestId")) {
        throw std::logic_error("Corrupted package.");
    }
    uint32_t requestId = json["requestId"];
    if (requestId == 0) {
        GameContextPackage pkg(_game->getContext());
        socket->write(pkg);
    }
}

void SpectatorsDispatcher::broadcast(const Package &package)
{
    nlohmann::json json;
    package.toJson(json);
    broadcast(json);
}
