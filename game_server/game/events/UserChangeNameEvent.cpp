//
// Created by kir on 04.07.19.
//

#include "UserChangeNameEvent.h"
#include "../Player.h"
#include "../Game.h"
#include "../packages/PlayerInfoPackage.h"

bool UserChangeNameEvent::isEventSupported(int eventId) const
{
    return eventId == 0;
}

void UserChangeNameEvent::process(Player &player, const nlohmann::json &requestData, Game &game) const
{
    std::string name = requestData["name"];
    player.setName(name);

    PlayerInfoPackage pkg(player);
    game.getSpectatorDispatcher()->broadcast(pkg);
}
