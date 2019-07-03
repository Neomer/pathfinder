//
// Created by vinokurov on 29.06.2019.
//

#include "MagicChainMail.h"

std::string_view MagicChainMailMetadata::getCardTitle() const {
    return "Волшебная кольчуга";
}

const char *MagicChainMailMetadata::getTypeName() const {
    return "MagicChainMail";
}

const char *MagicChainMailMetadata::getDescription() const {
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> MagicChainMailMetadata::createInstance() const {
    return std::shared_ptr<Card>(new MagicChainMail());
}

bool MagicChainMailMetadata::isBeginnerLevel() const {
    return false;
}

int MagicChainMailMetadata::TypeId() const {
    return 100;
}

void MagicChainMailMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes) {
    attributes.push_back(CardAttribute::Magic);
    attributes.push_back(CardAttribute::HeavyArmor);
}

void MagicChainMailMetadata::fillCardsTakenConditions(HandTakableCardMetadata::CardTakenConditions &conditions)
{
    conditions.emplace_back(std::vector{ Skill::Endurance, Skill::Stamina }, 3);
}

MagicChainMail::~MagicChainMail() {

}

int MagicChainMail::getTypeId() const {
    return 100;
}
