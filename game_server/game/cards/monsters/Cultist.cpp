//
// Created by vinokurov on 29.06.2019.
//

#include "Cultist.h"

std::shared_ptr<Card> CultistCardMetadata::createInstance() const {
    return std::shared_ptr<Card>(new CultistCard());
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
    attributes.push_back(CardAttribute::BeginnerLevel);
}

void CultistCardMetadata::fillCardCheckConditions(CheckableCardMetadata::CardCheckConditions &conditions)
{
    conditions.emplace_back(std::vector{ Skill::Fight }, 9);
}


int CultistCard::getTypeId() const {
    return 401;
}
