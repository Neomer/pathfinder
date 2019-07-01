//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_GAME_H
#define GAME_SERVER_GAME_H

#include "cards/scenario/Scenario.h"
#include "../network/WebSocketServer.h"
#include "../network/TcpServer.h"
#include "../network/IConnectionAcceptedListener.h"
#include "../network/IConnectionClosedListener.h"
#include "../network/IDataArrivedListener.h"
#include "../network/IWebSocketSessionInitListener.h"
#include "../network/TcpSocket.h"
#include "Player.h"


class Game :
        public IConnectionAcceptedListener,
        public IConnectionClosedListener,
        public IWebSocketSessionInitListener,
        public IDataArrivedListener
{
public:
    explicit Game(Card *scenario);

    void run(int numPlayers);

    void onConnectionAccepted(const TcpServer *server, TcpSocket *socket) override;

    void onConnectionClosed(const TcpSocket *socket) override;

    void onDataArrived(TcpSocket *socket, nlohmann::json &json) override;

    void onSessionInit(WebSocket *socket) override;

private:
    void broadcast(std::vector<TcpSocket *> &sockets, nlohmann::json &json);
    Player *getPlayerBySocket(const TcpSocket *socket);

    Card *_scenario;
    const ScenarioMetadata *_scenarioMetadata;
    std::vector<std::shared_ptr<Card>> _locations;
    uint8_t _movesLeft;

    TcpServer *_webServer, *_playerServer;
    std::vector<TcpSocket *> _spectators;
    std::vector<std::pair<TcpSocket *, Player *>> _players;

};


#endif //GAME_SERVER_GAME_H
