//
// Created by kir on 06.07.19.
//

#ifndef GAME_SERVER_GAMECONTEXT_H
#define GAME_SERVER_GAMECONTEXT_H

#include "cards/scenario/Scenario.h"
#include "Player.h"

class GameContext
{
public:
    Scenario *getScenario() const;

    void setScenario(Scenario *scenario);

    const ScenarioMetadata *getScenarioMetadata() const;

    uint8_t getMovesLeft() const;

    void setMovesLeft(uint8_t movesLeft);

    const std::vector<Player *> &getPlayers() const;

    void addPlayer(Player *player);

private:
    Scenario *_scenario;
    const ScenarioMetadata *_scenarioMetadata;
    uint8_t _movesLeft;
    std::vector<Player *> _players;
};


#endif //GAME_SERVER_GAMECONTEXT_H
