//
// Created by vinokurov on 29.06.2019.
//

#include "Card.h"

CardMetadata::CardMetadata() {

}

bool CardMetadata::hasAttribute(CardMetadata::CardAttribute attribute) const {
    auto it = std::find_if(_attributes.begin(), _attributes.end(),
                           [attribute](CardAttribute item) {
                               return item == attribute;
                           });
    return it != _attributes.end();
}

const std::vector<CardMetadata::CardAttribute> &CardMetadata::getAttributes() const {
    return _attributes;
}

void CardMetadata::load() {
    fillAttributes(_attributes);
}

const char *CardMetadata::getDescription() const {
    return "";
}

void CardMetadata::toJson(nlohmann::json &json) const {
    json["description"] = getDescription();
    json["typeId"] = (int)getCardType();
    json["typeName"] = getTypeName();
    json["attributes"] = nlohmann::json::array();
}
