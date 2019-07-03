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
    fillMastery(_mastery);
    fillStartHandCardTypes(_startHandCardTypes);
}

const std::pair<int, int> RoleCardMetadata::getSkillAmount(ActiveCardMetadata::Skill skill) const
{
    auto it = std::find_if(_skills.begin(), _skills.end(),
            [skill](const RoleSkill &item) {
                return item.first == skill;
            });
    return it == _skills.end() ? std::pair<int, int>(0, 0) : it->second;
}

bool RoleCardMetadata::hasMastery(ActiveCardMetadata::Mastery mastery) const {
    return std::find(_mastery.begin(), _mastery.end(), mastery) != _mastery.end();
}

const RoleCardMetadata::RoleStartHandCardTypes &RoleCardMetadata::getStartHandCardTypes() const {
    return _startHandCardTypes;
}

