//
// Created by kir on 04.07.19.
//

#ifndef GAME_SERVER_EVENTPROCESSOR_H
#define GAME_SERVER_EVENTPROCESSOR_H

#include "../../network/packages/ErrorPackage.h"

class Game;

class Player;

class EventProcessor
{
public:
    virtual ~EventProcessor() = default;

    virtual bool checkEventConditions(Player &player, Game &game, ErrorPackage **errorPackage) const;

    virtual bool isEventSupported(int eventId) const = 0;

    virtual void process(Player &player, const nlohmann::json &requestData, Game &game) const = 0;
};


#endif //GAME_SERVER_EVENTPROCESSOR_H
