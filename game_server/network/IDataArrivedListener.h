//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_IDATAARRIVEDLISTENER_H
#define GAME_SERVER_IDATAARRIVEDLISTENER_H

class TcpSocket;

class IDataArrivedListener
{
public:
    void onDataArrived(const TcpSocket *socket);
};


#endif //GAME_SERVER_IDATAARRIVEDLISTENER_H
