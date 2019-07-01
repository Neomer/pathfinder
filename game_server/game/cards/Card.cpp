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
    json["typeId"] = cardTypeToString(getCardType());
    json["typeName"] = getTypeName();
    json["title"] = getCardTitle();
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
    }
    return std::to_string((int) attribute).c_str();
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
        case CardType::Boss: return "Босс";
        case CardType::Scenario: return "Сценарий";
        case CardType::Location: return "Локация";
        case CardType::Barrier: return "Предграда";
    }
    return std::to_string((int) type).c_str();
}

const CardMetadata *Card::getMetadata() const {
    return CardMetadataProvider::getInstance().getMetadata(getTypeId());
}
