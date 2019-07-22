//
// Created by kir on 01.07.19.
//

#include "Dagger.h"

int Dagger::getTypeId() const
{
    return 502;
}

std::string_view DaggerMetadata::getCardTitle() const
{
    return "Кинжал";
}

const char *DaggerMetadata::getTypeName() const
{
    return "Dagger";
}

const char *DaggerMetadata::getDescription() const
{
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> DaggerMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new Dagger());
}

int DaggerMetadata::TypeId() const
{
    return 502;
}

void DaggerMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes)
{
    attributes.push_back(CardAttribute::BeginnerLevel);
    attributes.push_back(CardAttribute::Knife);
    attributes.push_back(CardAttribute::LongRange);
    attributes.push_back(CardAttribute::Piercing);
}

void DaggerMetadata::fillCardCheckConditions(CheckableCardMetadata::CardCheckConditions &conditions) {
    conditions.emplace_back(std::vector{ Skill::Agility, Skill::LongRange }, 3);
}
