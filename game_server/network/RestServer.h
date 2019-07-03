//
// Created by kir on 03.07.19.
//

#ifndef GAME_SERVER_RESTSERVER_H
#define GAME_SERVER_RESTSERVER_H

#include "TcpServer.h"

class RestServer : public TcpServer
{
public:
    ~RestServer() override;

protected:
    TcpSocket *createSocket(int socketDescriptor) override;
};


#endif //GAME_SERVER_RESTSERVER_H
