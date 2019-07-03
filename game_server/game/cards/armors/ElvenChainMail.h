//
// Created by vinokurov on 03.07.2019.
//

#ifndef GAME_SERVER_ELVENCHAINMAIL_H
#define GAME_SERVER_ELVENCHAINMAIL_H

#include "../ArmorCard.h"

class ElvenChainMail : public ActiveCard {
public:
    int getTypeId() const override;
};

class ElvenChainMailMetadata : public ArmorCardMetadata
{
public:
    std::string_view getCardTitle() const override;

    const char *getTypeName() const override;

    const char *getDescription() const override;

    std::shared_ptr<Card> createInstance() const override;

    int TypeId() const override;

protected:
    void fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes) override;

    void fillCardsTakenConditions(CardTakenConditions &conditions) override;
};

#endif //GAME_SERVER_ELVENCHAINMAIL_H
