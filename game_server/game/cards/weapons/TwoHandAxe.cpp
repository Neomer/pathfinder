//
// Created by kir on 01.07.19.
//

#include "TwoHandAxe.h"

int TwoHandAxe::getTypeId() const
{
    return 506;
}

std::string_view TwoHandAxeMetadata::getCardTitle() const
{
    return "Двуручный топор";
}

const char *TwoHandAxeMetadata::getTypeName() const
{
    return "TwoHandAxe";
}

const char *TwoHandAxeMetadata::getDescription() const
{
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> TwoHandAxeMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new TwoHandAxe());
}

int TwoHandAxeMetadata::TypeId() const
{
    return 506;
}

void TwoHandAxeMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes)
{
    attributes.push_back(CardAttribute::Axe);
    attributes.push_back(CardAttribute::ShortRange);
    attributes.push_back(CardAttribute::TwoHand);
    attributes.push_back(CardAttribute::Slashing);
}

void TwoHandAxeMetadata::fillCardsTakenConditions(HandTakableCardMetadata::CardTakenConditions &conditions) {
    conditions.emplace_back(std::vector{ Skill::Strength, Skill::ShortRange }, 10);
}
