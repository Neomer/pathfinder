//
// Created by kir on 01.07.19.
//

#include "BattleStaff.h"

int BattleStaff::getTypeId() const
{
    return 513;
}

std::string_view BattleStaffMetadata::getCardTitle() const
{
    return "Боевой посох";
}

const char *BattleStaffMetadata::getTypeName() const
{
    return "BattleStaff";
}

const char *BattleStaffMetadata::getDescription() const
{
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> BattleStaffMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new BattleStaff());
}

int BattleStaffMetadata::TypeId() const
{
    return 513;
}

void BattleStaffMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes)
{
    attributes.push_back(CardAttribute::BeginnerLevel);
    attributes.push_back(CardAttribute::Staff);
    attributes.push_back(CardAttribute::ShortRange);
    attributes.push_back(CardAttribute::Crushing);
    attributes.push_back(CardAttribute::TwoHand);
}
