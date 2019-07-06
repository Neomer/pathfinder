//
// Created by kir on 06.07.19.
//

#include "GameContext.h"

Scenario *GameContext::getScenario() const
{
    return _scenario;
}

void GameContext::setScenario(Scenario *scenario)
{
    _scenario = scenario;
    _scenarioMetadata = dynamic_cast<const ScenarioMetadata *>(scenario->getMetadata());
}

const ScenarioMetadata *GameContext::getScenarioMetadata() const
{
    return _scenarioMetadata;
}

uint8_t GameContext::getMovesLeft() const
{
    return _movesLeft;
}

void GameContext::setMovesLeft(uint8_t movesLeft)
{
    _movesLeft = movesLeft;
}

const std::vector<Player *> &GameContext::getPlayers() const
{
    return _players;
}

void GameContext::addPlayer(Player *player)
{
    _players.push_back(player);
}