//
// Created by vinokurov on 08.07.2019.
//

#include "LocationsAvailableRequestEvent.h"
#include "../Game.h"
#include "../packages/LocationsCollectionPackage.h"
#include "../cards/Card.h"

bool LocationsAvailableRequestEvent::isEventSupported(int eventId) const {
    return eventId == 4;
}

void LocationsAvailableRequestEvent::process(Player &player, const nlohmann::json &requestData, Game &game) const {
    std::vector<const CardMetadata *> list;
    auto locations = game.getContext().getScenario()->getLocations();
    for (auto card : locations) {
        list.push_back(card->getMetadata());
    }
    LocationsCollectionPackage pkg(list);
    player.getTransportPipe()->write(pkg);
}
