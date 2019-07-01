//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_CARD_H
#define GAME_SERVER_CARD_H

#include <memory>
#include <string_view>
#include <vector>
#include "Metadata.h"

class CardMetadata;

class Card
{
public:
    virtual ~Card() {}

    virtual int getTypeId() const = 0;

    virtual const CardMetadata *getMetadata() const;

};

class ActiveCard : public Card
{
public:

};

class CardMetadata : public Metadata
{
public:
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
        Boss,       // Босс
        Scenario,   // Сценарий
        Location,   // Локация
        Barrier,    // Предграда
    };

    virtual std::string_view  getCardTitle() const = 0;

    virtual CardMetadata::CardType getCardType() const = 0;

    virtual const char *getTypeName() const = 0;

    virtual const char *getDescription() const;

    virtual void load() = 0;

    void toJson(nlohmann::json &json) const override;

    virtual std::shared_ptr<Card> createInstance() const = 0;

private:

    static const char *cardTypeToString(CardType type);

};


class ActiveCardMetadata : public CardMetadata
{
public:
    ActiveCardMetadata();

    enum class CardAttribute
    {
        BeginnerLevel, // Начальный уровень
        AdvancedLevel, // Продвинутый уровень

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
        Spear,      // Копье

        HeavyArmor, // Тяжелая броня
        OneHand,    // Занятая рука
        Shield,     // Щит

        Decoration, // Украшение

// -----Аттрибуты монстров ------
        Undead, 	// Нежить
        Skeleton,	// Скелет
        Human, 		// Человек
        Rogue,		// Разбойник
        Cheat,      // Плут
        Trap, 		// Ловушка
        Poison,		// Яд
        Bagbier, 	// Багбир
        Goblin,		// Гоблин
        Fighter,	// Боец
        Cultist,	// Культист
        Banip,      // Баньип
        Water,      // Вода
        Witchcraft, // Чародей
        Veteran,    // Ветеран
        Disembodied,// Бестелесность
        Ghost,      // Привидение
        Ghoul,      // Упырь
        Animal,     // Животное
        Shooter,    // Стрелок
        Giant,      // Великан
        Ogre,       // Огр
        Zombie,     // Зомби
        Siren,      // Сирена
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

    void load() override;

    const std::vector<ActiveCardMetadata::CardAttribute> &getAttributes() const;

    bool hasAttribute(CardAttribute attribute) const;

    void toJson(nlohmann::json &json) const override;

protected:
    virtual void fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes) = 0;

    static const char *attributeToString(CardAttribute attribute);

private:
    std::vector<ActiveCardMetadata::CardAttribute> _attributes;
};


#endif //GAME_SERVER_CARD_H
