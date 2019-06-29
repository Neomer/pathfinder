//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_WEBSOCKETSERVER_H
#define GAME_SERVER_WEBSOCKETSERVER_H

#include "TcpServer.h"

class WebSocketServer : public TcpServer
{
public:
    ~WebSocketServer() override;

protected:
    TcpSocket *createSocket(int socketDescriptor) override;
};


#endif //GAME_SERVER_WEBSOCKETSERVER_H
