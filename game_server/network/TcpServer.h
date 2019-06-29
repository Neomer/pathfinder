//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_TCPSERVER_H
#define GAME_SERVER_TCPSERVER_H

#include <inttypes.h>
#include <thread>
#include <atomic>

class IConnectionAcceptedListener;

class TcpSocket;

class TcpServer
{
public:
    TcpServer();

    virtual ~TcpServer();

    void listen(uint16_t port);

    void close();

    void setConnectionAcceptedListener(IConnectionAcceptedListener *listener);

protected:
    virtual TcpSocket *createSocket(int socketDescriptor);

private:
    void acceptProc();

    std::thread _acceptedThread;
    std::atomic_bool _run;
    int _socketDescriptor;

    IConnectionAcceptedListener *_connectionAcceptedListener;
};


#endif //GAME_SERVER_TCPSERVER_H
