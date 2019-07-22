//
// Created by vinokurov on 01.07.2019.
//

#include "HillGiant.h"

int HillGiant::getTypeId() const {
    return 410;
}

std::string_view HillGiantMetadata::getCardTitle() const {
    return "Холмовой великан";
}

const char *HillGiantMetadata::getTypeName() const {
    return "HillGiant";
}

const char *HillGiantMetadata::getDescription() const {
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> HillGiantMetadata::createInstance() const {
    return std::shared_ptr<Card>(new HillGiant());
}

int HillGiantMetadata::TypeId() const {
    return 410;
}

void HillGiantMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes) {
    attributes.push_back(CardAttribute::Giant);
}

void HillGiantMetadata::fillCardCheckConditions(CheckableCardMetadata::CardCheckConditions &conditions)
{
    conditions.emplace_back(std::vector{ Skill::Fight }, 15);
}
