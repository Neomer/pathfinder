//
// Created by kir on 01.07.19.
//

#ifndef GAME_SERVER_HEAVYCROSSBOW_H
#define GAME_SERVER_HEAVYCROSSBOW_H

#include "../WeaponCard.h"

class HeavyCrossbow : public ActiveCard
{
public:
    int getTypeId() const override;
};

class HeavyCrossbowMetadata : public WeaponCardMetadata {
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

#endif //GAME_SERVER_HEAVYCROSSBOW_H
