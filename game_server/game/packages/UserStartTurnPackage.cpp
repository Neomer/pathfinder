//
// Created by kir on 12.07.19.
//

#include "UserStartTurnPackage.h"

UserStartTurnPackage::UserStartTurnPackage(const Player &player) :
        _player(player)
{

}

void UserStartTurnPackage::packageData(nlohmann::json &json) const
{
    _player.toJson(json);
}

uint32_t UserStartTurnPackage::getEventId() const
{
    return 8;
}
