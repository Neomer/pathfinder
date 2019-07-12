//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_LOCATIONCARD_H
#define GAME_SERVER_LOCATIONCARD_H

#include "../Card.h"

class LocationCard : public Card
{
public:
    LocationCard();

    virtual void createDeck();

    void close();

    virtual void toJson(nlohmann::json &json) const;

private:
    std::vector<std::shared_ptr<Card>> _deck;
    bool _isClosed;
};

class LocationCardMetadata : public CardMetadata
{
public:
    CardType getCardType() const override;

    virtual const std::vector<std::pair<int, CardMetadata::CardType>> &getLocationDeck() const;

    void toJson(nlohmann::json &json) const override;

    void load() override;

protected:
    virtual void fillDeck(std::vector<std::pair<int, CardMetadata::CardType>> &deck) = 0;

private:
    std::vector<std::pair<int, CardMetadata::CardType>> _deck;
};


#endif //GAME_SERVER_LOCATIONCARD_H
