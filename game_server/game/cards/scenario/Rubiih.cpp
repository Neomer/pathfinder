//
// Created by vinokurov on 29.06.2019.
//

#include "Rubiih.h"

std::string_view RubiihMetadata::getCardTitle() const {
    return "Рубиих!";
}

const char *RubiihMetadata::getTypeName() const {
    return "Rubiih";
}

const char *RubiihMetadata::getDescription() const {
    return CardMetadata::getDescription();
}

int RubiihMetadata::TypeId() const {
    return 10000;
}

const std::vector<std::pair<int, int>> &RubiihMetadata::getLocationsByPlayers() const {
    return _locations;
}

RubiihMetadata::RubiihMetadata() {
    _locations.emplace_back(1, 1000);
    _locations.emplace_back(1, 1001);
    _locations.emplace_back(1, 1002);
    _locations.emplace_back(2, 1003);
    _locations.emplace_back(3, 1004);
    _locations.emplace_back(4, 1005);
}

std::shared_ptr<Card> RubiihMetadata::createInstance() const {
    return std::shared_ptr<Card>(new Rubiih());
}

Rubiih::~Rubiih() {

}

int Rubiih::getTypeId() const {
    return 10000;
}
