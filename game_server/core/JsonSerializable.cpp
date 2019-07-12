//
// Created by vinokurov on 12.07.2019.
//

#include "JsonSerializable.h"

nlohmann::json JsonSerializable::toJsonObject() const {
    nlohmann::json obj;
    toJson(obj);
    return obj;
}
