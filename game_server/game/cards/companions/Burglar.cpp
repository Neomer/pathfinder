//
// Created by kir on 03.07.19.
//

#include "Burglar.h"

int Burglar::getTypeId() const
{
    return 700;
}

std::string_view BurglarMetadata::getCardTitle() const
{
    return "Взломщик";
}

const char *BurglarMetadata::getTypeName() const
{
    return "Burglar";
}

const char *BurglarMetadata::getDescription() const
{
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> BurglarMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new Burglar());
}

int BurglarMetadata::TypeId() const
{
    return 700;
}

void BurglarMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes)
{
    attributes.push_back(CardAttribute::BeginnerLevel);
    attributes.push_back(CardAttribute::Human);
}

void BurglarMetadata::fillCardCheckConditions(CheckableCardMetadata::CardCheckConditions &conditions)
{
    conditions.emplace_back(std::vector{ Skill::Agility, Skill::Stealth }, 7);
    conditions.emplace_back(std::vector{ Skill::Charisma, Skill::Diplomacy }, 6);
}
