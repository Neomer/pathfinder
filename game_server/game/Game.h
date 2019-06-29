//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_GAME_H
#define GAME_SERVER_GAME_H

#include "cards/scenario/Scenario.h"

class Game {
public:
    explicit Game(Card *scenario);

    void run(int numPlayers);

private:
    Card *_scenario;
    const ScenarioMetadata *_scenarioMetadata;
    std::vector<std::shared_ptr<Card>> _locations;
};


#endif //GAME_SERVER_GAME_H
