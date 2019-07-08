#include <iostream>
#include "network/Sockets.h"
#include "Logger.h"
#include "game/CardMetadataProvider.h"
#include "game/Game.h"
#include "game/cards/scenario/Rubiih.h"
#include "game/EventProvider.h"

#include "game/Deck.h"

using namespace std::string_literals;

int main()
{
    Logger::getInstace().log("Starting game server...");
    srand(time(nullptr));

#ifdef _WIN32
    setlocale( LC_ALL, "en-US" );

    WSADATA wsaData;
    if (WSAStartup(WINSOCK_VERSION, &wsaData)) {
        throw std::runtime_error("Winsock initialization failed!");
    }
#endif
    auto start = std::chrono::steady_clock::now();
    CardMetadataProvider::getInstance().init();
    Logger::getInstace().info("Metadata initialization time: "s + std::to_string(std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start).count()) + " mcsec");

    EventProvider::getInstance().load();

    Card *scenario = new Rubiih();
    Game game(scenario, "password");

    auto cmd = '0';
    while (cmd != 'q') {
        cmd = getchar();
        if (cmd == 'a') {
        }
    }
    Logger::getInstace().info("Finishing game server...");

#ifdef _WIN32
    WSACleanup();
#endif
    return 0;
}