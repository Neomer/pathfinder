//
// Created by vinokurov on 01.07.2019.
//

#ifndef GAME_SERVER_MERCENARY_H
#define GAME_SERVER_MERCENARY_H

#include "../MonsterCard.h"

class Mercenary : public ActiveCard {
public:
    int getTypeId() const override;
};

class MercenaryMetadata : public MonsterCardMetadata {
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

#endif //GAME_SERVER_MERCENARY_H
