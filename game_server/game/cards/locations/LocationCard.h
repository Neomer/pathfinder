//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_LOCATIONCARD_H
#define GAME_SERVER_LOCATIONCARD_H

#include "../Card.h"

class LocationCard : public Card
{
public:
    virtual void createDeck() = 0;
};

class LocationCardMetadata : public CardMetadata
{
public:
    CardType getCardType() const override;

    virtual const std::vector<std::pair<int, CardMetadata::CardType>> &getLocationDeck() const = 0;

    void load() override;
};


#endif //GAME_SERVER_LOCATIONCARD_H
