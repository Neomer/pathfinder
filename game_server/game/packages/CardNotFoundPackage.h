//
// Created by vinokurov on 08.07.2019.
//

#ifndef GAME_SERVER_CARDNOTFOUNDPACKAGE_H
#define GAME_SERVER_CARDNOTFOUNDPACKAGE_H

#include "../../network/packages/ErrorPackage.h"

class CardNotFoundPackage : public ErrorPackage {
public:
    CardNotFoundPackage(uint32_t cardTypeId);

    std::string_view getErrorMessage() const override;

private:
    uint32_t _cardTypeId;
};


#endif //GAME_SERVER_CARDNOTFOUNDPACKAGE_H
