//
// Created by kir on 12.07.19.
//

#include "Quay.h"

int Quay::getTypeId() const
{
    return 1002;
}

std::string_view QuayMetadata::getCardTitle() const
{
    return "Набережная";
}

const char *QuayMetadata::getTypeName() const
{
    return "Quay";
}

const char *QuayMetadata::getDescription() const
{
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> QuayMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new Quay());
}

int QuayMetadata::TypeId() const
{
    return 1002;
}

void QuayMetadata::fillDeck(std::vector<std::pair<int, CardMetadata::CardType>> &deck)
{
    deck.emplace_back(4, CardType::Monster);
    deck.emplace_back(2, CardType::Barrier);
    deck.emplace_back(1, CardType::Thing);
    deck.emplace_back(2, CardType::Companion);
}
