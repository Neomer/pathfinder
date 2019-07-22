//
// Created by vinokurov on 03.07.2019.
//

#include "ElvenChainMail.h"

int ElvenChainMail::getTypeId() const {
    return 103;
}

std::string_view ElvenChainMailMetadata::getCardTitle() const {
    return "Эльфийская кольчуга";
}

const char *ElvenChainMailMetadata::getTypeName() const {
    return "ElvenChainMail";
}

const char *ElvenChainMailMetadata::getDescription() const {
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> ElvenChainMailMetadata::createInstance() const {
    return std::shared_ptr<Card>(new ElvenChainMail());
}

int ElvenChainMailMetadata::TypeId() const {
    return 103;
}

void ElvenChainMailMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes) {
    attributes.push_back(CardAttribute::AdvancedLevel);
    attributes.push_back(CardAttribute::LightArmor);
    attributes.push_back(CardAttribute::Magic);
}

void ElvenChainMailMetadata::fillCardCheckConditions(CheckableCardMetadata::CardCheckConditions &conditions) {
    conditions.emplace_back(std::vector{ Skill::Endurance, Skill::Stamina }, 6);
}
