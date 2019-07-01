//
// Created by vinokurov on 29.06.2019.
//

#include "Game.h"
#include "cards/locations/LocationCard.h"
#include "CardMetadataProvider.h"
#include "../Logger.h"
#include "../network/WebSocket.h"

using namespace std::string_literals;

Game::Game(Card *scenario) :
    _scenario{ scenario },
    _webServer{ new WebSocketServer() },
    _playerServer{ new TcpServer() },
    _movesLeft{ 50 }
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
        Logger::getInstace().log("New player connected");
        _players.emplace_back(socket, new Player());
    } else {
        Logger::getInstace().log("New spectator connected");
        dynamic_cast<WebSocket *>(socket)->setOnWebSocketSessionInitListener(this);
        _spectators.push_back(socket);
    }
}

void Game::onConnectionClosed(const TcpSocket *socket) {
    Logger::getInstace().log("Someone disconnect...");
    _spectators.erase(std::remove(_spectators.begin(), _spectators.end(), socket), _spectators.end());
    //_players.erase(std::remove(_players.begin(), _players.end(), socket), _players.end());
}

void Game::onDataArrived(TcpSocket *socket, nlohmann::json &json) {
    auto player = getPlayerBySocket(socket);
    if (player == nullptr) {
        Logger::getInstace().log("User not found");
        return;
    }
    Logger::getInstace().log("Receive: "s + json.dump());
    nlohmann::json answer, dataObject, broadcastMessage;
    int eventId = json["eventId"];
    answer["eventId"] = eventId;
    Logger::getInstace().log("Event: "s + std::to_string(eventId));
    switch (eventId) {
        case 1:
        {
            player->setName(json["data"]["id"]);
            _scenarioMetadata->toJson(dataObject);
            break;
        }

        case 2:
        {
            auto locationId = json["data"]["locationId"];
            auto it = std::find_if(_locations.begin(), _locations.end(),
                    [locationId](std::shared_ptr<Card> card) -> bool {
                        return card->getTypeId() == locationId;
                    });
            player->setLocation(*it);
            dynamic_cast<LocationCard *>((*it).get())->toJson(dataObject);
            broadcastMessage["eventId"] = 1;
            broadcastMessage["user"] = player->getName();
            broadcastMessage["userPerson"] = "Харск";
            broadcastMessage["data"]["user"]["name"] = player->getName();
            broadcastMessage["data"]["user"]["person"] = "Харск";
            broadcastMessage["data"]["user"]["location"] = dataObject;
            broadcast(_spectators, broadcastMessage);
            break;
        }

        case 3: {
            broadcastMessage["eventId"] = 1;
            broadcastMessage["user"] = player->getName();
            broadcastMessage["userPerson"] = "Харск";
            broadcastMessage["data"]["user"]["name"] = player->getName();
            broadcastMessage["data"]["user"]["person"] = "Харск";
            broadcastMessage["data"]["user"]["location"] = dataObject;
            broadcastMessage["data"]["moves_left"] = _movesLeft;
            broadcastMessage["data"]["moves_left"] = _movesLeft;
            broadcast(_spectators, broadcastMessage);

            dataObject["moves_left"] = _movesLeft;
            dataObject["location"] = dataObject;

            nlohmann::json locationMetadataJson;
            dynamic_cast<const LocationCardMetadata *>(player->getLocation()->getMetadata())->toJson(locationMetadataJson);
            dataObject["location_info"] = locationMetadataJson;
            break;
        }
    }
    answer["data"] = dataObject;
    Logger::getInstace().log("Answer: "s + answer.dump());
    socket->write(answer);
}

void Game::broadcast(std::vector<TcpSocket *> &sockets, nlohmann::json &json) {
    Logger::getInstace().log("Broadcast: "s + json.dump());
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

void Game::onSessionInit(WebSocket *socket) {
    nlohmann::json gameInfo;

    gameInfo["eventId"] = 0;
    gameInfo["user"] = "John";
    gameInfo["userPerson"] = "Харск";

    nlohmann::json dataObject;
    _scenarioMetadata->toJson(dataObject);
    gameInfo["data"] = dataObject;


    Logger::getInstace().log("Game Info: "s + gameInfo.dump());
    socket->write(gameInfo);
}
