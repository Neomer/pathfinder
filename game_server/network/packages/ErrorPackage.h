//
// Created by kir on 07.07.19.
//

#ifndef GAME_SERVER_ERRORPACKAGE_H
#define GAME_SERVER_ERRORPACKAGE_H

#include <string_view>
#include "Package.h"

class ErrorPackage : public Package
{
public:
    ErrorPackage(uint32_t eventId);

    ResultStatus getResultStatus() const final;

    uint32_t getEventId() const override;

    virtual std::string_view getErrorMessage() const = 0;

    void toJson(nlohmann::json &json) const override;

private:
    uint32_t _eventId;
};


#endif //GAME_SERVER_ERRORPACKAGE_H
