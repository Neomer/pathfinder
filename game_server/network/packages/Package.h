//
// Created by kir on 07.07.19.
//

#ifndef GAME_SERVER_PACKAGE_H
#define GAME_SERVER_PACKAGE_H

#include "../../modules/json/single_include/nlohmann/json.hpp"

class Package
{
public:
    enum class ResultStatus
    {
        Success,
        Error
    };

    virtual uint32_t getEventId() const = 0;

    virtual ResultStatus getResultStatus() const = 0;

    virtual void toJson(nlohmann::json &json) const;
};


#endif //GAME_SERVER_PACKAGE_H
