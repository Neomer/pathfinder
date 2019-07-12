//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_CARD_H
#define GAME_SERVER_CARD_H

#include <memory>
#include <string_view>
#include <vector>
#include "../../core/JsonSerializable.h"
#include "Metadata.h"

class CardMetadata;

class Card : public JsonSerializable
{
public:
    virtual ~Card() = default;

    virtual int getTypeId() const = 0;

    virtual const CardMetadata *getMetadata() const;

    void toJson(nlohmann::json &json) const override;
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
        Role,       // Роль
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

// -----Аттрибуты брони ------
        HeavyArmor, // Тяжелая броня
        LightArmor, // Легкая броня
        OneHand,    // Занятая рука
        Shield,     // Щит

// -----Аттрибуты предметов ------
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

// -----Аттрибуты персонажей ------
        Wizard,     // Волшебник
        Dwarf,      // Дварф
        Tracker,    // Следопыт
        Man,        // Мужчина
        Woman,      // Женщина
        Priestess,  // Жрица

    };

    enum class Skill
    {
        Strength,       // Сила
        Agility,        // Ловкость
        Endurance,      // Выносливость
        Intelligence,   // Интеллект
        Wisdom,         // Мудрость
        Charisma,       // Харизма
        Charms,         // Чары
        Knowledge,      // Знания
        LongRange,      // Дальний бой
        ShortRange,     // Ближний бой
        Stamina,        // Стойкость
        Attention,      // Внимание
        Survival,       // Выживание
        Faith,          // Вера
        Stealth,        // Скрытность
        Diplomacy,      // Дипломатия
    };

    enum class Mastery
    {
        LightArmor,     // Легкая броня
        HeavyArmor,     // Тяжелая броня
        Weapon,         // Оружие
    };

    ActiveCardMetadata();


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
