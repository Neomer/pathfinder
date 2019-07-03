//
// Created by kir on 03.07.19.
//

#ifndef GAME_SERVER_MAGICDETECTION_H
#define GAME_SERVER_MAGICDETECTION_H

#include "../SpellCard.h"

class MagicDetection : public ActiveCard
{
public:
    int getTypeId() const override;
};

class MagicDetectionMetadata : public SpellCardMetadata
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

#endif //GAME_SERVER_MAGICDETECTION_H
