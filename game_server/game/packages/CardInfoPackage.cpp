//
// Created by kir on 22.07.19.
//

#include "CardInfoPackage.h"

uint32_t CardInfoPackage::getEventId() const
{
    return 10;
}

void CardInfoPackage::packageData(nlohmann::json &json) const
{
    _card->toJson(json);
}

CardInfoPackage::CardInfoPackage(const std::shared_ptr<Card> &card) :
        _card(card)
{

}
