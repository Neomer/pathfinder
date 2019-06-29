#include <iostream>
#include "Logger.h"
#include "game/CardMetadataProvider.h"

#include "network/Sockets.h"
#include "modules/json/single_include/nlohmann/json.hpp"
#include "network/TcpServer.h"
#include "network/IConnectionAcceptedListener.h"
#include "network/IDataArrivedListener.h"
#include "network/IConnectionClosedListener.h"
#include "network/TcpSocket.h"
#include "network/WebSocketServer.h"
#include "game/cards/Card.h"

class A : public IConnectionAcceptedListener,
        public IDataArrivedListener,
        public IConnectionClosedListener
{
public:
    void onConnectionAccepted(const TcpServer *server, TcpSocket *socket) override {
        _socket = socket;
        socket->setConnectionClosedListener(this);
        socket->setDataArrivedListener(this);
    }

    void onConnectionClosed(const TcpSocket *socket) override {

    }

    void onDataArrived(const TcpSocket *socket, nlohmann::json &json) override {

    }

    TcpSocket *_socket;
};

int main()
{
    Logger::getInstace().log("Starting game server...");
#ifdef _WIN32
    WSADATA wsaData;
    if (WSAStartup(WINSOCK_VERSION, &wsaData)) {
        throw std::runtime_error("Winsock initialization failed!");
    }
#endif
    CardMetadataProvider::getInstance().init();

    auto metadata = CardMetadataProvider::getInstance().getMetadata(0);
    nlohmann::json j;
    metadata->toJson(j);

    A a;
    try
    {
        TcpServer* server = new WebSocketServer();
        server->listen(11555);
        server->setConnectionAcceptedListener(&a);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    auto cmd = '0';
    while (cmd != 'q') {
        cmd = getchar();
        if (cmd == 'a') {
            a._socket->write(j);
        }
    }
    Logger::getInstace().log("Finishing game server...");

#ifdef _WIN32
    WSACleanup();
#endif
    return 0;
}