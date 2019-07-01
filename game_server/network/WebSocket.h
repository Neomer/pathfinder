//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_WEBSOCKET_H
#define GAME_SERVER_WEBSOCKET_H

#include "TcpSocket.h"
#include "IWebSocketSessionInitListener.h"

class WebSocket : public TcpSocket
{
public:
    WebSocket(int socketDescriptor);

    enum class ChannelState
    {
        Open,
        Ready
    };

    ~WebSocket() override;

    void setOnWebSocketSessionInitListener(IWebSocketSessionInitListener *listener);


protected:
    bool prepareRawData(char **buffer, size_t *size) override;

    void writeRawData(std::string_view str) override;

    void writeRawData(const char *data, size_t size) override;

private:
    ChannelState _state;

    IWebSocketSessionInitListener *_webSocketSessionInitListener;
};


#endif //GAME_SERVER_WEBSOCKET_H
