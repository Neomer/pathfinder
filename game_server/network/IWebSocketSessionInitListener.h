//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_IWEBSOCKETSESSIONINITLISTENER_H
#define GAME_SERVER_IWEBSOCKETSESSIONINITLISTENER_H

class WebSocket;

class IWebSocketSessionInitListener
{
public:

    virtual void onSessionInit(WebSocket *socket) = 0;
};

#endif //GAME_SERVER_IWEBSOCKETSESSIONINITLISTENER_H
