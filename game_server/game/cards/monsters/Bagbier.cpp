//
// Created by vinokurov on 29.06.2019.
//

#include "Bagbier.h"

std::shared_ptr<Card> BagbierCardMetadata::createInstance() const {
    return std::shared_ptr<Card>(new BagbierCard());
}

std::string_view BagbierCardMetadata::getCardTitle() const {
    return "Багбир";
}

const char *BagbierCardMetadata::getTypeName() const {
    return "Bagbier";
}

int BagbierCardMetadata::TypeId() const {
    return 400;
}

void BagbierCardMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes) {
    attributes.push_back(CardAttribute::Fighter);
    attributes.push_back(CardAttribute::Goblin);
	attributes.push_back(CardAttribute::Bagbier);
}

bool BagbierCardMetadata::isBeginnerLevel() const {
    return false;
}

int BagbierCard::getTypeId() const {
    return 400;
}
