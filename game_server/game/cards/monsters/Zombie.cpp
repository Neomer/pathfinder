//
// Created by kir on 01.07.19.
//

#include "Zombie.h"

int Zombie::getTypeId() const
{
    return 417;
}

std::string_view ZombieMetadata::getCardTitle() const
{
    return "Зомби";
}

const char *ZombieMetadata::getTypeName() const
{
    return "Zombie";
}

const char *ZombieMetadata::getDescription() const
{
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> ZombieMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new Zombie());
}

int ZombieMetadata::TypeId() const
{
    return 417;
}

void ZombieMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes)
{
    attributes.push_back(CardAttribute::BeginnerLevel);
    attributes.push_back(CardAttribute::Undead);
    attributes.push_back(CardAttribute::Zombie);
}
