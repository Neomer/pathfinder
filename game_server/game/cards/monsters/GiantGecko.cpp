//
// Created by vinokurov on 01.07.2019.
//

#include "GiantGecko.h"

int GiantGecko::getTypeId() const {
    return 406;
}

std::string_view GiantGeckoMetadata::getCardTitle() const {
    return "Гигантский геккон";
}

const char *GiantGeckoMetadata::getTypeName() const {
    return "GiantGecko";
}

const char *GiantGeckoMetadata::getDescription() const {
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> GiantGeckoMetadata::createInstance() const {
    return std::shared_ptr<Card>(new GiantGecko());
}

int GiantGeckoMetadata::TypeId() const {
    return 406;
}

void GiantGeckoMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes) {
    attributes.push_back(CardAttribute::BeginnerLevel);
    attributes.push_back(CardAttribute::Animal);
}
