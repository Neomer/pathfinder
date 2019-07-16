//
// Created by kir on 06.07.19.
//

#include <algorithm>
#include "GameStartEvent.h"
#include "../Game.h"
#include "../packages/PlayersTurnPackage.h"
#include "../packages/GameAlreadyStartedPackage.h"
#include "../packages/NotAllUserDataSetPackage.h"

bool GameStartEvent::isEventSupported(int eventId) const
{
    return eventId == 1;
}

void GameStartEvent::process(Player &player, const nlohmann::json &requestData, Game &game) const
{
    if (game.getContext().isStarted()) {
        GameAlreadyStartedPackage pkg;
        player.getTransportPipe()->write(pkg);
    } else {
        game.getContext().start();
        game.getContext().getScenario()->loadLocations(game.getContext().getPlayers().size());
        PlayersTurnPackage pkg(player, game.getContext().getMovesLeft());
        player.getTransportPipe()->write(pkg);
        game.getSpectatorDispatcher()->broadcast(pkg);
    }
}

bool GameStartEvent::checkEventConditions(Player &player, Game &game, ErrorPackage **errorPackage) const {
    if (game.getContext().isStarted()) {
        *errorPackage = new GameAlreadyStartedPackage();
        return false;
    }
    auto players = game.getContext().getPlayers();
    auto it = std::find_if(players.begin(), players.end(),
                           [](const Player *player) -> bool {
                               return player->getName().empty();
                           });
    if (it != players.end()) {
        *errorPackage = new NotAllUserDataSetPackage(**it);
        return false;
    }
    return true;
}
