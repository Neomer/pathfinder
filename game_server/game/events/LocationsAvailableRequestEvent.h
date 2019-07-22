//
// Created by vinokurov on 08.07.2019.
//

#ifndef GAME_SERVER_LOCATIONSAVAILABLEREQUESTEVENT_H
#define GAME_SERVER_LOCATIONSAVAILABLEREQUESTEVENT_H

#include "EventProcessor.h"

class LocationsAvailableRequestEvent : public EventProcessor
{
public:
    ~LocationsAvailableRequestEvent() override = default;

    bool isEventSupported(int eventId) const override;

    void process(Player &player, const nlohmann::json &requestData, Game &game) const override;

    bool checkEventConditions(Player &player, Game &game, ErrorPackage **errorPackage) const override;
};


#endif //GAME_SERVER_LOCATIONSAVAILABLEREQUESTEVENT_H
