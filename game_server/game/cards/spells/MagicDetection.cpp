//
// Created by kir on 03.07.19.
//

#include "MagicDetection.h"

int MagicDetection::getTypeId() const
{
    return 7;
}

std::string_view MagicDetectionMetadata::getCardTitle() const
{
    return "Обнаружение магии";
}

const char *MagicDetectionMetadata::getTypeName() const
{
    return "MagicDetection";
}

const char *MagicDetectionMetadata::getDescription() const
{
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> MagicDetectionMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new MagicDetection());
}

int MagicDetectionMetadata::TypeId() const
{
    return 7;
}

void MagicDetectionMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes)
{
    attributes.push_back(CardAttribute::BeginnerLevel);
    attributes.push_back(CardAttribute::Magic);
    attributes.push_back(CardAttribute::Charms);
    attributes.push_back(CardAttribute::Faith);
}

void MagicDetectionMetadata::fillCardsTakenConditions(HandTakableCardMetadata::CardTakenConditions &conditions)
{
    conditions.emplace_back(std::vector{ Skill::Intelligence, Skill::Charms, Skill::Wisdom, Skill::Faith }, 2);
}
