//
// Created by kir on 07.07.19.
//

#ifndef GAME_SERVER_SUCCESSPACKAGE_H
#define GAME_SERVER_SUCCESSPACKAGE_H

#include "Package.h"

class SuccessPackage : public Package
{
public:
    ResultStatus getResultStatus() const final;

    void toJson(nlohmann::json &json) const override;

protected:
    virtual void packageData(nlohmann::json &json) const = 0;
};


#endif //GAME_SERVER_SUCCESSPACKAGE_H
