//
// Created by vinokurov on 29.06.2019.
//

#include "WebSocketServer.h"
#include "WebSocket.h"

WebSocketServer::~WebSocketServer() {

}

TcpSocket *WebSocketServer::createSocket(int socketDescriptor) {
    return new WebSocket(socketDescriptor);
}
