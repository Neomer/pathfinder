//
// Created by kir on 07.07.19.
//

#ifndef GAME_SERVER_ROLESAVAILABLEREQUESTEVENT_H
#define GAME_SERVER_ROLESAVAILABLEREQUESTEVENT_H

#include "EventProcessor.h"

class RolesAvailableRequestEvent : public EventProcessor
{
public:
    ~RolesAvailableRequestEvent() override = default;

    bool isEventSupported(int eventId) const override;

    void process(Player &player, const nlohmann::json &requestData, Game &game) const override;
};


#endif //GAME_SERVER_ROLESAVAILABLEREQUESTEVENT_H
