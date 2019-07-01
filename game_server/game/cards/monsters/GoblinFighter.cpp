//
// Created by vinokurov on 01.07.2019.
//

#include "GoblinFighter.h"

int GoblinFighter::getTypeId() const {
    return 408;
}

std::string_view GoblinFighterMetadata::getCardTitle() const {
    return "Гоблин-боец";
}

const char *GoblinFighterMetadata::getTypeName() const {
    return "GoblinFighter";
}

const char *GoblinFighterMetadata::getDescription() const {
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> GoblinFighterMetadata::createInstance() const {
    return std::shared_ptr<Card>(new GoblinFighter());
}

int GoblinFighterMetadata::TypeId() const {
    return 408;
}

void GoblinFighterMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes) {
    attributes.push_back(CardAttribute::AdvancedLevel);
    attributes.push_back(CardAttribute::Goblin);
    attributes.push_back(CardAttribute::Fighter);
}
