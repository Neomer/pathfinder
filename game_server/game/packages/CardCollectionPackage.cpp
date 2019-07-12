//
// Created by kir on 07.07.19.
//

#include "CardCollectionPackage.h"

CardCollectionPackage::CardCollectionPackage(const std::vector<const CardMetadata *> &cards) :
        _cards(cards)
{

}

void CardCollectionPackage::packageData(nlohmann::json &json) const
{
    nlohmann::json collection = nlohmann::json::array();
    for (auto metadata : _cards) {
        collection.push_back(metadata->toJsonObject());
    }
    json["cards"] = collection;
}


