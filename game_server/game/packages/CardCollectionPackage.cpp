//
// Created by kir on 07.07.19.
//

#include "CardCollectionPackage.h"

CardCollectionPackage::CardCollectionPackage(const std::vector<const CardMetadata *> &cards) :
        _cards(cards)
{

}

uint32_t CardCollectionPackage::getEventId() const
{
    return 1;
}

void CardCollectionPackage::packageData(nlohmann::json &json) const
{
    nlohmann::json collection = nlohmann::json::array();
    for (auto metadata : _cards) {
        nlohmann::json metaJson;
        metadata->toJson(metaJson);
        collection.push_back(metaJson);
    }
    json["cards"] = collection;
}

