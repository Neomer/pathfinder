//
// Created by vinokurov on 29.06.2019.
//

#include "Game.h"
#include "cards/locations/LocationCard.h"
#include "CardMetadataProvider.h"
#include "../Logger.h"

Game::Game(Card *scenario) :
    _scenario{ scenario },
    _webServer{ new WebSocketServer() },
    _playerServer{ new TcpServer() }
{
    _scenarioMetadata = dynamic_cast<const ScenarioMetadata *>
    (CardMetadataProvider::getInstance().getMetadata(scenario->getTypeId()));

}

void Game::run(int numPlayers) {

    std::for_each(_scenarioMetadata->getLocationsByPlayers().begin(), _scenarioMetadata->getLocationsByPlayers().end(),
            [this, numPlayers](const std::pair<int, int> &loc) {
                if (loc.first <= numPlayers) {
                    auto metadata = CardMetadataProvider::getInstance().getMetadata(loc.second);
                    if (metadata != nullptr) {
                        auto location = metadata->createInstance();
                        dynamic_cast<LocationCard *>(location.get())->createDeck();
                        this->_locations.push_back(location);
                    }
                }
            });

    _playerServer->setConnectionAcceptedListener(this);
    _playerServer->listen(10555);

    _webServer->setConnectionAcceptedListener(this);
    _webServer->listen(11555);

}

void Game::onConnectionAccepted(const TcpServer *server, TcpSocket *socket) {
    socket->setDataArrivedListener(this);
    socket->setConnectionClosedListener(this);
    if (server == _playerServer) {
        _players.emplace_back(socket, new Player());
    } else {
        _spectators.push_back(socket);
    }
}

void Game::onConnectionClosed(const TcpSocket *socket) {
    Logger::getInstace().log("Someone disconnect...");
    _spectators.erase(std::remove(_spectators.begin(), _spectators.end(), socket), _spectators.end());
    /*
    _players.erase(std::remove_if(_spectators.begin(), _spectators.end(),
            [socket](const std::pair<TcpSocket *, Player *> &item) -> bool {
                return item.first == socket;
            }), _spectators.end());
    */
}

void Game::onDataArrived(const TcpSocket *socket, nlohmann::json &json) {
    int eventId = json["eventId"];
    switch (eventId) {
        case 1:
        {
            auto player = getPlayerBySocket(socket);
            if (player != nullptr) {
                player->setName(json["data"]["id"]);
                nlohmann::json answer;
                answer["eventId"] = 1;
                answer["user"] = player->getName();
                answer["userPerson"] = "Харск";
                broadcast(_spectators, answer);
            }
            break;
        }
    }
}

void Game::broadcast(std::vector<TcpSocket *> &sockets, nlohmann::json &json) {
    for (auto item : sockets) {
        item->write(json);
    }
}

Player *Game::getPlayerBySocket(const TcpSocket *socket) {
    auto it = std::find_if(_players.begin(), _players.end(),
                     [socket](const std::pair<TcpSocket *, Player *> &item) -> bool {
                         return item.first == socket;
                     });
    return it == _players.end() ? nullptr : (*it).second;
}
