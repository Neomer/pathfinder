//
// Created by kir on 01.07.19.
//

#include "Scout.h"

int Scout::getTypeId() const
{
    return 413;
}

std::string_view ScoutMetadata::getCardTitle() const
{
    return "Разведчик";
}

const char *ScoutMetadata::getTypeName() const
{
    return "Scout";
}

const char *ScoutMetadata::getDescription() const
{
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> ScoutMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new Scout());
}

int ScoutMetadata::TypeId() const
{
    return 413;
}

void ScoutMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes)
{
    attributes.push_back(CardAttribute::Human);
    attributes.push_back(CardAttribute::Shooter);
    attributes.push_back(CardAttribute::Veteran);
}

void ScoutMetadata::fillCardCheckConditions(CheckableCardMetadata::CardCheckConditions &conditions)
{
    conditions.emplace_back(std::vector{ Skill::Fight }, 8);
}
