//
// Created by kir on 12.07.19.
//

#ifndef GAME_SERVER_ROLEALREADYBEENCHOSENPACKAGE_H
#define GAME_SERVER_ROLEALREADYBEENCHOSENPACKAGE_H

#include "../../network/packages/ErrorPackage.h"
#include "../cards/Card.h"

class RoleAlreadyBeenChosenPackage : public ErrorPackage
{
public:
    RoleAlreadyBeenChosenPackage(const CardMetadata *roleMetadata);

    std::string_view getErrorMessage() const override;

private:
    const CardMetadata *_roleMetadata;
};


#endif //GAME_SERVER_ROLEALREADYBEENCHOSENPACKAGE_H
