//
// Created by kir on 01.07.19.
//

#include "BattleAxe.h"

int BattleAxe::getTypeId() const
{
    return 501;
}

std::string_view BattleAxeMetadata::getCardTitle() const
{
    return "Боевой топор";
}

const char *BattleAxeMetadata::getTypeName() const
{
    return "BattleAxe";
}

const char *BattleAxeMetadata::getDescription() const
{
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> BattleAxeMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new BattleAxe());
}

int BattleAxeMetadata::TypeId() const
{
    return 501;
}

void BattleAxeMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes)
{
    attributes.push_back(CardAttribute::AdvancedLevel);
    attributes.push_back(CardAttribute::Axe);
    attributes.push_back(CardAttribute::ShortRange);
    attributes.push_back(CardAttribute::Slashing);
}

void BattleAxeMetadata::fillCardsTakenConditions(HandTakableCardMetadata::CardTakenConditions &conditions) {
    conditions.emplace_back(std::vector{ Skill::Strength, Skill::ShortRange }, 8);
}
