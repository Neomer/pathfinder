//
// Created by vinokurov on 29.06.2019.
//

#include "MagicShield.h"

MagicShield::~MagicShield() {

}

int MagicShield::getTypeId() const {
    return 101;
}

std::string_view MagicShieldMetadata::getCardTitle() const {
    return "Волшебный щит";
}

const char *MagicShieldMetadata::getTypeName() const {
    return "MagicShield";
}

const char *MagicShieldMetadata::getDescription() const {
    return CardMetadata::getDescription();
}

bool MagicShieldMetadata::isBeginnerLevel() const {
    return false;
}

int MagicShieldMetadata::TypeId() const {
    return 101;
}

void MagicShieldMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes) {
    attributes.push_back(CardAttribute::Shield);
    attributes.push_back(CardAttribute::OneHand);
    attributes.push_back(CardAttribute::Magic);
}

std::shared_ptr<Card> MagicShieldMetadata::createInstance() const {
    return std::shared_ptr<Card>(new MagicShield());
}
