//
// Created by vinokurov on 01.07.2019.
//

#include "GoblinSaboteur.h"

int GoblinSaboteur::getTypeId() const {
    return 407;
}

std::string_view GoblinSaboteurMetadata::getCardTitle() const {
    return "Гоблин-диверсант";
}

const char *GoblinSaboteurMetadata::getTypeName() const {
    return "GoblinSaboteur";
}

const char *GoblinSaboteurMetadata::getDescription() const {
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> GoblinSaboteurMetadata::createInstance() const {
    return std::shared_ptr<Card>(new GoblinSaboteur());
}

int GoblinSaboteurMetadata::TypeId() const {
    return 407;
}

void GoblinSaboteurMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes) {
    attributes.push_back(CardAttribute::AdvancedLevel);
    attributes.push_back(CardAttribute::Shooter);
    attributes.push_back(CardAttribute::Goblin);
}

void GoblinSaboteurMetadata::fillCardCheckConditions(CheckableCardMetadata::CardCheckConditions &conditions)
{
    conditions.emplace_back(std::vector{ Skill::Fight }, 9);
}
