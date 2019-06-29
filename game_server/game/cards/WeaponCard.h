//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_WEAPONCARD_H
#define GAME_SERVER_WEAPONCARD_H

#include "HandTakableCardMetadata.h"

class WeaponCardMetadata : public HandTakableCardMetadata
{
public:
    CardType getCardType() const final;
};


#endif //GAME_SERVER_WEAPONCARD_H
