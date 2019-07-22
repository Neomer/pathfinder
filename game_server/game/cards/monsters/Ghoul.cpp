//
// Created by vinokurov on 01.07.2019.
//

#include "Ghoul.h"

int Ghoul::getTypeId() const {
    return 405;
}

std::string_view GhoulMetadata::getCardTitle() const {
    return "Упырь";
}

const char *GhoulMetadata::getTypeName() const {
    return "Ghoul";
}

const char *GhoulMetadata::getDescription() const {
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> GhoulMetadata::createInstance() const {
    return std::shared_ptr<Card>(new Ghoul());
}

int GhoulMetadata::TypeId() const {
    return 405;
}

void GhoulMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes) {
    attributes.push_back(CardAttribute::Undead);
    attributes.push_back(CardAttribute::Ghoul);
    attributes.push_back(CardAttribute::AdvancedLevel);
}

void GhoulMetadata::fillCardCheckConditions(CheckableCardMetadata::CardCheckConditions &conditions)
{
    conditions.emplace_back(std::vector{ Skill::Fight }, 11);
}
