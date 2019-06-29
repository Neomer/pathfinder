//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_METADATA_H
#define GAME_SERVER_METADATA_H

#include "../../modules/json/single_include/nlohmann/json.hpp"

class Metadata {
public:
    virtual int TypeId() const = 0;

    virtual void toJson(nlohmann::json &json) const = 0;
};


#endif //GAME_SERVER_METADATA_H
