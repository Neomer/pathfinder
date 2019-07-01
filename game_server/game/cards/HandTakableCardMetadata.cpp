//
// Created by vinokurov on 29.06.2019.
//

#include "HandTakableCardMetadata.h"

bool HandTakableCardMetadata::isBeginnerLevel() const {
    return hasAttribute(CardAttribute::BeginnerLevel);
}
