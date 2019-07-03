//
// Created by kir on 02.07.19.
//

#ifndef GAME_SERVER_ROLECARD_H
#define GAME_SERVER_ROLECARD_H

#include "Card.h"

class RoleCard : public Card
{

};

class RoleCardMetadata : public ActiveCardMetadata
{
public:
    using RoleSkill = std::pair<Skill, std::pair<int, int>>;
    using RoleSkillCollection = std::vector<RoleSkill>;
    using RoleMastery = std::vector<Mastery>;
    using RoleStartHandCardTypes = std::vector<std::pair<CardType, int>>;

    CardType getCardType() const override;

    const RoleSkillCollection &getSkills() const;

    const std::pair<int, int> getSkillAmount(ActiveCardMetadata::Skill skill) const;

    const RoleStartHandCardTypes &getStartHandCardTypes() const;

    bool hasMastery(Mastery mastery) const;

    void load() override;

    virtual uint8_t getHandSize() const = 0;

    virtual CardType getFavouriteCardType() const = 0;

protected:
    virtual void fillSkills(RoleSkillCollection &skills) = 0;
    virtual void fillMastery(RoleMastery &mastery) = 0;
    virtual void fillStartHandCardTypes(RoleStartHandCardTypes &startHandCardTypes) = 0;

private:
    RoleSkillCollection _skills;
    RoleMastery _mastery;
    RoleStartHandCardTypes _startHandCardTypes;
};


#endif //GAME_SERVER_ROLECARD_H
