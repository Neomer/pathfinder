#include <iostream>
#include "network/Sockets.h"
#include "Logger.h"
#include "game/CardMetadataProvider.h"
#include "game/cards/scenario/Rubiih.h"

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

    Scenario *scenario = new Rubiih();
    Game game();

    auto cmd = '0';
    while (cmd != 'q') {
        cmd = getchar();
    }
    Logger::getInstace().log("Finishing game server...");

#ifdef _WIN32
    WSACleanup();
#endif
    return 0;
}