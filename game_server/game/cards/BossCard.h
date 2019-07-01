//
// Created by kir on 01.07.19.
//

#ifndef GAME_SERVER_BOSSCARD_H
#define GAME_SERVER_BOSSCARD_H

#include "Card.h"

class BossCardMetadata : public ActiveCardMetadata
{
public:
    CardType getCardType() const override;
};


#endif //GAME_SERVER_BOSSCARD_H
