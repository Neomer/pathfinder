//
// Created by kir on 01.07.19.
//

#include "LightCrossbow.h"

int LightCrossbow::getTypeId() const
{
    return 508;
}

std::string_view LightCrossbowMetadata::getCardTitle() const
{
    return "Лёгкий арбалет";
}

const char *LightCrossbowMetadata::getTypeName() const
{
    return "LightCrossbow";
}

const char *LightCrossbowMetadata::getDescription() const
{
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> LightCrossbowMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new LightCrossbow());
}

int LightCrossbowMetadata::TypeId() const
{
    return 508;
}

void LightCrossbowMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes)
{
    attributes.push_back(CardAttribute::Bow);
    attributes.push_back(CardAttribute::LongRange);
    attributes.push_back(CardAttribute::BeginnerLevel);
    attributes.push_back(CardAttribute::Piercing);
}
