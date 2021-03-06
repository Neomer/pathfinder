//
// Created by vinokurov on 29.06.2019.
//

#include "HealCard.h"

std::shared_ptr<Card> HealCardMetadata::createInstance() const {
    return std::shared_ptr<Card>(new HealCard());
}

std::string_view HealCardMetadata::getCardTitle() const {
    return "Исцеление";
}

const char *HealCardMetadata::getTypeName() const {
    return "Heal";
}

int HealCardMetadata::TypeId() const {
    return 0;
}

void HealCardMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes) {
    attributes.push_back(CardAttribute::Magic);
    attributes.push_back(CardAttribute::Faith);
    attributes.push_back(CardAttribute::Heal);
}

bool HealCardMetadata::isBeginnerLevel() const {
    return true;
}

int HealCard::getTypeId() const {
    return 0;
}
