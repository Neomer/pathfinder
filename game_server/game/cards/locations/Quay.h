//
// Created by kir on 12.07.19.
//

#ifndef GAME_SERVER_QUAY_H
#define GAME_SERVER_QUAY_H

#include "LocationCard.h"

class Quay : public LocationCard
{
public:
    int getTypeId() const override;
};

class QuayMetadata : public LocationCardMetadata
{
public:
    std::string_view getCardTitle() const override;

    const char *getTypeName() const override;

    const char *getDescription() const override;

    std::shared_ptr<Card> createInstance() const override;

    int TypeId() const override;

protected:
    void fillDeck(std::vector<std::pair<int, CardMetadata::CardType>> &deck) override;
};

#endif //GAME_SERVER_QUAY_H
