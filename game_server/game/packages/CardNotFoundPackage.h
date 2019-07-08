//
// Created by vinokurov on 08.07.2019.
//

#ifndef GAME_SERVER_CARDNOTFOUNDPACKAGE_H
#define GAME_SERVER_CARDNOTFOUNDPACKAGE_H

#include "../../network/packages/ErrorPackage.h"

class CardNotFoundPackage : public ErrorPackage {
public:
    CardNotFoundPackage(int cardTypeId);

    std::string_view getErrorMessage() const override;

    uint32_t getEventId() const override;

private:
    int _cardTypeId;
};


#endif //GAME_SERVER_CARDNOTFOUNDPACKAGE_H
