//
// Created by kir on 04.07.19.
//

#include "UserChangeNameEvent.h"
#include "../Player.h"

bool UserChangeNameEvent::isEventSupported(int eventId)
{
    return eventId == 0;
}

void UserChangeNameEvent::process(Player &player, const nlohmann::json &requestData, Game &game)
{
    std::string name;
    player.setName(name);
}
