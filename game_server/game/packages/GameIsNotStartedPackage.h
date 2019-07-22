//
// Created by kir on 22.07.19.
//

#ifndef GAME_SERVER_GAMEISNOTSTARTEDPACKAGE_H
#define GAME_SERVER_GAMEISNOTSTARTEDPACKAGE_H

#include "../../network/packages/ErrorPackage.h"

class GameIsNotStartedPackage : public ErrorPackage
{
public:
    GameIsNotStartedPackage();

    std::string_view getErrorMessage() const override;
};


#endif //GAME_SERVER_GAMEISNOTSTARTEDPACKAGE_H
