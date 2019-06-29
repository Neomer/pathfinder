//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_MAGICCHAINMAIL_H
#define GAME_SERVER_MAGICCHAINMAIL_H

#include "../ArmorCard.h"

class MagicChainMail : public ActiveCard
{
public:
    ~MagicChainMail() override;

    int getTypeId() const override;
};

class MagicChainMailMetadata : public ArmorCardMetadata
{
public:
    std::string_view getCardTitle() const override;

    const char *getTypeName() const override;

    const char *getDescription() const override;

    std::shared_ptr<Card> createInstance() const override;

    bool isBeginnerLevel() const override;

    int TypeId() const override;

protected:
    void fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes) override;
};


#endif //GAME_SERVER_MAGICCHAINMAIL_H
