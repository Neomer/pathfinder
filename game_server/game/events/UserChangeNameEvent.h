//
// Created by kir on 04.07.19.
//

#ifndef GAME_SERVER_USERCHANGENAMEEVENT_H
#define GAME_SERVER_USERCHANGENAMEEVENT_H

#include "EventProcessor.h"

class UserChangeNameEvent : public EventProcessor
{
public:
    bool isEventSupported(int eventId) override;

    void process(Player &player, const nlohmann::json &requestData, Game &game) override;
};


#endif //GAME_SERVER_USERCHANGENAMEEVENT_H
