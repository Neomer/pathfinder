//
// Created by vinokurov on 29.06.2019.
//

#include "CheckableCardMetadata.h"

bool CheckableCardMetadata::isBeginnerLevel() const {
    return hasAttribute(CardAttribute::BeginnerLevel);
}

void CheckableCardMetadata::load()
{
    ActiveCardMetadata::load();

    fillCardCheckConditions(_takenConditions);
}

const CheckableCardMetadata::CardCheckConditions &CheckableCardMetadata::getCardCheckConditions() const
{
    return _takenConditions;
}
