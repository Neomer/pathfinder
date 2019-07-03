//
// Created by kir on 02.07.19.
//

#include "Harsk.h"

int Harsk::getTypeId() const
{
    return 801;
}

std::string_view HarskMetadata::getCardTitle() const
{
    return "Харск";
}

const char *HarskMetadata::getTypeName() const
{
    return "Harsk";
}

const char *HarskMetadata::getDescription() const
{
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> HarskMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new Harsk());
}

int HarskMetadata::TypeId() const
{
    return 801;
}

void HarskMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes)
{
    attributes.push_back(CardAttribute::Man);
    attributes.push_back(CardAttribute::Dwarf);
    attributes.push_back(CardAttribute::Tracker);
}

void HarskMetadata::fillSkills(RoleCardMetadata::RoleSkillCollection &skills)
{
    skills.emplace_back(Skill::Strength, std::pair<int, int>(6, 0));
    skills.emplace_back(Skill::Agility, std::pair<int, int>(8, 0));
    skills.emplace_back(Skill::LongRange, std::pair<int, int>(8, 3));
    skills.emplace_back(Skill::Endurance, std::pair<int, int>(12, 0));
    skills.emplace_back(Skill::Stamina, std::pair<int, int>(12, 2));
    skills.emplace_back(Skill::Intelligence, std::pair<int, int>(6, 0));
    skills.emplace_back(Skill::Wisdom, std::pair<int, int>(4, 0));
    skills.emplace_back(Skill::Attention, std::pair<int, int>(4, 2));
    skills.emplace_back(Skill::Survival, std::pair<int, int>(4, 2));
    skills.emplace_back(Skill::Charisma, std::pair<int, int>(4, 0));
}

void HarskMetadata::fillMastery(RoleCardMetadata::RoleMastery &mastery) {
    mastery.push_back(Mastery::LightArmor);
    mastery.push_back(Mastery::Weapon);
}

uint8_t HarskMetadata::getHandSize() const {
    return 5;
}

CardMetadata::CardType HarskMetadata::getFavouriteCardType() const {
    return CardType::Weapon;
}

void HarskMetadata::fillStartHandCardTypes(RoleCardMetadata::RoleStartHandCardTypes &startHandCardTypes) {
    startHandCardTypes.emplace_back(CardType::Weapon, 5);
    startHandCardTypes.emplace_back(CardType::Armor, 1);
    startHandCardTypes.emplace_back(CardType::Thing, 3);
    startHandCardTypes.emplace_back(CardType::Companion, 1);
    startHandCardTypes.emplace_back(CardType::Blessing, 5);
}
