//
// Created by vinokurov on 03.07.2019.
//

#include "ChainMail.h"

int ChainMail::getTypeId() const {
    return 102;
}

std::string_view ChainMailMetadata::getCardTitle() const {
    return "Кольчуга";
}

const char *ChainMailMetadata::getTypeName() const {
    return "ChainMail";
}

const char *ChainMailMetadata::getDescription() const {
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> ChainMailMetadata::createInstance() const {
    return std::shared_ptr<Card>(new ChainMail());
}

int ChainMailMetadata::TypeId() const {
    return 102;
}

void ChainMailMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes) {
    attributes.push_back(CardAttribute::HeavyArmor);
    attributes.push_back(CardAttribute::BeginnerLevel);
}

void ChainMailMetadata::fillCardCheckConditions(CheckableCardMetadata::CardCheckConditions &conditions) {
    conditions.emplace_back(std::vector{ Skill::Endurance, Skill::Stamina }, 3);
}
