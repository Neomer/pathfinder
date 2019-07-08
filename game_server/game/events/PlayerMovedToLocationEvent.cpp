//
// Created by vinokurov on 08.07.2019.
//

#include "PlayerMovedToLocationEvent.h"
#include "../CardMetadataProvider.h"
#include "../cards/Card.h"
#include "../Game.h"
#include "../packages/PlayerInfoPackage.h"

bool PlayerMovedToLocationEvent::isEventSupported(int eventId) const {
    return eventId == 5;
}

void PlayerMovedToLocationEvent::process(Player &player, const nlohmann::json &requestData, Game &game) const {
    auto location = CardMetadataProvider::getInstance().getMetadata(requestData["locationId"]);
    if (location->getCardType() == CardMetadata::CardType::Location) {
        player.setLocation(location->createInstance());
        PlayerInfoPackage pkg(player);
        player.getTransportPipe()->write(pkg);
    } else {
        //TODO: send error: wrong card type
    }
}
