//
// Created by kir on 12.07.19.
//

#include "Farm.h"

int Farm::getTypeId() const
{
    return 1001;
}

std::string_view FarmMetadata::getCardTitle() const
{
    return "Ферма";
}

const char *FarmMetadata::getTypeName() const
{
    return "Farm";
}

const char *FarmMetadata::getDescription() const
{
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> FarmMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new Farm());
}

int FarmMetadata::TypeId() const
{
    return 1001;
}

void FarmMetadata::fillDeck(std::vector<std::pair<int, CardMetadata::CardType>> &deck)
{
    deck.emplace_back(3, CardType::Monster);
    deck.emplace_back(1, CardType::Barrier);
    deck.emplace_back(1, CardType::Weapon);
    deck.emplace_back(3, CardType::Thing);
    deck.emplace_back(1, CardType::Companion);
}
