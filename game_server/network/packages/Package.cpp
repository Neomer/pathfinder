//
// Created by vinokurov on 29.06.2019.
//

#include "Package.h"

void Package::fromJson(nlohmann::json &json) {
    _eventId = json["eventId"];
}

void Package::toJson(nlohmann::json &json) {
    json["eventId"] = _eventId;
}

int Package::getEventId() const {
    return _eventId;
}

void Package::setEventId(int eventId) {
    _eventId = eventId;
}
