#include <iostream>
#include "network/Sockets.h"
#include "Logger.h"
#include "game/CardMetadataProvider.h"
#include "game/Game.h"
#include "game/cards/scenario/Rubiih.h"

#include "game/Deck.h"

using namespace std::string_literals;

int main()
{
    Logger::getInstace().log("Starting game server...");
    srand(time(nullptr));

#ifdef _WIN32
    WSADATA wsaData;
    if (WSAStartup(WINSOCK_VERSION, &wsaData)) {
        throw std::runtime_error("Winsock initialization failed!");
    }
#endif
    auto start = std::chrono::steady_clock::now();
    CardMetadataProvider::getInstance().init();
    Logger::getInstace().log("Metadata intialization time: "s + std::to_string(std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start).count()) + " mcsec");

    Card *scenario = new Rubiih();
    Game game(scenario, "password");
    game.run(1);



    auto cmd = '0';
    while (cmd != 'q') {
        cmd = getchar();
        if (cmd == 'a') {
        }
    }
    Logger::getInstace().log("Finishing game server...");

#ifdef _WIN32
    WSACleanup();
#endif
    return 0;
}