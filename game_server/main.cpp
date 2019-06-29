#include <iostream>
#include "Logger.h"
#include "game/CardMetadataProvider.h"

#include "network/Sockets.h"
#include "modules/json/single_include/nlohmann/json.hpp"
#include "network/TcpServer.h"
#include "network/IConnectionAcceptedListener.h"
#include "network/TcpSocket.h"

class A : public IConnectionAcceptedListener
{
public:
    void onConnectionAccepted(const TcpServer *server, TcpSocket *socket) override {
        _socket = socket;
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

    A a;
    try
    {
        TcpServer server;
        server.listen(10555);
        server.setConnectionAcceptedListener(&a);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    auto cmd = '0';
    while (cmd != 'q') {
        cmd = getchar();
        if (cmd == 'a') {
            nlohmann::json jDoc;
            jDoc["hello"] = "world";
            a._socket->write(jDoc);
        }
    }
    Logger::getInstace().log("Finishing game server...");

#ifdef _WIN32
    WSACleanup();
#endif
    return 0;
}