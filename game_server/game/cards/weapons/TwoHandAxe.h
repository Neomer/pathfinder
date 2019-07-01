//
// Created by kir on 01.07.19.
//

#ifndef GAME_SERVER_TWOHANDAXE_H
#define GAME_SERVER_TWOHANDAXE_H

#include "../WeaponCard.h"

class TwoHandAxe : public ActiveCard
{
public:
    int getTypeId() const override;
};

class TwoHandAxeMetadata : public WeaponCardMetadata {
public:
    std::string_view getCardTitle() const override;

    const char *getTypeName() const override;

    const char *getDescription() const override;

    std::shared_ptr<Card> createInstance() const override;

    int TypeId() const override;

protected:
    void fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes) override;
};

#endif //GAME_SERVER_TWOHANDAXE_H
