//
// Created by kir on 07.07.19.
//

#ifndef GAME_SERVER_CARDCOLLECTIONPACKAGE_H
#define GAME_SERVER_CARDCOLLECTIONPACKAGE_H

#include "../../network/packages/SuccessPackage.h"
#include "../cards/Card.h"

class CardCollectionPackage : public SuccessPackage
{
public:
    CardCollectionPackage(const std::vector<const CardMetadata *> &cards);

    uint32_t getEventId() const override;

protected:
    void packageData(nlohmann::json &json) const override;

private:
    const std::vector<const CardMetadata *> &_cards;
};


#endif //GAME_SERVER_CARDCOLLECTIONPACKAGE_H
