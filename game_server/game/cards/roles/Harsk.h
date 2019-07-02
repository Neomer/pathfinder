//
// Created by kir on 02.07.19.
//

#ifndef GAME_SERVER_HARSK_H
#define GAME_SERVER_HARSK_H

#include "../RoleCard.h"

class Harsk : public RoleCard
{
public:
    int getTypeId() const override;
};

class HarskMetadata : public RoleCardMetadata
{
public:
    std::string_view getCardTitle() const override;

    const char *getTypeName() const override;

    const char *getDescription() const override;

    std::shared_ptr<Card> createInstance() const override;

    int TypeId() const override;

protected:
    void fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes) override;
};


#endif //GAME_SERVER_HARSK_H
