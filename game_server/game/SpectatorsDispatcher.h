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

class SpectatorsDispatcher :
        public IConnectionAcceptedListener,
        public IConnectionClosedListener,
        public IDataArrivedListener
{
public:
    explicit SpectatorsDispatcher(TcpServer *server);

    ~SpectatorsDispatcher();

    void onConnectionAccepted(const TcpServer *server, TcpSocket *socket) override;

    void onConnectionClosed(const TcpSocket *socket) override;

    void onDataArrived(TcpSocket *socket, nlohmann::json &json) override;

    void broadcast(const nlohmann::json &json);

private:
    TcpServer *_server;
    std::vector<TcpSocket *> _spectators;
};


#endif //GAME_SERVER_SPECTATORSDISPATCHER_H
