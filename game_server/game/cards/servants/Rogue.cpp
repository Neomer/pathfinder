//
// Created by vinokurov on 29.06.2019.
//

#include "RogueCard.h"

std::shared_ptr<Card> RogueCardMetadata::createInstance() const {
    return std::shared_ptr<Card>(new RogueCard());
}

std::string_view RogueCardMetadata::getCardTitle() const {
    return "Разбойник";
}

const char *RogueCardMetadata::getTypeName() const {
    return "Rogue";
}

int RogueCardMetadata::TypeId() const {
    return 301;
}

void RogueCardMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes) {
    attributes.push_back(CardAttribute::Rogue);
    attributes.push_back(CardAttribute::Human);
}

int RogueCard::getTypeId() const {
    return 301;
}
