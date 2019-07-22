//
// Created by kir on 22.07.19.
//

#ifndef GAME_SERVER_CARDINFOPACKAGE_H
#define GAME_SERVER_CARDINFOPACKAGE_H

#include "../../network/packages/SuccessPackage.h"
#include "../cards/Card.h"

class CardInfoPackage : public SuccessPackage
{
public:
    CardInfoPackage(const std::shared_ptr<Card> &card);

    uint32_t getEventId() const override;

protected:
    void packageData(nlohmann::json &json) const override;

private:
    std::shared_ptr<Card> _card;
};


#endif //GAME_SERVER_CARDINFOPACKAGE_H
