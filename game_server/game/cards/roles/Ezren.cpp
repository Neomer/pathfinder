//
// Created by kir on 02.07.19.
//

#include "Ezren.h"

int Ezren::getTypeId() const
{
    return 800;
}

std::string_view EzrenMetadata::getCardTitle() const
{
    return "Эзрен";
}

const char *EzrenMetadata::getTypeName() const
{
    return "Ezren";
}

const char *EzrenMetadata::getDescription() const
{
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> EzrenMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new Ezren());
}

int EzrenMetadata::TypeId() const
{
    return 800;
}

void EzrenMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes)
{
    attributes.push_back(CardAttribute::Man);
    attributes.push_back(CardAttribute::Human);
    attributes.push_back(CardAttribute::Wizard);
}
