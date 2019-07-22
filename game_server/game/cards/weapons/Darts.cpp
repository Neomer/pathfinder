//
// Created by kir on 01.07.19.
//

#include "Darts.h"

int Darts::getTypeId() const
{
    return 503;
}

std::string_view DartsMetadata::getCardTitle() const
{
    return "Дротики";
}

const char *DartsMetadata::getTypeName() const
{
    return "Darts";
}

const char *DartsMetadata::getDescription() const
{
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> DartsMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new Darts());
}

int DartsMetadata::TypeId() const
{
    return 503;
}

void DartsMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes)
{
    attributes.push_back(CardAttribute::BeginnerLevel);
    attributes.push_back(CardAttribute::Dart);
    attributes.push_back(CardAttribute::LongRange);
    attributes.push_back(CardAttribute::Piercing);
}

void DartsMetadata::fillCardCheckConditions(CheckableCardMetadata::CardCheckConditions &conditions) {
    conditions.emplace_back(std::vector{ Skill::Agility, Skill::LongRange }, 4);
}
