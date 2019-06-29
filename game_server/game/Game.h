//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_GAME_H
#define GAME_SERVER_GAME_H

#include "cards/scenario/Scenario.h"

class Game {
public:
    explicit Game(ScenarioMetadata *scenario);

    void run();

private:
    ScenarioMetadata _scenario;
};


#endif //GAME_SERVER_GAME_H
