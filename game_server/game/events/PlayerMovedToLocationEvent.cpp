//
// Created by vinokurov on 08.07.2019.
//

#include "PlayerMovedToLocationEvent.h"
#include "../CardMetadataProvider.h"
#include "../cards/Card.h"
#include "../Game.h"
#include "../packages/PlayerInfoPackage.h"
#include "../packages/GameIsNotStartedPackage.h"
#include "../packages/NotYourTurnPackage.h"

bool PlayerMovedToLocationEvent::isEventSupported(int eventId) const {
    return eventId == 5;
}

void PlayerMovedToLocationEvent::process(Player &player, const nlohmann::json &requestData, Game &game) const {
    auto scenarioLocations = game.getContext().getScenario()->getLocations();
    int locationId = requestData["locationId"];
    auto it = std::find_if(scenarioLocations.begin(), scenarioLocations.end(), [locationId](std::shared_ptr<Card> &card) {
        return card->getTypeId() == locationId;
    });
    if (it == scenarioLocations.end()) {
        //TODO: send error: location not found
    } else {
        player.setLocation(*it);
        PlayerInfoPackage pkg(player);
        player.getTransportPipe()->write(pkg);
    }
}

bool PlayerMovedToLocationEvent::checkEventConditions(Player &player, Game &game, ErrorPackage **errorPackage) const
{
    if (!game.getContext().isStarted()) {
        *errorPackage = new GameIsNotStartedPackage();
        return false;
    }
    if (game.getContext().getCurrentPlayer() != &player) {
        *errorPackage = new NotYourTurnPackage();
        return false;
    }
    return EventProcessor::checkEventConditions(player, game, errorPackage);
}
