//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_SCENARIO_H
#define GAME_SERVER_SCENARIO_H

#include "../Card.h"

class Scenario : public Card
{
public:
    virtual void toJson(nlohmann::json &json) const;
};

class ScenarioMetadata : public CardMetadata {
public:
    CardType getCardType() const final;

    virtual const std::vector<std::pair<int, int>> &getLocationsByPlayers() const = 0;

    void toJson(nlohmann::json &json) const override;

    void load() override;

};


#endif //GAME_SERVER_SCENARIO_H
