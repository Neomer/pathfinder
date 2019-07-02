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

    CardType getCardType() const override;

    const RoleSkillCollection &getSkills() const;

    const std::pair<int, int> getSkillAmount(ActiveCardMetadata::Skill skill) const;

    void load() override;

protected:
    virtual void fillSkills(RoleSkillCollection &skills) = 0;

private:
    RoleSkillCollection _skills;
};


#endif //GAME_SERVER_ROLECARD_H
