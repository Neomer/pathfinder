//
// Created by kir on 03.07.19.
//

#include "EvilDetection.h"

int EvilDetection::getTypeId() const
{
    return 6;
}

std::string_view EvilDetectionMetadata::getCardTitle() const
{
    return "Обнаружение зла";
}

const char *EvilDetectionMetadata::getTypeName() const
{
    return "EvilDetection";
}

const char *EvilDetectionMetadata::getDescription() const
{
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> EvilDetectionMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new EvilDetection());
}

int EvilDetectionMetadata::TypeId() const
{
    return 6;
}

void EvilDetectionMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes)
{
    attributes.push_back(CardAttribute::Magic);
    attributes.push_back(CardAttribute::Faith);
}

void EvilDetectionMetadata::fillCardsTakenConditions(HandTakableCardMetadata::CardTakenConditions &conditions)
{
    conditions.emplace_back(std::vector{ Skill::Wisdom, Skill::Faith }, 4);
}
