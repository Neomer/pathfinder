//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_CultistCard_H
#define GAME_SERVER_CultistCard_H

#include "../MonsterCard.h"

class CultistCard : public Card
{
public:
    int getTypeId() const override;
};

class CultistCardMetadata : public MonsterCardMetadata
{
public:
    std::shared_ptr<Card> createInstance() const override;

    std::string_view getCardTitle() const override;

    const char *getTypeName() const override;

    int TypeId() const override;
	
	bool isBeginnerLevel() const override;

protected:
    void fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes) override;
};

#endif //GAME_SERVER_MONSTERCARD_H
