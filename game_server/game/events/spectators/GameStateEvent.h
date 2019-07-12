//
// Created by vinokurov on 11.07.2019.
//

#ifndef GAME_SERVER_GAMESTATEEVENT_H
#define GAME_SERVER_GAMESTATEEVENT_H

#include "../EventProcessor.h"

class GameStateEvent : public EventProcessor
{
public:
    ~GameStateEvent() override = default;

    bool isEventSupported(int eventId) const override;

    void process(Player &player, const nlohmann::json &requestData, Game &game) const override;
};


#endif //GAME_SERVER_GAMESTATEEVENT_H
