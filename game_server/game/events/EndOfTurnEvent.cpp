//
// Created by kir on 12.07.19.
//

#include "EndOfTurnEvent.h"
#include "../Game.h"
#include "../packages/NotYourTurnPackage.h"
#include "../packages/PlayersTurnPackage.h"

bool EndOfTurnEvent::checkEventConditions(Player &player, Game &game, ErrorPackage **errorPackage) const
{
    if (game.getContext().getCurrentPlayer() != &player) {
        *errorPackage = new NotYourTurnPackage();
        return false;
    }
    return EventProcessor::checkEventConditions(player, game, errorPackage);;
}

bool EndOfTurnEvent::isEventSupported(int eventId) const
{
    return eventId == 6;
}

void EndOfTurnEvent::process(Player &player, const nlohmann::json &requestData, Game &game) const
{
    game.getContext().nextTurn();
    PlayersTurnPackage pkg(player, game.getContext().getMovesLeft());
    const_cast<Player *>(game.getContext().getCurrentPlayer())->getTransportPipe()->write(pkg);
    game.getSpectatorDispatcher()->broadcast(pkg);
}
