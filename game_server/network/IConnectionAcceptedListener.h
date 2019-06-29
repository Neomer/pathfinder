//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_ICONNECTIONACCEPTEDLISTENER_H
#define GAME_SERVER_ICONNECTIONACCEPTEDLISTENER_H

class TcpSocket;

class TcpServer;

class IConnectionAcceptedListener
{
public:
    void onConnectionAccepted(const TcpServer *server, TcpSocket *socket);
};

#endif //GAME_SERVER_ICONNECTIONACCEPTEDLISTENER_H
