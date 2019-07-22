//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_MONSTERCARD_H
#define GAME_SERVER_MONSTERCARD_H


#include "CheckableCardMetadata.h"

class MonsterCardMetadata : public CheckableCardMetadata
{
public:
    CardType getCardType() const override;
};


#endif //GAME_SERVER_MONSTERCARD_H
