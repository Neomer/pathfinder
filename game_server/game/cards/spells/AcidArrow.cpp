//
// Created by kir on 03.07.19.
//

#include "AcidArrow.h"

int AcidArrow::getTypeId() const
{
    return 1;
}

std::string_view AcidArrowMetadata::getCardTitle() const
{
    return "Кислотная стрела";
}

const char *AcidArrowMetadata::getTypeName() const
{
    return "AcidArrow";
}

const char *AcidArrowMetadata::getDescription() const
{
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> AcidArrowMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new AcidArrow());
}

int AcidArrowMetadata::TypeId() const
{
    return 1;
}

void AcidArrowMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes)
{
    attributes.push_back(CardAttribute::AdvancedLevel);
    attributes.push_back(CardAttribute::Magic);
    attributes.push_back(CardAttribute::Charms);
    attributes.push_back(CardAttribute::Attack);
    attributes.push_back(CardAttribute::Acid);
}

void AcidArrowMetadata::fillCardsTakenConditions(HandTakableCardMetadata::CardTakenConditions &conditions)
{
    conditions.emplace_back(std::vector{ Skill::Intelligence, Skill::Charms }, 4);
}
