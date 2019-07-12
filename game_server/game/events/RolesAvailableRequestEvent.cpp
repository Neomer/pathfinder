//
// Created by kir on 07.07.19.
//

#include <algorithm>
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
    auto players = game.getContext().getPlayers();
    auto roles = CardMetadataProvider::getInstance().getMetadata(
            [&game, &players](const CardMetadata *metadata) -> bool {
                return metadata != nullptr && metadata->getCardType() == CardMetadata::CardType::Role &&
                    std::find_if(players.begin(), players.end(),
                            [&metadata](const Player *player) -> bool {
                                return
                                    player != nullptr &&
                                    player->getRole() != nullptr &&
                                    player->getRole()->getTypeId() == metadata->TypeId();
                            }) == players.end();
             });
    RolesCollectionPackage pkg(roles);
    player.getTransportPipe()->write(pkg);
}
