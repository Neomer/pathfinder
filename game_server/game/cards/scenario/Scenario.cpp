//
// Created by vinokurov on 29.06.2019.
//

#include "Scenario.h"
#include "../locations/LocationCard.h"
#include "../../CardMetadataProvider.h"

CardMetadata::CardType ScenarioMetadata::getCardType() const {
    return CardType::Scenario;
}

void ScenarioMetadata::load() {

}

void ScenarioMetadata::toJson(nlohmann::json &json) const {
    CardMetadata::toJson(json);
    auto locations = nlohmann::json::array();
    for (auto loc : getLocationsByPlayers()) {
        auto locationMetadata = dynamic_cast<const LocationCardMetadata *>(CardMetadataProvider::getInstance().getMetadata(loc.second));
        if (locationMetadata != nullptr) {
            nlohmann::json obj;
            obj["players"] = loc.first;
            nlohmann::json objLocation;
            locationMetadata->toJson(objLocation);
            obj["location"] = objLocation;
            locations.push_back(obj);
        }
    }
    json["locations"] = locations;

}

void Scenario::toJson(nlohmann::json &json) const {

}
