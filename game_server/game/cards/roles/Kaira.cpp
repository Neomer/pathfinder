//
// Created by vinokurov on 03.07.2019.
//

#include "Kaira.h"

int Kaira::getTypeId() const {
    return 802;
}

std::string_view KairaMetadata::getCardTitle() const {
    return "Кайра";
}

const char *KairaMetadata::getTypeName() const {
    return "Kaira";
}

const char *KairaMetadata::getDescription() const {
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> KairaMetadata::createInstance() const {
    return std::shared_ptr<Card>(new Kaira());
}

int KairaMetadata::TypeId() const {
    return 802;
}

uint8_t KairaMetadata::getHandSize() const {
    return 5;
}

void KairaMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes) {
    attributes.push_back(CardAttribute::Woman);
    attributes.push_back(CardAttribute::Human);
    attributes.push_back(CardAttribute::Priestess);
}

void KairaMetadata::fillSkills(RoleCardMetadata::RoleSkillCollection &skills) {
    skills.emplace_back(Skill::Strength, std::pair<int, int>(6, 0));
    skills.emplace_back(Skill::ShortRange, std::pair<int, int>(6, 2));
    skills.emplace_back(Skill::Agility, std::pair<int, int>(4, 0));
    skills.emplace_back(Skill::Endurance, std::pair<int, int>(6, 0));
    skills.emplace_back(Skill::Stamina, std::pair<int, int>(6, 3));
    skills.emplace_back(Skill::Intelligence, std::pair<int, int>(6, 0));
    skills.emplace_back(Skill::Wisdom, std::pair<int, int>(12, 0));
    skills.emplace_back(Skill::Faith, std::pair<int, int>(12, 2));
    skills.emplace_back(Skill::Charisma, std::pair<int, int>(6, 0));
}

void KairaMetadata::fillMastery(RoleCardMetadata::RoleMastery &mastery) {
    mastery.push_back(Mastery::LightArmor);
    mastery.push_back(Mastery::HeavyArmor);
}

CardMetadata::CardType KairaMetadata::getFavouriteCardType() const {
    return CardType::Blessing;
}

void KairaMetadata::fillStartHandCardTypes(RoleCardMetadata::RoleStartHandCardTypes &startHandCardTypes) {
    startHandCardTypes.emplace_back(CardType::Weapon, 2);
    startHandCardTypes.emplace_back(CardType::Spell, 3);
    startHandCardTypes.emplace_back(CardType::Armor, 2);
    startHandCardTypes.emplace_back(CardType::Thing, 1);
    startHandCardTypes.emplace_back(CardType::Companion, 1);
    startHandCardTypes.emplace_back(CardType::Blessing, 6);
}
