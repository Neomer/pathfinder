//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_THINGCARD_H
#define GAME_SERVER_THINGCARD_H

#include "CheckableCardMetadata.h"

class ThingCardMetadata : public CheckableCardMetadata
{
public:
    CardType getCardType() const override;
};


#endif //GAME_SERVER_THINGCARD_H
