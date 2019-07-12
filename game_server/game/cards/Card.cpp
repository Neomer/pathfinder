//
// Created by vinokurov on 29.06.2019.
//

#include "Card.h"
#include "../CardMetadataProvider.h"

ActiveCardMetadata::ActiveCardMetadata() {

}

bool ActiveCardMetadata::hasAttribute(ActiveCardMetadata::CardAttribute attribute) const {
    auto it = std::find_if(_attributes.begin(), _attributes.end(),
                           [attribute](CardAttribute item) {
                               return item == attribute;
                           });
    return it != _attributes.end();
}

const std::vector<ActiveCardMetadata::CardAttribute> &ActiveCardMetadata::getAttributes() const {
    return _attributes;
}

void ActiveCardMetadata::load() {
    fillAttributes(_attributes);
}

const char *CardMetadata::getDescription() const {
    return "";
}

void CardMetadata::toJson(nlohmann::json &json) const {
    json["description"] = getDescription();
    json["cardTypeId"] = (int)getCardType();
    json["cardTypeName"] = cardTypeToString(getCardType());
    json["typeName"] = getTypeName();
    json["title"] = getCardTitle();
    json["typeId"] = TypeId();
}

void ActiveCardMetadata::toJson(nlohmann::json &json) const {
    CardMetadata::toJson(json);
    auto attrArray = nlohmann::json::array();
    for (auto attr : getAttributes()) {
        attrArray.push_back(attributeToString(attr));
    }
    json["attributes"] = attrArray;
}

const char *ActiveCardMetadata::attributeToString(CardAttribute attribute) {
    switch (attribute) {
        case CardAttribute::Magic: return "Магия";
        case CardAttribute::Faith: return "Вера";
        case CardAttribute::Heal: return "Лечение";
        case CardAttribute::Charms: return "Чары";
        case CardAttribute::Attack: return "Атака";
        case CardAttribute::Energy: return "Энергия";
        case CardAttribute::Electricity: return "Электричество";
        case CardAttribute::Acid: return "Кислота";
        case CardAttribute::Psycho: return "Психика";
        case CardAttribute::Bow: return "Лук";
        case CardAttribute::Mace: return "Булава";
        case CardAttribute::Pole: return "Древковое оружие";
        case CardAttribute::Axe: return "Топор";
        case CardAttribute::Chain: return "Цепь";
        case CardAttribute::Knife: return "Нож";
        case CardAttribute::Staff: return "Посох";
        case CardAttribute::Dart: return "Дротик";
        case CardAttribute::Sling: return "Праща";
        case CardAttribute::ShortRange: return "Ближний бой";
        case CardAttribute::LongRange: return "Дальний бой";
        case CardAttribute::Slashing: return "Рубящее оружие";
        case CardAttribute::Piercing: return "Колющее оружие";
        case CardAttribute::Crushing: return "Дробящее оружие";
        case CardAttribute::TwoHand: return "Двуручное оружие";
        case CardAttribute::Rare: return "Редкость";
        case CardAttribute::Spear: return "Копье";
        case CardAttribute::HeavyArmor: return "Тяжелая броня";
        case CardAttribute::LightArmor: return "Легкая броня";
        case CardAttribute::OneHand: return "Занятая рука";
        case CardAttribute::Shield: return "Щит";
        case CardAttribute::Decoration: return "Украшение";
        case CardAttribute::Undead: return "Нежить";
        case CardAttribute::Skeleton: return "Скелет";
        case CardAttribute::Human: return "Человек";
        case CardAttribute::Rogue: return "Разбойник";
        case CardAttribute::Cheat: return "Плут";
        case CardAttribute::Trap: return "Ловушка";
        case CardAttribute::Poison: return "Яд";
        case CardAttribute::Bagbier: return "Багбир";
        case CardAttribute::Goblin: return "Гоблин";
        case CardAttribute::Fighter: return "Боец";
        case CardAttribute::Cultist: return "Культист";
        case CardAttribute::Banip: return "Баньип";
        case CardAttribute::Water: return "Вода";
        case CardAttribute::Witchcraft: return "Чародей";
        case CardAttribute::Veteran: return "Ветеран";
        case CardAttribute::Disembodied: return "Бестелесность";
        case CardAttribute::Ghost: return "Привидение";
        case CardAttribute::Ghoul: return "Упырь";
        case CardAttribute::Animal: return "Животное";
        case CardAttribute::Shooter: return "Стрелок";
        case CardAttribute::Giant: return "Великан";
        case CardAttribute::Ogre: return "Огр";
        case CardAttribute::Zombie: return "Зомби";
        case CardAttribute::Siren: return "Сирена";
        case CardAttribute::Wizard: return "Волшебник";
        case CardAttribute::Dwarf: return "Дварф";
        case CardAttribute::Tracker: return "Следопыт";
        case CardAttribute::Man: return "Мужчина";
        case CardAttribute::Woman: return "Женщина";
        case CardAttribute::Priestess: return "Жрица";
        case CardAttribute::BeginnerLevel: return "Начальный уровень";
        case CardAttribute::AdvancedLevel: return "Продвинутый уровень";
        case CardAttribute::Sword: return "Меч";
    }
}

const char *CardMetadata::cardTypeToString(CardType type) {
    switch (type) {
        case CardType::Weapon: return "Оружие";
        case CardType::Spell: return "Заклинание";
        case CardType::Armor: return "Броня";
        case CardType::Thing: return "Предмет";
        case CardType::Companion: return "Компаньон";
        case CardType::Blessing: return "Благословение";
        case CardType::Monster: return "Монстр";
        case CardType::Servant: return "Прислужник";
        case CardType::Boss: return "Босс";
        case CardType::Scenario: return "Сценарий";
        case CardType::Location: return "Локация";
        case CardType::Barrier: return "Предграда";
        case CardType::Role: return "Роль";
    }
}

const CardMetadata *Card::getMetadata() const {
    return CardMetadataProvider::getInstance().getMetadata(getTypeId());
}

void Card::toJson(nlohmann::json &json) const
{
    json["metadata"] = getMetadata()->toJsonObject();
}

