//
// Created by kir on 07.07.19.
//

#ifndef GAME_SERVER_PLAYERINFOPACKAGE_H
#define GAME_SERVER_PLAYERINFOPACKAGE_H

#include "../../network/packages/SuccessPackage.h"
#include "../Player.h"

class PlayerInfoPackage : public SuccessPackage
{
public:
    PlayerInfoPackage(const Player &player);

    uint32_t getEventId() const override;

protected:
    void packageData(nlohmann::json &json) const override;

private:
    const Player &_player;
};


#endif //GAME_SERVER_PLAYERINFOPACKAGE_H
