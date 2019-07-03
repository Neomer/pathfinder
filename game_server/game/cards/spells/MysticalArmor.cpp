//
// Created by kir on 03.07.19.
//

#include "MysticalArmor.h"

int MysticalArmor::getTypeId() const
{
    return 3;
}

std::string_view MysticalArmorMetadata::getCardTitle() const
{
    return "Мистическая броня";
}

const char *MysticalArmorMetadata::getTypeName() const
{
    return "MysticalArmor";
}

const char *MysticalArmorMetadata::getDescription() const
{
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> MysticalArmorMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new MysticalArmor());
}

int MysticalArmorMetadata::TypeId() const
{
    return 3;
}

void MysticalArmorMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes)
{
    attributes.push_back(CardAttribute::BeginnerLevel);
    attributes.push_back(CardAttribute::Magic);
    attributes.push_back(CardAttribute::Charms);
}

void MysticalArmorMetadata::fillCardsTakenConditions(HandTakableCardMetadata::CardTakenConditions &conditions)
{
    conditions.emplace_back(std::vector{ Skill::Intelligence, Skill::Charms }, 4);
}
