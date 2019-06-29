//
// Created by vinokurov on 29.06.2019.
//

#include <functional>
#include "TcpSocket.h"
#include "Sockets.h"
#include "../Logger.h"

TcpSocket::TcpSocket(int socketDescriptor) :
    _socketDescriptor{ socketDescriptor },
    _run{ true },
    _readThread{ std::bind(&TcpSocket::readDataProc, this) },
    _writeThread{ std::bind(&TcpSocket::writeDataProc, this) }
{

}

void TcpSocket::close() {
    if (_run.load()) {
        _run = false;
        shutdown(_socketDescriptor, 0);
        closesocket(_socketDescriptor);
    }
}

void TcpSocket::readDataProc() {
    Logger::getInstace().log("Start read thread...");
    while (_run.load()) {

    }
    Logger::getInstace().log("Read thread terminated");
}

void TcpSocket::writeDataProc() {
    Logger::getInstace().log("Start write thread...");
    while (_run.load()) {

    }
    Logger::getInstace().log("Write thread terminated");
}

TcpSocket::~TcpSocket() {
    close();
}
