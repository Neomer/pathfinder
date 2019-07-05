//
// Created by kir on 03.07.19.
//

#include "RestSocket.h"

RestSocket::RestSocket(int socketDescriptor) :
        TcpSocket(socketDescriptor)
{

}

RestSocket::~RestSocket()
{

}

bool RestSocket::prepareRawData(char **buffer, size_t *size)
{
    auto headerIdx = strstr(*buffer, "\r\n\r\n");
    if (headerIdx == nullptr) {
        return false;
    }
    *buffer = headerIdx + 4;
    return true;
}

void RestSocket::writeRawData(std::string_view str)
{
    TcpSocket::writeRawData(str);
}


