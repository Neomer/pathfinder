//
// Created by kir on 03.07.19.
//

#ifndef GAME_SERVER_RESTSOCKET_H
#define GAME_SERVER_RESTSOCKET_H

#include "TcpSocket.h"

class RestSocket : public TcpSocket
{
public:
    RestSocket(int socketDescriptor);

    ~RestSocket() override;

protected:
    bool prepareRawData(char **buffer, size_t *size) override;

    void writeRawData(std::string_view str) override;
};


#endif //GAME_SERVER_RESTSOCKET_H
