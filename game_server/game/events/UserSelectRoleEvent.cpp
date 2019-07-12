//
// Created by vinokurov on 08.07.2019.
//

#include "UserSelectRoleEvent.h"
#include "../CardMetadataProvider.h"
#include "../Player.h"
#include "../Game.h"
#include "../packages/CardNotFoundPackage.h"
#include "../packages/PlayerInfoPackage.h"
#include "../packages/RoleAlreadyBeenChosenPackage.h"

bool UserSelectRoleEvent::isEventSupported(int eventId) const {
    return eventId == 3;
}

void UserSelectRoleEvent::process(Player &player, const nlohmann::json &requestData, Game &game) const {
    uint32_t cardTypeId = requestData["roleId"];
    auto role = CardMetadataProvider::getInstance().getMetadata(cardTypeId);
    if (role == nullptr) {
        CardNotFoundPackage pkg(cardTypeId);
        player.getTransportPipe()->write(pkg);
    } else {
        auto alreadySelected = std::find_if(game.getContext().getPlayers().begin(), game.getContext().getPlayers().end(),
                                            [cardTypeId](const Player *player) -> bool {
                                                return player != nullptr &&
                                                       player->getRole() != nullptr &&
                                                       player->getRole()->getTypeId() == cardTypeId;
                                            }) != game.getContext().getPlayers().end();
        if (alreadySelected) {
            RoleAlreadyBeenChosenPackage pkg(role);
            player.getTransportPipe()->write(pkg);
        } else {
            player.setRole(role->createInstance());
            PlayerInfoPackage pkg(player);
            player.getTransportPipe()->write(pkg);
        }
    }
}
