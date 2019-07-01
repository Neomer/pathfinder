//
// Created by kir on 01.07.19.
//

#include "Skeleton.h"

int Skeleton::getTypeId() const
{
    return 416;
}

std::string_view SkeletonMetadata::getCardTitle() const
{
    return "Скелет";
}

const char *SkeletonMetadata::getTypeName() const
{
    return "Skeleton";
}

const char *SkeletonMetadata::getDescription() const
{
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> SkeletonMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new Skeleton());
}

int SkeletonMetadata::TypeId() const
{
    return 416;
}

void SkeletonMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes)
{
    attributes.push_back(CardAttribute::BeginnerLevel);
    attributes.push_back(CardAttribute::Undead);
    attributes.push_back(CardAttribute::Skeleton);
}
