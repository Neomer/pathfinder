//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_RUBIIH_H
#define GAME_SERVER_RUBIIH_H

#include "Scenario.h"

class Rubiih : public Card
{
public:
    ~Rubiih() override;

    int getTypeId() const override;
};

class RubiihMetadata : public ScenarioMetadata
{
public:
    RubiihMetadata();

    std::string_view getCardTitle() const override;

    const char *getTypeName() const override;

    const char *getDescription() const override;

    int TypeId() const override;

    const std::vector<std::pair<int, int>> &getLocationsByPlayers() const override;

private:
    std::vector<std::pair<int, int>> _locations;
};

#endif //GAME_SERVER_RUBIIH_H
