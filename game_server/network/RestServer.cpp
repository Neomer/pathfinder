//
// Created by kir on 03.07.19.
//

#include "RestServer.h"
#include "RestSocket.h"

RestServer::~RestServer()
{

}

TcpSocket *RestServer::createSocket(int socketDescriptor)
{
    return new RestSocket(socketDescriptor);
}
