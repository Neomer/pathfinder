//
// Created by vinokurov on 29.06.2019.
//

#include "PoisonTrapCard.h"

std::shared_ptr<Card> PoisonTrapCardMetadata::createInstance() const {
    return std::shared_ptr<Card>(new PoisonTrapCard());
}

std::string_view PoisonTrapCardMetadata::getCardTitle() const {
    return "Ядовитая ловушка";
}

const char *PoisonTrapCardMetadata::getTypeName() const {
    return "PoisonTrap";
}

int PoisonTrapCardMetadata::TypeId() const {
    return 302;
}

void PoisonTrapCardMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes) {
    attributes.push_back(CardAttribute::Trap);
    attributes.push_back(CardAttribute::Poison);
}

int PoisonTrapCard::getTypeId() const {
    return 302;
}
