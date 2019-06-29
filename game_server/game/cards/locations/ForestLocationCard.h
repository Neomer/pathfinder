//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_FORESTLOCATIONCARD_H
#define GAME_SERVER_FORESTLOCATIONCARD_H

#include "LocationCard.h"

class ForestLocationCard : public LocationCard {
public:
    ~ForestLocationCard() override;

    int getTypeId() const override;
};

class ForestLocationCardMetadata : public LocationCardMetadata {
public:
    ForestLocationCardMetadata();

    std::string_view getCardTitle() const override;

    const char *getTypeName() const override;

    const char *getDescription() const override;

    int TypeId() const override;

    const std::vector<std::pair<int, CardMetadata::CardType>> &getLocationDeck() const override;

    std::shared_ptr<Card> createInstance() const override;

private:
    std::vector<std::pair<int, CardMetadata::CardType>> _deck;
};

#endif //GAME_SERVER_FORESTLOCATIONCARD_H
