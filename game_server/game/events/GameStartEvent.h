//
// Created by kir on 06.07.19.
//

#ifndef GAME_SERVER_GAMESTARTEVENT_H
#define GAME_SERVER_GAMESTARTEVENT_H

#include "EventProcessor.h"

class GameStartEvent : public EventProcessor
{
public:
    ~GameStartEvent() override = default;

    bool isEventSupported(int eventId) const override;

    void process(Player &player, const nlohmann::json &requestData, Game &game) const override;
};


#endif //GAME_SERVER_GAMESTARTEVENT_H
