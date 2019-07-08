//
// Created by vinokurov on 08.07.2019.
//

#include "PlayersTurnPackage.h"

PlayersTurnPackage::PlayersTurnPackage(const Player &player, uint8_t turnsLeft) :
    _turnsLeft{ turnsLeft },
    _player{ _player }
{

}

uint32_t PlayersTurnPackage::getEventId() const {
    return 3;
}

void PlayersTurnPackage::packageData(nlohmann::json &json) const {
    json["turnLeft"] = _turnsLeft;
    /*
    nlohmann::json playerJson;
    playerJson["userName"] = _player.getName();
    if ( _player.getRole().get() != nullptr) {
        nlohmann::json playerRoleJson;
        _player.getRole()->toJson(playerRoleJson);
        playerJson["role"] = playerRoleJson;
    }
    json["player"] = playerJson;
    */
}
