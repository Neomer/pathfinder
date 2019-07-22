//
// Created by kir on 03.07.19.
//

#include "Divination.h"

int Divination::getTypeId() const
{
    return 4;
}

std::string_view DivinationMetadata::getCardTitle() const
{
    return "Гадание";
}

const char *DivinationMetadata::getTypeName() const
{
    return "Divination";
}

const char *DivinationMetadata::getDescription() const
{
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> DivinationMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new Divination());
}

int DivinationMetadata::TypeId() const
{
    return 4;
}

void DivinationMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes)
{
    attributes.push_back(CardAttribute::Magic);
    attributes.push_back(CardAttribute::Charms);
    attributes.push_back(CardAttribute::Faith);
}

void DivinationMetadata::fillCardCheckConditions(CheckableCardMetadata::CardCheckConditions &conditions)
{
    conditions.emplace_back(std::vector{ Skill::Intelligence, Skill::Charms, Skill::Wisdom, Skill::Faith }, 6);
}
