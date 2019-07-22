//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_ARMORCARD_H
#define GAME_SERVER_ARMORCARD_H

#include "CheckableCardMetadata.h"

class ArmorCardMetadata : public CheckableCardMetadata
{
public:
    CardType getCardType() const override;
};


#endif //GAME_SERVER_ARMORCARD_H
