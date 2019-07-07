//
// Created by kir on 06.07.19.
//

#include "GameContext.h"

GameContext::GameContext() :
        _currentPlayerIdx{ 0 },
        _movesLeft{ 50 }
{

}

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

const Player *GameContext::getCurrentPlayer() const
{
    return _players.at(_currentPlayerIdx);
}

void GameContext::nextTurn()
{
    _currentPlayerIdx = _currentPlayerIdx < _players.size() - 1 ? _currentPlayerIdx + 1 : 0;
    --_movesLeft;
}
