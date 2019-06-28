#include <iostream>
#include "Logger.h"

int main()
{
    Logger::getInstace().log("Starting game server...");

    auto cmd = '0';
    while (cmd != 'q') {
        cmd = getchar();
    }
    Logger::getInstace().log("Finishing game server...");

    return 0;
}