//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_METADATA_H
#define GAME_SERVER_METADATA_H

#include "../../core/JsonSerializable.h"
#include "../../modules/json/single_include/nlohmann/json.hpp"

class Metadata : public JsonSerializable {
public:
    virtual int TypeId() const = 0;
};


#endif //GAME_SERVER_METADATA_H
