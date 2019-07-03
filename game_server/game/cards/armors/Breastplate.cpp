//
// Created by vinokurov on 03.07.2019.
//

#include "Breastplate.h"

int Breastplate::getTypeId() const {
    return 104;
}

std::string_view BreastplateMetadata::getCardTitle() const {
    return "Нагрудник";
}

const char *BreastplateMetadata::getTypeName() const {
    return "Breastplate";
}

const char *BreastplateMetadata::getDescription() const {
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> BreastplateMetadata::createInstance() const {
    return std::shared_ptr<Card>(new Breastplate());
}

int BreastplateMetadata::TypeId() const {
    return 104;
}

void BreastplateMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes) {
    attributes.push_back(CardAttribute::AdvancedLevel);
    attributes.push_back(CardAttribute::HeavyArmor);
}

void BreastplateMetadata::fillCardsTakenConditions(HandTakableCardMetadata::CardTakenConditions &conditions) {
    conditions.emplace_back(std::vector{ Skill::Endurance, Skill::Stamina }, 4);
}
