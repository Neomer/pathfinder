//
// Created by vinokurov on 01.07.2019.
//

#include "Banip.h"

std::string_view BanipMetadata::getCardTitle() const {
    return "Баньип";
}

const char *BanipMetadata::getTypeName() const {
    return "Banip";
}

const char *BanipMetadata::getDescription() const {
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> BanipMetadata::createInstance() const {
    return std::shared_ptr<Card>(new Banip());
}

int BanipMetadata::TypeId() const {
    return 402;
}

void BanipMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes) {
    attributes.push_back(CardAttribute::Water);
    attributes.push_back(CardAttribute::Banip);
    attributes.push_back(CardAttribute::AdvancedLevel);
}

int Banip::getTypeId() const {
    return 402;
}
