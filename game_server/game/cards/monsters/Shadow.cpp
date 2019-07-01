//
// Created by kir on 01.07.19.
//

#include "Shadow.h"

int Shadow::getTypeId() const
{
    return 414;
}

std::string_view ShadowMetadata::getCardTitle() const
{
    return "Тень";
}

const char *ShadowMetadata::getTypeName() const
{
    return "Shadow";
}

const char *ShadowMetadata::getDescription() const
{
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> ShadowMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new Shadow());
}

int ShadowMetadata::TypeId() const
{
    return 414;
}

void ShadowMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes)
{
    attributes.push_back(CardAttribute::Undead);
    attributes.push_back(CardAttribute::Disembodied);
}
