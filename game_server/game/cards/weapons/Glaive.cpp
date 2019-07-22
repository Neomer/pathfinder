//
// Created by kir on 01.07.19.
//

#include "Glaive.h"

int Glaive::getTypeId() const
{
    return 505;
}

std::string_view GlaiveMetadata::getCardTitle() const
{
    return "Глефа";
}

const char *GlaiveMetadata::getTypeName() const
{
    return "Glaive";
}

const char *GlaiveMetadata::getDescription() const
{
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> GlaiveMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new Glaive());
}

int GlaiveMetadata::TypeId() const
{
    return 505;
}

void GlaiveMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes)
{
    attributes.push_back(CardAttribute::AdvancedLevel);
    attributes.push_back(CardAttribute::Pole);
    attributes.push_back(CardAttribute::ShortRange);
    attributes.push_back(CardAttribute::Slashing);
    attributes.push_back(CardAttribute::TwoHand);
}

void GlaiveMetadata::fillCardCheckConditions(CheckableCardMetadata::CardCheckConditions &conditions) {
    conditions.emplace_back(std::vector{ Skill::Strength, Skill::ShortRange }, 9);
}
