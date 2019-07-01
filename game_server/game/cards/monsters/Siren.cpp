//
// Created by kir on 01.07.19.
//

#include "Siren.h"

int Siren::getTypeId() const
{
    return 415;
}

std::string_view SirenMetadata::getCardTitle() const
{
    return "Сирена";
}

const char *SirenMetadata::getTypeName() const
{
    return "Siren";
}

const char *SirenMetadata::getDescription() const
{
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> SirenMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new Siren());
}

int SirenMetadata::TypeId() const
{
    return 415;
}

void SirenMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes)
{
    attributes.push_back(CardAttribute::AdvancedLevel);
    attributes.push_back(CardAttribute::Siren);
}
