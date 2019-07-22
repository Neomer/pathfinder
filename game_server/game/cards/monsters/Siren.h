//
// Created by kir on 01.07.19.
//

#ifndef GAME_SERVER_SIREN_H
#define GAME_SERVER_SIREN_H

#include "../MonsterCard.h"

class Siren : public ActiveCard
{
public:
    int getTypeId() const override;
};

class SirenMetadata : public MonsterCardMetadata {
public:
    std::string_view getCardTitle() const override;

    const char *getTypeName() const override;

    const char *getDescription() const override;

    std::shared_ptr<Card> createInstance() const override;

    int TypeId() const override;

protected:
    void fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes) override;

    void fillCardCheckConditions(CardCheckConditions &conditions) override;
};

#endif //GAME_SERVER_SIREN_H
