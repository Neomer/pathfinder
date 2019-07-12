//
// Created by vinokurov on 12.07.2019.
//

#ifndef GAME_SERVER_JSONSERIALIZABLE_H
#define GAME_SERVER_JSONSERIALIZABLE_H

#include "../modules/json/single_include/nlohmann/json.hpp"

class JsonSerializable {
public:
    virtual void toJson(nlohmann::json &json) const = 0;

    virtual nlohmann::json toJsonObject() const;
};


#endif //GAME_SERVER_JSONSERIALIZABLE_H
