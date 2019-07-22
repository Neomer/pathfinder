//
// Created by vinokurov on 29.06.2019.
//

#include "CheckableCardMetadata.h"

bool CheckableCardMetadata::isBeginnerLevel() const {
    return hasAttribute(CardAttribute::BeginnerLevel);
}

void CheckableCardMetadata::load()
{
    ActiveCardMetadata::load();

    fillCardCheckConditions(_checkConditions);
}

const CheckableCardMetadata::CardCheckConditions &CheckableCardMetadata::getCardCheckConditions() const
{
    return _checkConditions;
}

void CheckableCardMetadata::toJson(nlohmann::json &json) const
{
    ActiveCardMetadata::toJson(json);
    nlohmann::json::array_t conditionsArrayJson;
    for (auto cond : _checkConditions) {
        nlohmann::json condJson;
        nlohmann::json::array_t skillsJson;
        for (auto condSkills : cond.first) {
            skillsJson.push_back(skillToString(condSkills));
        }
        condJson["skills"] = skillsJson;
        condJson["amount"] = cond.second;
        conditionsArrayJson.push_back(condJson);
    }
    json["checkConditions"] = conditionsArrayJson;
}
