//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_SCENARIO_H
#define GAME_SERVER_SCENARIO_H

#include "../Card.h"

class Scenario : public Card
{
public:
    virtual void loadLocations(uint8_t playersCount);

    const std::vector<std::shared_ptr<Card>> &getLocations() const;

    void toJson(nlohmann::json &json) const override;

private:
    std::vector<std::shared_ptr<Card>> _locations;
};

class ScenarioMetadata : public CardMetadata {
public:
    CardType getCardType() const final;

    virtual const std::vector<std::pair<int, int>> &getLocationsByPlayers() const = 0;

    virtual int getBossId() const = 0;

    void toJson(nlohmann::json &json) const override;

    void load() override;

};


#endif //GAME_SERVER_SCENARIO_H
