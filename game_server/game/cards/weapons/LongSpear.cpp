//
// Created by kir on 01.07.19.
//

#include "LongSpear.h"

int LongSpear::getTypeId() const
{
    return 510;
}

std::string_view LongSpearMetadata::getCardTitle() const
{
    return "Длинное копьё";
}

const char *LongSpearMetadata::getTypeName() const
{
    return "LongSpear";
}

const char *LongSpearMetadata::getDescription() const
{
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> LongSpearMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new LongSpear());
}

int LongSpearMetadata::TypeId() const
{
    return 510;
}

void LongSpearMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes)
{
    attributes.push_back(CardAttribute::Spear);
    attributes.push_back(CardAttribute::ShortRange);
    attributes.push_back(CardAttribute::BeginnerLevel);
    attributes.push_back(CardAttribute::Piercing);
    attributes.push_back(CardAttribute::TwoHand);
}

void LongSpearMetadata::fillCardCheckConditions(CheckableCardMetadata::CardCheckConditions &conditions) {
    conditions.emplace_back(std::vector{ Skill::Strength, Skill::ShortRange }, 5);
}
