//
// Created by vinokurov on 03.07.2019.
//

#include "LeatherArmor.h"

int LeatherArmor::getTypeId() const {
    return 105;
}

std::string_view LeatherArmorMetadata::getCardTitle() const {
    return "Кожаная броня";
}

const char *LeatherArmorMetadata::getTypeName() const {
    return "LeatherArmor";
}

const char *LeatherArmorMetadata::getDescription() const {
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> LeatherArmorMetadata::createInstance() const {
    return std::shared_ptr<Card>(new LeatherArmor());
}

int LeatherArmorMetadata::TypeId() const {
    return 105;
}

void LeatherArmorMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes) {
    attributes.push_back(CardAttribute::BeginnerLevel);
    attributes.push_back(CardAttribute::LightArmor);
}

void LeatherArmorMetadata::fillCardsTakenConditions(HandTakableCardMetadata::CardTakenConditions &conditions) {
    conditions.emplace_back(std::vector{ Skill::Endurance, Skill::Stamina }, 2);
}
