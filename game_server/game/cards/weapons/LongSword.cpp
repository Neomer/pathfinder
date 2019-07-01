//
// Created by kir on 01.07.19.
//

#include "LongSword.h"

int LongSword::getTypeId() const
{
    return 511;
}

std::string_view LongSwordMetadata::getCardTitle() const
{
    return "Длинный меч";
}

const char *LongSwordMetadata::getTypeName() const
{
    return "LongSword";
}

const char *LongSwordMetadata::getDescription() const
{
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> LongSwordMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new LongSword());
}

int LongSwordMetadata::TypeId() const
{
    return 511;
}

void LongSwordMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes)
{
    attributes.push_back(CardAttribute::Sword);
    attributes.push_back(CardAttribute::ShortRange);
    attributes.push_back(CardAttribute::BeginnerLevel);
    attributes.push_back(CardAttribute::Slashing);
}
