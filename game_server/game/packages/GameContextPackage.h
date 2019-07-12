//
// Created by vinokurov on 11.07.2019.
//

#ifndef GAME_SERVER_GAMECONTEXTPACKAGE_H
#define GAME_SERVER_GAMECONTEXTPACKAGE_H

#include "../../network/packages/SuccessPackage.h"
#include "../GameContext.h"

class GameContextPackage : public SuccessPackage
{
public:
    GameContextPackage(const GameContext &context);

    uint32_t getEventId() const override;

protected:
    void packageData(nlohmann::json &json) const override;

private:
    const GameContext &_context;
};


#endif //GAME_SERVER_GAMECONTEXTPACKAGE_H
