//
// Created by vinokurov on 29.06.2019.
//

#include <functional>
#include <string>
#include "TcpServer.h"
#include "TcpSocket.h"
#include "Sockets.h"
#include "../Logger.h"
#include "IConnectionAcceptedListener.h"

using namespace std::string_literals;

TcpServer::TcpServer() :
    _run{ false },
    _connectionAcceptedListener{ nullptr }
{

}

TcpServer::~TcpServer() {

}

void TcpServer::listen(uint16_t port) {
    Logger::getInstace().log("Server start listening on port "s + std::to_string(port));
    _socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if(bind(_socketDescriptor, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        throw std::runtime_error("Socket bind failed!");
    }
    _run = true;
    _acceptedThread = std::thread(std::bind(&TcpServer::acceptProc, this));
    _acceptedThread.detach();

}

void TcpServer::acceptProc() {
    Logger::getInstace().log("Start listening thread...");
    ::listen(_socketDescriptor, 10);
    while (_run.load()) {
        auto socket = accept(_socketDescriptor, nullptr ,0);
        if (_connectionAcceptedListener != nullptr && socket >= 0 && socket != INVALID_SOCKET) {
            Logger::getInstace().log("New connection found");
            _connectionAcceptedListener->onConnectionAccepted(this, createSocket(socket));
        }
    }
    Logger::getInstace().log("Listening thread terminated");
}

void TcpServer::close() {
    if (_run.load()) {
        _run = false;


        if (_acceptedThread.joinable()) {
            _acceptedThread.join();
        }
    }
}

TcpSocket *TcpServer::createSocket(int socketDescriptor) {
    return new TcpSocket(socketDescriptor);
}

void TcpServer::setConnectionAcceptedListener(IConnectionAcceptedListener *listener) {
    _connectionAcceptedListener = listener;
}
