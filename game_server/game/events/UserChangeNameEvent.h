//
// Created by kir on 04.07.19.
//

#ifndef GAME_SERVER_USERCHANGENAMEEVENT_H
#define GAME_SERVER_USERCHANGENAMEEVENT_H

#include "EventProcessor.h"

class UserChangeNameEvent : public EventProcessor
{
public:
    ~UserChangeNameEvent() override = default;

    bool isEventSupported(int eventId) const override;

    void process(Player &player, const nlohmann::json &requestData, Game &game) const override;
};


#endif //GAME_SERVER_USERCHANGENAMEEVENT_H
