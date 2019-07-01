//
// Created by kir on 01.07.19.
//

#include "LongBow.h"

int LongBow::getTypeId() const
{
    return 509;
}

std::string_view LongBowMetadata::getCardTitle() const
{
    return "Длинный лук";
}

const char *LongBowMetadata::getTypeName() const
{
    return "LongBow";
}

const char *LongBowMetadata::getDescription() const
{
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> LongBowMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new LongBow());
}

int LongBowMetadata::TypeId() const
{
    return 509;
}

void LongBowMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes)
{
    attributes.push_back(CardAttribute::Bow);
    attributes.push_back(CardAttribute::LongRange);
    attributes.push_back(CardAttribute::AdvancedLevel);
    attributes.push_back(CardAttribute::Piercing);
    attributes.push_back(CardAttribute::TwoHand);
}
