//
// Created by kir on 01.07.19.
//

#include "HeavyCrossbow.h"

int HeavyCrossbow::getTypeId() const
{
    return 507;
}

std::string_view HeavyCrossbowMetadata::getCardTitle() const
{
    return "Тяжелый арбалет";
}

const char *HeavyCrossbowMetadata::getTypeName() const
{
    return "HeavyCrossbow";
}

const char *HeavyCrossbowMetadata::getDescription() const
{
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> HeavyCrossbowMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new HeavyCrossbow());
}

int HeavyCrossbowMetadata::TypeId() const
{
    return 507;
}

void HeavyCrossbowMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes)
{
    attributes.push_back(CardAttribute::Bow);
    attributes.push_back(CardAttribute::LongRange);
    attributes.push_back(CardAttribute::TwoHand);
    attributes.push_back(CardAttribute::Piercing);
}

void HeavyCrossbowMetadata::fillCardCheckConditions(CheckableCardMetadata::CardCheckConditions &conditions) {
    conditions.emplace_back(std::vector{ Skill::Agility, Skill::LongRange }, 7);
}
