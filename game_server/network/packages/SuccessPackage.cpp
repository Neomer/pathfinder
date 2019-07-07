//
// Created by kir on 07.07.19.
//

#include "SuccessPackage.h"

Package::ResultStatus SuccessPackage::getResultStatus() const
{
    return ResultStatus::Success;
}

void SuccessPackage::toJson(nlohmann::json &json) const
{
    Package::toJson(json);
    nlohmann::json dataJson;
    packageData(dataJson);
    json["data"] = dataJson;
}
