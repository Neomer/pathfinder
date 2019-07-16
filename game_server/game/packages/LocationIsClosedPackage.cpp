#include <utility>

//
// Created by kir on 13.07.19.
//

#include "LocationIsClosedPackage.h"

using namespace std::string_literals;

LocationIsClosedPackage::LocationIsClosedPackage(const LocationCard *location) :
        ErrorPackage(9),
        _location(location)
{

}

std::string_view LocationIsClosedPackage::getErrorMessage() const
{
    auto locationTitle = _location->getMetadata()->getCardTitle();
    return "Локация "s + std::string(locationTitle.data(), locationTitle.size()) + " уже закрыта!";
}
