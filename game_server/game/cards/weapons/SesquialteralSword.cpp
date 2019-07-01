//
// Created by kir on 01.07.19.
//

#include "SesquialteralSword.h"

int SesquialteralSword::getTypeId() const
{
    return 500;
}

std::string_view SesquialteralSwordMetadata::getCardTitle() const
{
    return "Полуторный меч";
}

const char *SesquialteralSwordMetadata::getTypeName() const
{
    return "SesquialteralSword";
}

const char *SesquialteralSwordMetadata::getDescription() const
{
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> SesquialteralSwordMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new SesquialteralSword());
}

int SesquialteralSwordMetadata::TypeId() const
{
    return 500;
}

void SesquialteralSwordMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes)
{
    attributes.push_back(CardAttribute::Sword);
    attributes.push_back(CardAttribute::ShortRange);
    attributes.push_back(CardAttribute::TwoHand);
    attributes.push_back(CardAttribute::Slashing);
}
