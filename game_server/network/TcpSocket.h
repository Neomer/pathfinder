//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_TCPSOCKET_H
#define GAME_SERVER_TCPSOCKET_H

#include <inttypes.h>
#include <thread>
#include <atomic>

class TcpSocket
{
public:
    explicit TcpSocket(int socketDescriptor);

    virtual ~TcpSocket();

    void close();

private:
    void readDataProc();
    void writeDataProc();

    int _socketDescriptor;

    std::thread _readThread, _writeThread;
    std::atomic_bool _run;
};


#endif //GAME_SERVER_TCPSOCKET_H
