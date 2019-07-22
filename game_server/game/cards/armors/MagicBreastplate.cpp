//
// Created by vinokurov on 03.07.2019.
//

#include "MagicBreastplate.h"

int MagicBreastplate::getTypeId() const {
    return 106;
}

std::string_view MagicBreastplateMetadata::getCardTitle() const {
    return "Магический нагрудник";
}

const char *MagicBreastplateMetadata::getTypeName() const {
    return "MagicBreastplate";
}

const char *MagicBreastplateMetadata::getDescription() const {
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> MagicBreastplateMetadata::createInstance() const {
    return std::shared_ptr<Card>(new MagicBreastplate());
}

int MagicBreastplateMetadata::TypeId() const {
    return 106;
}

void MagicBreastplateMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes) {
    attributes.push_back(CardAttribute::AdvancedLevel);
    attributes.push_back(CardAttribute::HeavyArmor);
    attributes.push_back(CardAttribute::Magic);
}

void MagicBreastplateMetadata::fillCardCheckConditions(CheckableCardMetadata::CardCheckConditions &conditions) {
    conditions.emplace_back(std::vector{ Skill::Endurance, Skill::Stamina }, 4);
}
