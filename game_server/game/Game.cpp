//
// Created by vinokurov on 29.06.2019.
//

#include "Game.h"
#include "cards/locations/LocationCard.h"
#include "CardMetadataProvider.h"
#include "../Logger.h"
#include "../network/WebSocketServer.h"
#include "EventProvider.h"
#include "packages/GameContextPackage.h"

using namespace std::string_literals;

Game::Game(Card *scenario, std::string_view securityKey) :
    _playerServer{ new WebSocketServer() },
    _securityKey{ securityKey },
    _context{ }
{
    _spectatorDispatcher = new SpectatorsDispatcher(this, new WebSocketServer());
    _context.setScenario(dynamic_cast<Scenario *>(scenario));

    _playerServer->setConnectionAcceptedListener(this);
    _playerServer->listen(10555);
}

Game::~Game()
{
    delete _spectatorDispatcher;
    delete _playerServer;
}

GameContext &Game::getContext()
{
    return _context;
}

SpectatorsDispatcher *Game::getSpectatorDispatcher() const
{
    return _spectatorDispatcher;
}

void Game::onConnectionAccepted(const TcpServer *server, TcpSocket *socket) {
    socket->setDataArrivedListener(this);
    socket->setConnectionClosedListener(this);
    if (server == _playerServer) {
        Logger::getInstace().info("New player connected.");
        auto player = new Player(socket);
        _context.addPlayer(player);
    }
}

void Game::onConnectionClosed(const TcpSocket *socket) {
    Logger::getInstace().info("Someone disconnect...");
}

void Game::onDataArrived(TcpSocket *socket, nlohmann::json &json) {
    auto player = getPlayerBySocket(socket);
    if (player == nullptr) {
        Logger::getInstace().error("User not found.");
        return;
    }
    /*
    if (player != _context.getCurrentPlayer()) {
        Logger::getInstace().log("Package isn't from current player.");
        return;
    }
     */
    Logger::getInstace().log("Received: "s + json.dump());
    int eventId = json["eventId"];

    auto processor = EventProvider::getInstance().getEventProcessor(eventId);
    if (processor == nullptr) {
        Logger::getInstace().error("Unsupported event: "s + std::to_string(eventId));
        return;
    }
    processor->process(*player, json["data"], *this);

    // Send updated game context to spectators
    GameContextPackage gameContextPackage(getContext());
    getSpectatorDispatcher()->broadcast(gameContextPackage);
}

Player *Game::getPlayerBySocket(const TcpSocket *socket) {
    auto it = std::find_if(_context.getPlayers().begin(), _context.getPlayers().end(),
                     [socket](const Player *item) -> bool {
                         return item->getTransportPipeConst() == socket;
                     });
    return it == _context.getPlayers().end() ? nullptr : *it;
}