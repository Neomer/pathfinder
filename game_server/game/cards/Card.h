//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_CARD_H
#define GAME_SERVER_CARD_H

#include <memory>
#include <string_view>
#include <vector>
#include "Metadata.h"

class Card
{
public:
    virtual ~Card() {}

    virtual int getTypeId() const = 0;

};


class CardMetadata : public Metadata
{
public:
    CardMetadata();

    enum class CardType
    {
        Weapon,     // Оружие
        Spell,      // Заклинание
        Armor,      // Броня
        Thing,      // Предмет
        Companion,  // Компаньон
        Blessing,   // Благословение
        Monster,    // Монстр
        Servant,    // Прислужник
        Boss        // Босс
    };

    enum class CardAttribute
    {
        // -----Аттрибуты Заклинаний ------
                Magic,      // Магия
        Faith,      // Вера
        Heal,       // Лечение
        Charms,     // Чары
        Attack,     // Атака
        Energy,     // Энергия
        Electricity,// Электричество
        Acid,       // Кислота
        Psycho,     // Психика

        // -----Аттрибуты оружия ------
                Sword,      // Меч
        Bow,        // Лук
        Mace,       // Булава
        Pole,       // Древковое оружие
        Axe,        // Топор
        Chain,      // Цепь
        Knife,      // Нож
        Staff,      // Посох
        Dart,       // Дротик
        Sling,      // Праща
        ShortRange, // Ближний бой
        LongRange,  // Дальний бой
        Slashing,   // Рубящее оружие
        Piercing,   // Колющее оружие
        Crushing,   // Дробящее оружие
        TwoHand,    // Двуручное оружие
        Rare,       // Редкость

    };

    enum class Skill
    {
        Strength,       // Сила
        Agility,        // Ловкость
        Endurance,      // Выносливость
        Intelligence,   // Интеллект
        Wisdom,         // Мудрость
        Charisma        // Харизма
    };

    void load();

    virtual std::shared_ptr<Card> createInstance() const = 0;

    virtual std::string_view  getCardTitle() const = 0;

    virtual CardMetadata::CardType getCardType() const = 0;

    virtual const char *getTypeName() const = 0;

    virtual const char *getDescription() const;

    const std::vector<CardMetadata::CardAttribute> &getAttributes() const;

    bool hasAttribute(CardAttribute attribute) const;

    void toJson(nlohmann::json &json) const override;

protected:
    virtual void fillAttributes(std::vector<CardMetadata::CardAttribute> &attributes) = 0;

private:
    std::vector<CardMetadata::CardAttribute> _attributes;
};


#endif //GAME_SERVER_CARD_H
