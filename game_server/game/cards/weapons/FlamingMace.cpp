//
// Created by kir on 01.07.19.
//

#include "FlamingMace.h"

int FlamingMace::getTypeId() const
{
    return 504;
}

std::string_view FlamingMaceMetadata::getCardTitle() const
{
    return "Пламенная булава";
}

const char *FlamingMaceMetadata::getTypeName() const
{
    return "FlamingMace";
}

const char *FlamingMaceMetadata::getDescription() const
{
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> FlamingMaceMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new FlamingMace());
}

int FlamingMaceMetadata::TypeId() const
{
    return 504;
}

void FlamingMaceMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes)
{
    attributes.push_back(CardAttribute::Mace);
    attributes.push_back(CardAttribute::ShortRange);
    attributes.push_back(CardAttribute::Crushing);
    attributes.push_back(CardAttribute::Magic);
}

void FlamingMaceMetadata::fillCardCheckConditions(CheckableCardMetadata::CardCheckConditions &conditions) {
    conditions.emplace_back(std::vector{ Skill::Strength, Skill::ShortRange }, 11);
}
