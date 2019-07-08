//
// Created by kir on 07.07.19.
//

#include "RolesAvailableRequestEvent.h"
#include "../Game.h"
#include "../CardMetadataProvider.h"
#include "../packages/RolesCollectionPackage.h"

bool RolesAvailableRequestEvent::isEventSupported(int eventId) const
{
    return eventId == 2;
}

void RolesAvailableRequestEvent::process(Player &player, const nlohmann::json &requestData, Game &game) const
{
    auto roles = CardMetadataProvider::getInstance().getMetadata(
            [](const CardMetadata *metadata) {
                return metadata->getCardType() == CardMetadata::CardType::Role;
            });
    RolesCollectionPackage pkg(roles);
    player.getTransportPipe()->write(pkg);
}
