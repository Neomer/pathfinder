//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_SPELLCARD_H
#define GAME_SERVER_SPELLCARD_H

#include "HandTakableCardMetadata.h"

class SpellCardMetadata : public HandTakableCardMetadata
{
public:
    CardType getCardType() const override;
};


#endif //GAME_SERVER_SPELLCARD_H
