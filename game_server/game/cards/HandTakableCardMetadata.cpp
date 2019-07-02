//
// Created by vinokurov on 29.06.2019.
//

#include "HandTakableCardMetadata.h"

bool HandTakableCardMetadata::isBeginnerLevel() const {
    return hasAttribute(CardAttribute::BeginnerLevel);
}

void HandTakableCardMetadata::load()
{
    ActiveCardMetadata::load();

    fillCardsTakenConditions(_takenConditions);
}

const HandTakableCardMetadata::CardTakenConditions &HandTakableCardMetadata::getTakenConditions() const
{
    return _takenConditions;
}
