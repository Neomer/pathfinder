//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_SERVANTCARD_H
#define GAME_SERVER_SERVANTCARD_H

#include "../ServantCard.h"

class RogueCard : public Card
{
public:
    int getTypeId() const override;
};

class RogueCardMetadata : public ServantCardMetadata
{
public:
    std::shared_ptr<Card> createInstance() const override;

    std::string_view getCardTitle() const override;

    const char *getTypeName() const override;

    int TypeId() const override;

protected:
    void fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes) override;
};

#endif //GAME_SERVER_SERVANTCARD_H
