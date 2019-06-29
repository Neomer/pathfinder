//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_AMULETOFLIFE_H
#define GAME_SERVER_AMULETOFLIFE_H

#include "../ThingCard.h"

class AmuletOfLife : public ActiveCard
{
public:
    ~AmuletOfLife() override;

    int getTypeId() const override;
};

class AmuletOfLifeMetadata : public ThingCardMetadata
{
public:
    std::string_view getCardTitle() const override;

    const char *getTypeName() const override;

    const char *getDescription() const override;

    std::shared_ptr<Card> createInstance() const override;

    bool isBeginnerLevel() const override;

    int TypeId() const override;

protected:
    void fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes) override;
};


#endif //GAME_SERVER_AMULETOFLIFE_H
