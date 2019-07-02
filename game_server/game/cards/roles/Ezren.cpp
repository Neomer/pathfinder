//
// Created by kir on 02.07.19.
//

#include "Ezren.h"

int Ezren::getTypeId() const
{
    return 800;
}

std::string_view EzrenMetadata::getCardTitle() const
{
    return "Эзрен";
}

const char *EzrenMetadata::getTypeName() const
{
    return "Ezren";
}

const char *EzrenMetadata::getDescription() const
{
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> EzrenMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new Ezren());
}

int EzrenMetadata::TypeId() const
{
    return 800;
}

void EzrenMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes)
{
    attributes.push_back(CardAttribute::Man);
    attributes.push_back(CardAttribute::Human);
    attributes.push_back(CardAttribute::Wizard);
}

void EzrenMetadata::fillSkills(RoleCardMetadata::RoleSkillCollection &skills)
{
    skills.emplace_back(Skill::Strength, std::pair<int, int>(6, 0));
    skills.emplace_back(Skill::Agility, std::pair<int, int>(6, 0));
    skills.emplace_back(Skill::Endurance, std::pair<int, int>(4, 0));
    skills.emplace_back(Skill::Intelligence, std::pair<int, int>(12, 0));
    skills.emplace_back(Skill::Charms, std::pair<int, int>(12, 2));
    skills.emplace_back(Skill::Knowledge, std::pair<int, int>(12, 2));
    skills.emplace_back(Skill::Wisdom, std::pair<int, int>(8, 0));
    skills.emplace_back(Skill::Charisma, std::pair<int, int>(6, 0));
}
