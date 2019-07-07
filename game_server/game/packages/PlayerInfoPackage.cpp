//
// Created by kir on 07.07.19.
//

#include "PlayerInfoPackage.h"

PlayerInfoPackage::PlayerInfoPackage(const Player &player) :
        _player(player)
{

}

uint32_t PlayerInfoPackage::getEventId() const
{
    return 0;
}

void PlayerInfoPackage::packageData(nlohmann::json &json) const
{
    json["userName"] = _player.getName();
    if (_player.getRole().get() != nullptr) {
        nlohmann::json roleJson;
        _player.getRole()->toJson(roleJson);
        json["role"] = roleJson;
    }
}

