//
// Created by vinokurov on 29.06.2019.
//

#include "CultistCard.h"

std::shared_ptr<Card> CultistCardMetadata::createInstance() const {
    return std::shared_ptr<Card>(new BagbierCard());
}

std::string_view CultistCardMetadata::getCardTitle() const {
    return "Культист";
}

const char *CultistCardMetadata::getTypeName() const {
    return "Cultist";
}

int CultistCardMetadata::TypeId() const {
    return 401;
}

void CultistCardMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes) {
    attributes.push_back(CardAttribute::Cultist);
    attributes.push_back(CardAttribute::Human);
}

bool CultistCardMetadata::isBeginnerLevel() const {
    return true;
}

int CultistCard::getTypeId() const {
    return 401;
}
