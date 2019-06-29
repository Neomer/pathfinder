//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_PACKAGE_H
#define GAME_SERVER_PACKAGE_H

#include "../../modules/json/single_include/nlohmann/json.hpp"

class Package {

public:

    virtual void fromJson(nlohmann::json &json);

    virtual void toJson(nlohmann::json &json);

    int getEventId() const;

    void setEventId(int eventId);

private:
    int _eventId;

};


#endif //GAME_SERVER_PACKAGE_H
