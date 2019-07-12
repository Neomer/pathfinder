//
// Created by vinokurov on 29.06.2019.
//

#include "LocationCard.h"
#include "../../CardMetadataProvider.h"

using namespace std::string_literals;

CardMetadata::CardType LocationCardMetadata::getCardType() const {
    return CardType::Location;
}

void LocationCardMetadata::load() {
    fillDeck(_deck);
}

void LocationCardMetadata::toJson(nlohmann::json &json) const {
    CardMetadata::toJson(json);
}

const std::vector<std::pair<int, CardMetadata::CardType>> &LocationCardMetadata::getLocationDeck() const
{
    return _deck;
}

LocationCard::LocationCard() :
        _isClosed{ false }
{

}

void LocationCard::createDeck() {
    auto metadata = dynamic_cast<const LocationCardMetadata *>(CardMetadataProvider::getInstance().getMetadata(getTypeId()));
    if (metadata == nullptr) {
        throw std::runtime_error("Metadata for type"s + std::to_string(getTypeId()) + " not found!");
    }
    auto deckDescription = metadata->getLocationDeck();
    for(auto cardsOfType : deckDescription) {
        auto metadataList = CardMetadataProvider::getInstance().getMetadata(
                [cardsOfType](const CardMetadata *metadata) -> bool {
                    return metadata->getCardType() == cardsOfType.second;
                });
        auto collectionSize = metadataList.size();
        if (collectionSize > 0) {
            while (cardsOfType.first-- > 0) {
                auto item = rand() % collectionSize;
                _deck.push_back(metadataList.at(item)->createInstance());
            }
        }
    }
}

void LocationCard::toJson(nlohmann::json &json) const {
    Card::toJson(json);
    json["deck"]["size"] = _deck.size();
    json["closed"] = _isClosed;
}

void LocationCard::close() {
    _isClosed = true;
}
