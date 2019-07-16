//
// Created by vinokurov on 08.07.2019.
//

#include "PlayersTurnPackage.h"

PlayersTurnPackage::PlayersTurnPackage(const Player &player, uint8_t turnsLeft) :
    _turnsLeft{ turnsLeft },
    _player{ player }
{

}

uint32_t PlayersTurnPackage::getEventId() const {
    return 3;
}

void PlayersTurnPackage::packageData(nlohmann::json &json) const {
    json["turnLeft"] = _turnsLeft;
    json["player"] = _player.toJsonObject();
}
