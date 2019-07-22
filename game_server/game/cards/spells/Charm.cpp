//
// Created by kir on 03.07.19.
//

#include "Charm.h"

int Charm::getTypeId() const
{
    return 5;
}

std::string_view CharmMetadata::getCardTitle() const
{
    return "Очарование";
}

const char *CharmMetadata::getTypeName() const
{
    return "Charm";
}

const char *CharmMetadata::getDescription() const
{
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> CharmMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new Charm());
}

int CharmMetadata::TypeId() const
{
    return 5;
}

void CharmMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes)
{
    attributes.push_back(CardAttribute::Magic);
    attributes.push_back(CardAttribute::Charms);
    attributes.push_back(CardAttribute::Psycho);
}

void CharmMetadata::fillCardCheckConditions(CheckableCardMetadata::CardCheckConditions &conditions)
{
    conditions.emplace_back(std::vector{ Skill::Intelligence, Skill::Charms }, 4);
}
