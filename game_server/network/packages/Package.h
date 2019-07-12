//
// Created by kir on 07.07.19.
//

#ifndef GAME_SERVER_PACKAGE_H
#define GAME_SERVER_PACKAGE_H

#include "../../core/JsonSerializable.h"

class Package : public JsonSerializable
{
public:
    enum class ResultStatus
    {
        Success,
        Error
    };

    virtual uint32_t getEventId() const = 0;

    virtual ResultStatus getResultStatus() const = 0;

    void toJson(nlohmann::json &json) const override;
};


#endif //GAME_SERVER_PACKAGE_H
