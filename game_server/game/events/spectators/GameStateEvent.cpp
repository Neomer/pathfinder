//
// Created by vinokurov on 11.07.2019.
//

#include "GameStateEvent.h"

bool GameStateEvent::isEventSupported(int eventId) const {
    return eventId == 0;
}

void GameStateEvent::process(Player &player, const nlohmann::json &requestData, Game &game) const {

}
