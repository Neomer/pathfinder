//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_BLESSINGCARD_H
#define GAME_SERVER_BLESSINGCARD_H

#include "CheckableCardMetadata.h"

class BlessingCardMetadata : public CheckableCardMetadata
{
public:
    CardType getCardType() const override;
};


#endif //GAME_SERVER_BLESSINGCARD_H
