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
    ResultStatus getResultStatus() const final;

    virtual std::string_view getErrorMessage() const = 0;
};


#endif //GAME_SERVER_ERRORPACKAGE_H
