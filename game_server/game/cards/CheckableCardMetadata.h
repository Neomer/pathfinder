//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_CHECKABLECARDMETADATA_H
#define GAME_SERVER_CHECKABLECARDMETADATA_H

#include "Card.h"

/**
 * Абстрактный класс для карт, имеющих любую проверку (боя или приобретения)
 */
class CheckableCardMetadata : public ActiveCardMetadata
{
public:
    using CardCheckConditions = std::vector<std::pair<std::vector<Skill>, int>>;

    virtual bool isBeginnerLevel() const;

    const CardCheckConditions &getCardCheckConditions() const;

    void load() override;

    void toJson(nlohmann::json &json) const override;

protected:
    virtual void fillCardCheckConditions(CardCheckConditions &conditions) = 0;

private:
    CardCheckConditions _checkConditions;
};


#endif //GAME_SERVER_CHECKABLECARDMETADATA_H
