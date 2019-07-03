//
// Created by kir on 03.07.19.
//

#ifndef GAME_SERVER_CHARM_H
#define GAME_SERVER_CHARM_H

#include "../SpellCard.h"

class Charm : public ActiveCard
{
public:
    int getTypeId() const override;
};

class CharmMetadata : public SpellCardMetadata
{
public:
    std::string_view getCardTitle() const override;

    const char *getTypeName() const override;

    const char *getDescription() const override;

    std::shared_ptr<Card> createInstance() const override;

    int TypeId() const override;

protected:
    void fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes) override;

    void fillCardsTakenConditions(CardTakenConditions &conditions) override;
};

#endif //GAME_SERVER_CHARM_H
