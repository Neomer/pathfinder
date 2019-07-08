//
// Created by vinokurov on 08.07.2019.
//

#include "CardNotFoundPackage.h"

using namespace std::string_literals;

CardNotFoundPackage::CardNotFoundPackage(int cardTypeId) : _cardTypeId(cardTypeId) {

}

std::string_view CardNotFoundPackage::getErrorMessage() const {
    return "Карта с типом "s + std::to_string(_cardTypeId) + " не найдена!";
}

uint32_t CardNotFoundPackage::getEventId() const {
    return 2;
}
