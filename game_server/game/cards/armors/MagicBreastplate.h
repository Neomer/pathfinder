//
// Created by vinokurov on 03.07.2019.
//

#ifndef GAME_SERVER_MAGICBREASTPLATE_H
#define GAME_SERVER_MAGICBREASTPLATE_H

#include "../ArmorCard.h"

class MagicBreastplate : public ActiveCard {
public:
    int getTypeId() const override;
};

class MagicBreastplateMetadata : public ArmorCardMetadata
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

#endif //GAME_SERVER_MAGICBREASTPLATE_H
