//
// Created by kir on 02.07.19.
//

#include "Harsk.h"

int Harsk::getTypeId() const
{
    return 801;
}

std::string_view HarskMetadata::getCardTitle() const
{
    return "Харск";
}

const char *HarskMetadata::getTypeName() const
{
    return "Harsk";
}

const char *HarskMetadata::getDescription() const
{
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> HarskMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new Harsk());
}

int HarskMetadata::TypeId() const
{
    return 801;
}

void HarskMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes)
{
    attributes.push_back(CardAttribute::Man);
    attributes.push_back(CardAttribute::Dwarf);
    attributes.push_back(CardAttribute::Tracker);
}
