//
// Created by kir on 13.07.19.
//

#ifndef GAME_SERVER_LOCATIONISCLOSEDPACKAGE_H
#define GAME_SERVER_LOCATIONISCLOSEDPACKAGE_H

#include "../../network/packages/ErrorPackage.h"
#include "../cards/locations/LocationCard.h"

class LocationIsClosedPackage : public ErrorPackage
{
public:
    LocationIsClosedPackage(const LocationCard *location);

private:
    std::string_view getErrorMessage() const override;

private:
    const LocationCard *_location;
};


#endif //GAME_SERVER_LOCATIONISCLOSEDPACKAGE_H
