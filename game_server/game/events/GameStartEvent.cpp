//
// Created by kir on 06.07.19.
//

#include "GameStartEvent.h"
#include "../Game.h"

bool GameStartEvent::isEventSupported(int eventId)
{
    return eventId == 1;
}

void GameStartEvent::process(Player &player, const nlohmann::json &requestData, Game &game)
{
    game.getContext()->getScenario()->loadLocations(game.getContext()->getPlayers().size());
}
