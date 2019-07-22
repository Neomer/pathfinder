//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_MAGICSHIELD_H
#define GAME_SERVER_MAGICSHIELD_H

#include "../ArmorCard.h"

class MagicShield : public ActiveCard
{
public:
    ~MagicShield() override;

    int getTypeId() const override;
};

class MagicShieldMetadata : public ArmorCardMetadata
{
public:
    std::string_view getCardTitle() const override;

    const char *getTypeName() const override;

    const char *getDescription() const override;

    bool isBeginnerLevel() const override;

    int TypeId() const override;

    std::shared_ptr<Card> createInstance() const override;

protected:
    void fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes) override;

    void fillCardCheckConditions(CardCheckConditions &conditions) override;
};


#endif //GAME_SERVER_MAGICSHIELD_H
