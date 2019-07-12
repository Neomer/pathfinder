//
// Created by kir on 04.07.19.
//

#ifndef GAME_SERVER_SPECTATORSDISPATCHER_H
#define GAME_SERVER_SPECTATORSDISPATCHER_H

#include <vector>
#include "../modules/json/single_include/nlohmann/json.hpp"
#include "../network/TcpServer.h"
#include "../network/IConnectionAcceptedListener.h"
#include "../network/IConnectionClosedListener.h"
#include "../network/IDataArrivedListener.h"
#include "../network/packages/Package.h"

class Game;

class SpectatorsDispatcher :
        public IConnectionAcceptedListener,
        public IConnectionClosedListener,
        public IDataArrivedListener
{
public:
    explicit SpectatorsDispatcher(Game *game, TcpServer *server);

    ~SpectatorsDispatcher();

    void onConnectionAccepted(const TcpServer *server, TcpSocket *socket) override;

    void onConnectionClosed(const TcpSocket *socket) override;

    void onDataArrived(TcpSocket *socket, nlohmann::json &json) override;

    void broadcast(const nlohmann::json &json);

    void broadcast(const Package &package);

private:
    TcpServer *_server;
    std::vector<TcpSocket *> _spectators;

    Game *_game;
};


#endif //GAME_SERVER_SPECTATORSDISPATCHER_H
