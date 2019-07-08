//
// Created by vinokurov on 08.07.2019.
//

#ifndef GAME_SERVER_PLAYERSTURNPACKAGE_H
#define GAME_SERVER_PLAYERSTURNPACKAGE_H

#include "../../network/packages/SuccessPackage.h"
#include "../Player.h"

class PlayersTurnPackage : public SuccessPackage
{
public:
    PlayersTurnPackage(const Player &player, uint8_t turnsLeft);

    uint32_t getEventId() const override;

protected:
    void packageData(nlohmann::json &json) const override;

private:
    uint8_t _turnsLeft;
    const Player &_player;
};


#endif //GAME_SERVER_PLAYERSTURNPACKAGE_H
