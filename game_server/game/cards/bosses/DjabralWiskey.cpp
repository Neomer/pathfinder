//
// Created by kir on 01.07.19.
//

#include "DjabralWiskey.h"

int DjabralWiskey::getTypeId() const
{
    return 600;
}

std::string_view DjabralWiskeyMetadata::getCardTitle() const
{
    return "Джабрайл Виски";
}

const char *DjabralWiskeyMetadata::getTypeName() const
{
    return "DjabralWiskey";
}

const char *DjabralWiskeyMetadata::getDescription() const
{
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> DjabralWiskeyMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new DjabralWiskey());
}

int DjabralWiskeyMetadata::TypeId() const
{
    return 600;
}

void DjabralWiskeyMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes)
{
    attributes.push_back(CardAttribute::Human);
    attributes.push_back(CardAttribute::Cheat);
}
