//
// Created by vinokurov on 08.07.2019.
//

#ifndef GAME_SERVER_USERSELECTROLEEVENT_H
#define GAME_SERVER_USERSELECTROLEEVENT_H

#include "EventProcessor.h"

class UserSelectRoleEvent : public EventProcessor
{
public:
    ~UserSelectRoleEvent() override = default;

    bool isEventSupported(int eventId) const override;

    void process(Player &player, const nlohmann::json &requestData, Game &game) const override;
};


#endif //GAME_SERVER_USERSELECTROLEEVENT_H
