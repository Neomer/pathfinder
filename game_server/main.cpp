#include <iostream>
#include "Logger.h"
#include "network/Sockets.h"

int main()
{
    Logger::getInstace().log("Starting game server...");
#ifdef _WIN32
    WSADATA wsaData;
    if (WSAStartup(WINSOCK_VERSION, &wsaData)) {
        throw std::runtime_error("Winsock initialization failed!");
    }
#endif
    try
    {

    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

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