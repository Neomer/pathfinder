//
// Created by kir on 01.07.19.
//

#include "PlagueZombie.h"

int PlagueZombie::getTypeId() const
{
    return 412;
}

std::string_view PlagueZombieMetadata::getCardTitle() const
{
    return "Чумной зомби";
}

const char *PlagueZombieMetadata::getTypeName() const
{
    return "PlagueZombie";
}

const char *PlagueZombieMetadata::getDescription() const
{
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> PlagueZombieMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new PlagueZombie());
}

int PlagueZombieMetadata::TypeId() const
{
    return 412;
}

void PlagueZombieMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes)
{
    attributes.push_back(CardAttribute::AdvancedLevel);
    attributes.push_back(CardAttribute::Undead);
    attributes.push_back(CardAttribute::Zombie);
}
