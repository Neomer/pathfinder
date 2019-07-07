//
// Created by kir on 04.07.19.
//

#ifndef GAME_SERVER_EVENTPROCESSOR_H
#define GAME_SERVER_EVENTPROCESSOR_H

#include "../../modules/json/single_include/nlohmann/json.hpp"

class Game;

class Player;

class EventProcessor
{
public:
    virtual ~EventProcessor() = default;

    virtual bool isEventSupported(int eventId) const = 0;

    virtual void process(Player &player, const nlohmann::json &requestData, Game &game) const = 0;
};


#endif //GAME_SERVER_EVENTPROCESSOR_H
