//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_HEALCARD_H
#define GAME_SERVER_HEALCARD_H

#include "../SpellCard.h"

class HealCard : public Card
{
public:
    int getTypeId() const override;
};

class HealCardMetadata : public SpellCardMetadata
{
public:
    std::shared_ptr<Card> createInstance() const override;

    std::string_view getCardTitle() const override;

    const char *getTypeName() const override;

    int TypeId() const override;

protected:
    void fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes) override;

    void fillCardCheckConditions(CardCheckConditions &conditions) override;
};

#endif //GAME_SERVER_HEALCARD_H
