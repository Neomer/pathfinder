//
// Created by vinokurov on 03.07.2019.
//

#ifndef GAME_SERVER_KAIRA_H
#define GAME_SERVER_KAIRA_H

#include "../RoleCard.h"

class Kaira : public RoleCard {
public:
    int getTypeId() const override;
};

class KairaMetadata : public RoleCardMetadata
{
public:
    std::string_view getCardTitle() const override;

    const char *getTypeName() const override;

    const char *getDescription() const override;

    std::shared_ptr<Card> createInstance() const override;

    int TypeId() const override;

    uint8_t getHandSize() const override;

    CardType getFavouriteCardType() const override;

protected:
    void fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes) override;

    void fillSkills(RoleSkillCollection &skills) override;

    void fillMastery(RoleMastery &mastery) override;

    void fillStartHandCardTypes(RoleStartHandCardTypes &startHandCardTypes) override;
};

#endif //GAME_SERVER_KAIRA_H
