//
// Created by vinokurov on 12.07.2019.
//

#ifndef GAME_SERVER_GAMEALREADYSTARTEDPACKAGE_H
#define GAME_SERVER_GAMEALREADYSTARTEDPACKAGE_H

#include "../../network/packages/ErrorPackage.h"

class GameAlreadyStartedPackage : public ErrorPackage {
public:
    GameAlreadyStartedPackage();

    std::string_view getErrorMessage() const override;
};


#endif //GAME_SERVER_GAMEALREADYSTARTEDPACKAGE_H
