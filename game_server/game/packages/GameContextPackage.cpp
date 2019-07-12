//
// Created by vinokurov on 11.07.2019.
//

#include "GameContextPackage.h"

GameContextPackage::GameContextPackage(const GameContext &context) :
        _context{ context }
{

}

uint32_t GameContextPackage::getEventId() const {
    return 0;
}

void GameContextPackage::packageData(nlohmann::json &json) const {
    _context.toJson(json);
}
