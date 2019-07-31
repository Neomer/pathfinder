//
// Created by kir on 13.07.19.
//

#include "ExploreLocationEvent.h"
#include "../../Logger.h"
#include "../Game.h"
#include "../packages/NotYourTurnPackage.h"
#include "../packages/LocationNotSelectedPackage.h"
#include "../packages/LocationIsClosedPackage.h"
#include "../cards/locations/LocationCard.h"
#include "../packages/CardInfoPackage.h"

bool ExploreLocationEvent::checkEventConditions(Player &player, Game &game, ErrorPackage **errorPackage) const
{
    if (game.getContext().getCurrentPlayer() != &player) {
        *errorPackage = new NotYourTurnPackage();
        return false;
    }
    if (player.getLocation() == nullptr) {
        *errorPackage = new LocationNotSelectedPackage(player);
        return false;
    }
    auto locationCard = dynamic_cast<LocationCard *>(player.getLocation().get());
    if (locationCard != nullptr && locationCard->isClosed()) {
        *errorPackage = new LocationIsClosedPackage(locationCard);
        return false;
    }
    return EventProcessor::checkEventConditions(player, game, errorPackage);
}

bool ExploreLocationEvent::isEventSupported(int eventId) const
{
    return eventId == 7;
}

void ExploreLocationEvent::process(Player &player, const nlohmann::json &requestData, Game &game) const
{
    auto location = dynamic_cast<LocationCard*>(player.getLocation().get());
    auto card = location->openCard();
    if (card == nullptr) {
        Logger::getInstace().error("Колода пуста!");
        return;
    }
    game.getContext().setActiveCard(card);
    CardInfoPackage pkg(card);
    player.getTransportPipe()->write(pkg);
    game.getSpectatorDispatcher()->broadcast(pkg);
}
