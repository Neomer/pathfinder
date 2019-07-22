//
// Created by vinokurov on 01.07.2019.
//

#include "Mercenary.h"

int Mercenary::getTypeId() const {
    return 409;
}

std::string_view MercenaryMetadata::getCardTitle() const {
    return "Наёмник";
}

const char *MercenaryMetadata::getTypeName() const {
    return "Mercenary";
}

const char *MercenaryMetadata::getDescription() const {
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> MercenaryMetadata::createInstance() const {
    return std::shared_ptr<Card>(new Mercenary());
}

int MercenaryMetadata::TypeId() const {
    return 409;
}

void MercenaryMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes) {
    attributes.push_back(CardAttribute::Human);
    attributes.push_back(CardAttribute::Fighter);
    attributes.push_back(CardAttribute::Veteran);
}

void MercenaryMetadata::fillCardCheckConditions(CheckableCardMetadata::CardCheckConditions &conditions)
{
    conditions.emplace_back(std::vector{ Skill::Fight }, 10);
}
