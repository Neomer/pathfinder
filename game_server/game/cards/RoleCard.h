//
// Created by kir on 02.07.19.
//

#ifndef GAME_SERVER_ROLECARD_H
#define GAME_SERVER_ROLECARD_H

#include "Card.h"

class RoleCard : public Card
{

};

class RoleCardMetadata : public ActiveCardMetadata
{
public:
    CardType getCardType() const override;
};


#endif //GAME_SERVER_ROLECARD_H
