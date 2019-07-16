//
// Created by kir on 12.07.19.
//

#ifndef GAME_SERVER_NOTYOURTURNPACKAGE_H
#define GAME_SERVER_NOTYOURTURNPACKAGE_H

#include "../../network/packages/ErrorPackage.h"

class NotYourTurnPackage : public ErrorPackage
{
public:
    NotYourTurnPackage();

    std::string_view getErrorMessage() const override;
};


#endif //GAME_SERVER_NOTYOURTURNPACKAGE_H
