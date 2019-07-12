//
// Created by vinokurov on 29.06.2019.
//

#include "ForestLocationCard.h"
#include "../../CardMetadataProvider.h"

std::string_view ForestLocationCardMetadata::getCardTitle() const {
    return "Лес";
}

const char *ForestLocationCardMetadata::getTypeName() const {
    return "Forest";
}

const char *ForestLocationCardMetadata::getDescription() const {
    return CardMetadata::getDescription();
}

int ForestLocationCardMetadata::TypeId() const {
    return 1000;
}

std::shared_ptr<Card> ForestLocationCardMetadata::createInstance() const {
    return std::shared_ptr<Card>(new ForestLocationCard());
}

void ForestLocationCardMetadata::fillDeck(std::vector<std::pair<int, CardMetadata::CardType>> &deck)
{
    deck.emplace_back(4, CardType::Monster);
    deck.emplace_back(2, CardType::Barrier);
    deck.emplace_back(1, CardType::Weapon);
    deck.emplace_back(2, CardType::Thing);
}

int ForestLocationCard::getTypeId() const {
    return 1000;
}
