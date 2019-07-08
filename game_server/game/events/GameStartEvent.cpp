//
// Created by kir on 06.07.19.
//

#include "GameStartEvent.h"
#include "../Game.h"
#include "../packages/PlayersTurnPackage.h"

bool GameStartEvent::isEventSupported(int eventId) const
{
    return eventId == 1;
}

void GameStartEvent::process(Player &player, const nlohmann::json &requestData, Game &game) const
{
    game.getContext().getScenario()->loadLocations(game.getContext().getPlayers().size());
    PlayersTurnPackage pkg(player, game.getContext().getMovesLeft());
    player.getTransportPipe()->write(pkg);
}
