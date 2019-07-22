//
// Created by kir on 03.07.19.
//

#ifndef GAME_SERVER_COMPANIONCARD_H
#define GAME_SERVER_COMPANIONCARD_H

#include "CheckableCardMetadata.h"

class CompanionCardMetadata : public CheckableCardMetadata
{
public:
    CardType getCardType() const override;
};


#endif //GAME_SERVER_COMPANIONCARD_H
