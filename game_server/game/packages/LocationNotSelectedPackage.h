//
// Created by kir on 13.07.19.
//

#ifndef GAME_SERVER_LOCATIONNOTSELECTEDPACKAGE_H
#define GAME_SERVER_LOCATIONNOTSELECTEDPACKAGE_H

#include "../../network/packages/ErrorPackage.h"
#include "../Player.h"

class LocationNotSelectedPackage : public ErrorPackage
{
public:
    LocationNotSelectedPackage(const Player &player);

    std::string_view getErrorMessage() const override;

private:
    const Player &_player;
};


#endif //GAME_SERVER_LOCATIONNOTSELECTEDPACKAGE_H
