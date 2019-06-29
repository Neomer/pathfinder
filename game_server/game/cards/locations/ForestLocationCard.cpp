//
// Created by vinokurov on 29.06.2019.
//

#include "ForestLocationCard.h"

std::string_view ForestLocationCardMetadata::getCardTitle() const {
    return std::string_view();
}

const char *ForestLocationCardMetadata::getTypeName() const {
    return nullptr;
}

const char *ForestLocationCardMetadata::getDescription() const {
    return CardMetadata::getDescription();
}

int ForestLocationCardMetadata::TypeId() const {
    return 1000;
}

const std::vector<std::pair<int, CardMetadata::CardType>> &ForestLocationCardMetadata::getLocationDeck() const {
    return _deck;
}

ForestLocationCardMetadata::ForestLocationCardMetadata() {
    _deck.emplace_back(4, CardType::Monster);
    _deck.emplace_back(2, CardType::Barrier);
    _deck.emplace_back(1, CardType::Weapon);
    _deck.emplace_back(2, CardType::Thing);

}

std::shared_ptr<Card> ForestLocationCardMetadata::createInstance() const {
    return std::shared_ptr<Card>(new ForestLocationCard());
}

ForestLocationCard::~ForestLocationCard() {

}

int ForestLocationCard::getTypeId() const {
    return 1000;
}

void ForestLocationCard::createDeck() {

}
