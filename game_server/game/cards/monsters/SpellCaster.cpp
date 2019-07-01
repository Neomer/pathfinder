//
// Created by vinokurov on 01.07.2019.
//

#include "SpellCaster.h"

int SpellCaster::getTypeId() const {
    return 403;
}

std::string_view SpellCasterMetadata::getCardTitle() const {
    return "Заклинательница";
}

const char *SpellCasterMetadata::getTypeName() const {
    return "SpellCaster";
}

const char *SpellCasterMetadata::getDescription() const {
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> SpellCasterMetadata::createInstance() const {
    return std::shared_ptr<Card>(new SpellCaster());
}

int SpellCasterMetadata::TypeId() const {
    return 403;
}

void SpellCasterMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes) {
    attributes.push_back(CardAttribute::Human);
    attributes.push_back(CardAttribute::Witchcraft);
    attributes.push_back(CardAttribute::Veteran);
}
