//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_HANDTAKABLECARDMETADATA_H
#define GAME_SERVER_HANDTAKABLECARDMETADATA_H

#include "Card.h"

class HandTakableCardMetadata : public CardMetadata
{
public:
    virtual bool isBeginnerLevel() const = 0;
};


#endif //GAME_SERVER_HANDTAKABLECARDMETADATA_H
