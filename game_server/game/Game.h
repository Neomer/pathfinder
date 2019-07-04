//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_GAME_H
#define GAME_SERVER_GAME_H

#include "cards/scenario/Scenario.h"
#include "../network/IConnectionAcceptedListener.h"
#include "../network/IConnectionClosedListener.h"
#include "../network/IDataArrivedListener.h"
#include "Player.h"
#include "SpectatorsDispatcher.h"


class TcpSocket;
class TcpServer;

class Game :
        public IConnectionAcceptedListener,
        public IConnectionClosedListener,
        public IDataArrivedListener
{
public:
    explicit Game(Card *scenario, std::string_view securityKey);

    virtual ~Game();

    void run(int numPlayers);

    void onConnectionAccepted(const TcpServer *server, TcpSocket *socket) override;

    void onConnectionClosed(const TcpSocket *socket) override;

    void onDataArrived(TcpSocket *socket, nlohmann::json &json) override;

private:
    void broadcast(std::vector<TcpSocket *> &sockets, nlohmann::json &json);
    Player *getPlayerBySocket(const TcpSocket *socket);

    std::string _securityKey;
    Card *_scenario;
    const ScenarioMetadata *_scenarioMetadata;
    std::vector<std::shared_ptr<Card>> _locations;
    uint8_t _movesLeft;

    TcpServer *_playerServer;
    std::vector<Player *> _players;

    SpectatorsDispatcher *_spectatorDispatcher;

};


#endif //GAME_SERVER_GAME_H
