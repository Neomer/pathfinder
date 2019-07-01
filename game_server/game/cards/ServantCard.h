//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_SERVANT2CARD_H
#define GAME_SERVER_SERVANT2CARD_H


#include "Card.h"

class ServantCardMetadata : public ActiveCardMetadata
{
public:
    CardType getCardType() const override;
};


#endif //GAME_SERVER_SERVANTCARD_H
