//
// Created by kir on 13.07.19.
//

#ifndef GAME_SERVER_EXPLORELOCATIONEVENT_H
#define GAME_SERVER_EXPLORELOCATIONEVENT_H

#include "EventProcessor.h"

class ExploreLocationEvent : public EventProcessor
{
public:
    bool checkEventConditions(Player &player, Game &game, ErrorPackage **errorPackage) const override;

    bool isEventSupported(int eventId) const override;

    void process(Player &player, const nlohmann::json &requestData, Game &game) const override;
};


#endif //GAME_SERVER_EXPLORELOCATIONEVENT_H
