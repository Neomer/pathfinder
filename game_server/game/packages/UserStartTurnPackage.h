//
// Created by kir on 12.07.19.
//

#ifndef GAME_SERVER_USERSTARTTURNPACKAGE_H
#define GAME_SERVER_USERSTARTTURNPACKAGE_H

#include "../../network/packages/SuccessPackage.h"
#include "../Player.h"

class UserStartTurnPackage : public SuccessPackage
{
public:
    UserStartTurnPackage(const Player &player);

    uint32_t getEventId() const override;

protected:
    void packageData(nlohmann::json &json) const override;

private:
    const Player &_player;
};


#endif //GAME_SERVER_USERSTARTTURNPACKAGE_H
