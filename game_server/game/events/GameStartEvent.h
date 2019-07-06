//
// Created by kir on 06.07.19.
//

#ifndef GAME_SERVER_GAMESTARTEVENT_H
#define GAME_SERVER_GAMESTARTEVENT_H

#include "EventProcessor.h"

class GameStartEvent : public EventProcessor
{
public:
    bool isEventSupported(int eventId) override;

    void process(Player &player, const nlohmann::json &requestData, Game &game) override;
};


#endif //GAME_SERVER_GAMESTARTEVENT_H
