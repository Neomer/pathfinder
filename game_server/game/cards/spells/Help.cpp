//
// Created by kir on 03.07.19.
//

#include "Help.h"

int Help::getTypeId() const
{
    return 2;
}

std::string_view HelpMetadata::getCardTitle() const
{
    return "Помощь";
}

const char *HelpMetadata::getTypeName() const
{
    return "Help";
}

const char *HelpMetadata::getDescription() const
{
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> HelpMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new Help());
}

int HelpMetadata::TypeId() const
{
    return 2;
}

void HelpMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes)
{
    attributes.push_back(CardAttribute::AdvancedLevel);
    attributes.push_back(CardAttribute::Magic);
    attributes.push_back(CardAttribute::Faith);
}

void HelpMetadata::fillCardCheckConditions(CheckableCardMetadata::CardCheckConditions &conditions)
{
    conditions.emplace_back(std::vector{ Skill::Wisdom, Skill::Faith }, 6);
}
