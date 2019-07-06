//
// Created by vinokurov on 29.06.2019.
//

#include "Game.h"
#include "cards/locations/LocationCard.h"
#include "CardMetadataProvider.h"
#include "../Logger.h"
#include "../network/WebSocketServer.h"

using namespace std::string_literals;

Game::Game(Card *scenario, std::string_view securityKey) :
    _playerServer{ new WebSocketServer() },
    _securityKey{ securityKey },
    _spectatorDispatcher{ new SpectatorsDispatcher(new WebSocketServer()) },
    _context{ new GameContext() }
{
    _context->setScenario(dynamic_cast<Scenario *>(scenario));

    _playerServer->setConnectionAcceptedListener(this);
    _playerServer->listen(10555);
}

void Game::onConnectionAccepted(const TcpServer *server, TcpSocket *socket) {
    socket->setDataArrivedListener(this);
    socket->setConnectionClosedListener(this);
    if (server == _playerServer) {
        Logger::getInstace().log("New player connected");
        _players.push_back(new Player(socket));
    }
}

void Game::onConnectionClosed(const TcpSocket *socket) {
    Logger::getInstace().log("Someone disconnect...");
}

void Game::onDataArrived(TcpSocket *socket, nlohmann::json &json) {
    auto player = getPlayerBySocket(socket);
    if (player == nullptr) {
        Logger::getInstace().log("User not found");
        return;
    }
    Logger::getInstace().log("Receive: "s + json.dump());
    int eventId = json["eventId"];
}

Player *Game::getPlayerBySocket(const TcpSocket *socket) {
    auto it = std::find_if(_players.begin(), _players.end(),
                     [socket](const Player *item) -> bool {
                         return item->getTransportPipeConst() == socket;
                     });
    return it == _players.end() ? nullptr : *it;
}

Game::~Game()
{
    delete _spectatorDispatcher;
    delete _playerServer;
    delete _context;
}

GameContext *Game::getContext()
{
    return _context;
}
