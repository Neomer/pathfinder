//
// Created by kir on 01.07.19.
//

#include "Mace.h"

int Mace::getTypeId() const
{
    return 512;
}

std::string_view MaceMetadata::getCardTitle() const
{
    return "Булава";
}

const char *MaceMetadata::getTypeName() const
{
    return "Mace";
}

const char *MaceMetadata::getDescription() const
{
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> MaceMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new Mace());
}

int MaceMetadata::TypeId() const
{
    return 512;
}

void MaceMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes)
{
    attributes.push_back(CardAttribute::BeginnerLevel);
    attributes.push_back(CardAttribute::Mace);
    attributes.push_back(CardAttribute::ShortRange);
    attributes.push_back(CardAttribute::Crushing);
}

void MaceMetadata::fillCardCheckConditions(CheckableCardMetadata::CardCheckConditions &conditions) {
    conditions.emplace_back(std::vector{ Skill::Strength, Skill::ShortRange }, 4);
}
