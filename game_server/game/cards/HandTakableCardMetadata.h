//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_HANDTAKABLECARDMETADATA_H
#define GAME_SERVER_HANDTAKABLECARDMETADATA_H

#include "Card.h"

class HandTakableCardMetadata : public ActiveCardMetadata
{
public:
    using CardTakenConditions = std::vector<std::pair<std::vector<Skill>, int>>;

    virtual bool isBeginnerLevel() const;

    const CardTakenConditions &getTakenConditions() const;

    void load() override;

protected:
    virtual void fillCardsTakenConditions(CardTakenConditions &conditions) = 0;

private:
    CardTakenConditions _takenConditions;
};


#endif //GAME_SERVER_HANDTAKABLECARDMETADATA_H
