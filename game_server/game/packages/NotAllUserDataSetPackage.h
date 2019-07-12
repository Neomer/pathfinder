//
// Created by vinokurov on 12.07.2019.
//

#ifndef GAME_SERVER_NOTALLUSERDATASETPACKAGE_H
#define GAME_SERVER_NOTALLUSERDATASETPACKAGE_H

#include "../../network/packages/ErrorPackage.h"
#include "../Player.h"

class NotAllUserDataSetPackage : public ErrorPackage
{
public:
    NotAllUserDataSetPackage(Player &player);

    std::string_view getErrorMessage() const override;

private:
    const Player &_player;
};


#endif //GAME_SERVER_NOTALLUSERDATASETPACKAGE_H
