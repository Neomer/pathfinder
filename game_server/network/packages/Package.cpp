//
// Created by kir on 07.07.19.
//

#include "Package.h"

void Package::toJson(nlohmann::json &json) const
{
    json["result"] = getResultStatus() == ResultStatus::Success ? "success" : "error";
    json["eventId"] = getEventId();
}
