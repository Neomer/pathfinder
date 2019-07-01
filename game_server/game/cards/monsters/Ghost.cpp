//
// Created by vinokurov on 01.07.2019.
//

#include "Ghost.h"

int Ghost::getTypeId() const {
    return 404;
}

std::string_view GhostMetadata::getCardTitle() const {
    return "Привидение";
}

const char *GhostMetadata::getTypeName() const {
    return "Ghost";
}

const char *GhostMetadata::getDescription() const {
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> GhostMetadata::createInstance() const {
    return std::shared_ptr<Card>(new Ghost());
}

int GhostMetadata::TypeId() const {
    return 404;
}

void GhostMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes) {
    attributes.push_back(CardAttribute::Undead);
    attributes.push_back(CardAttribute::Disembodied);
    attributes.push_back(CardAttribute::Ghost);
    attributes.push_back(CardAttribute::AdvancedLevel);
}
