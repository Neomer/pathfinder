//
// Created by kir on 02.07.19.
//

#include <algorithm>
#include "RoleCard.h"

CardMetadata::CardType RoleCardMetadata::getCardType() const
{
    return CardType::Role;
}

const RoleCardMetadata::RoleSkillCollection &RoleCardMetadata::getSkills() const
{
    return _skills;
}

void RoleCardMetadata::load()
{
    ActiveCardMetadata::load();

    fillSkills(_skills);
}

const std::pair<int, int> RoleCardMetadata::getSkillAmount(ActiveCardMetadata::Skill skill) const
{
    auto it = std::find_if(_skills.begin(), _skills.end(),
            [skill](const RoleSkill &item) {
                return item.first == skill;
            });
    return it == _skills.end() ? std::pair<int, int>(0, 0) : it->second;
}

