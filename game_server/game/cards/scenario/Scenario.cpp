//
// Created by vinokurov on 29.06.2019.
//

#include "Scenario.h"
#include "../../../Logger.h"
#include "../locations/LocationCard.h"
#include "../../CardMetadataProvider.h"

using namespace std::string_literals;

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

void Scenario::loadLocations(uint8_t playersCount)
{
    auto scenarioMetadata = dynamic_cast<const ScenarioMetadata *>(getMetadata());
    for (auto &loc : scenarioMetadata->getLocationsByPlayers()) {
        if (loc.first <= playersCount) {
            auto locationMetadata = dynamic_cast<const LocationCardMetadata *>(CardMetadataProvider::getInstance().getMetadata(loc.second));
            if (locationMetadata == nullptr) {
                Logger::getInstace().error("TypeId "s + std::to_string(loc.second) + " is not Location for scenario " + scenarioMetadata->getTypeName());
                continue;
            }
            _locations.push_back(locationMetadata->createInstance());
        }
    }
}

const std::vector<std::shared_ptr<Card>> &Scenario::getLocations() const {
    return _locations;
}
