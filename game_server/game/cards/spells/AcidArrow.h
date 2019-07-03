//
// Created by kir on 03.07.19.
//

#ifndef GAME_SERVER_ACIDARROW_H
#define GAME_SERVER_ACIDARROW_H

#include "../SpellCard.h"

class AcidArrow : public ActiveCard
{
public:
    int getTypeId() const override;
};

class AcidArrowMetadata : public SpellCardMetadata
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

#endif //GAME_SERVER_ACIDARROW_H
