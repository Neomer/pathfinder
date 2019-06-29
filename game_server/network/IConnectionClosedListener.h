//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_ICONNECTIONCLOSEDLISTENER_H
#define GAME_SERVER_ICONNECTIONCLOSEDLISTENER_H

class TcpSocket;

class IConnectionClosedListener
{
public:
    virtual void onConnectionClosed(const TcpSocket *socket) = 0;
};

#endif //GAME_SERVER_ICONNECTIONCLOSEDLISTENER_H
