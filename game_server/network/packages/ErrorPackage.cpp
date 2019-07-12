//
// Created by kir on 07.07.19.
//

#include <string_view>
#include "ErrorPackage.h"


ErrorPackage::ErrorPackage(uint32_t eventId) : _eventId(eventId) {

}

Package::ResultStatus ErrorPackage::getResultStatus() const
{
    return ResultStatus::Error;
}

uint32_t ErrorPackage::getEventId() const {
    return _eventId;
}

void ErrorPackage::toJson(nlohmann::json &json) const {
    Package::toJson(json);
    auto errMsgStringView = getErrorMessage();
    std::string errorMessage{ errMsgStringView.data(), errMsgStringView.size() } ;
    json["errorMessage"] = errorMessage;
}
