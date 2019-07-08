//
// Created by vinokurov on 08.07.2019.
//

#include "UserSelectRoleEvent.h"
#include "../CardMetadataProvider.h"
#include "../Player.h"
#include "../packages/CardNotFoundPackage.h"
#include "../packages/PlayerInfoPackage.h"

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
        player.setRole(role->createInstance());
        PlayerInfoPackage pkg(player);
        player.getTransportPipe()->write(pkg);
    }
}
