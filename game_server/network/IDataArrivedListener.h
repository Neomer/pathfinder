//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_IDATAARRIVEDLISTENER_H
#define GAME_SERVER_IDATAARRIVEDLISTENER_H

#include "../modules/json/single_include/nlohmann/json.hpp"

class TcpSocket;

class IDataArrivedListener
{
public:
    virtual void onDataArrived(const TcpSocket *socket, nlohmann::json &json) = 0;
};


#endif //GAME_SERVER_IDATAARRIVEDLISTENER_H
