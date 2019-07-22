//
// Created by vinokurov on 29.06.2019.
//

#include "AmuletOfLife.h"

std::string_view AmuletOfLifeMetadata::getCardTitle() const {
    return "Амулет жизни";
}

const char *AmuletOfLifeMetadata::getTypeName() const {
    return "AmuletOfLife";
}

const char *AmuletOfLifeMetadata::getDescription() const {
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> AmuletOfLifeMetadata::createInstance() const {
    return std::shared_ptr<Card>(new AmuletOfLife());
}

int AmuletOfLifeMetadata::TypeId() const {
    return 200;
}

void AmuletOfLifeMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes) {
    attributes.push_back(CardAttribute::BeginnerLevel);
    attributes.push_back(CardAttribute::Magic);
    attributes.push_back(CardAttribute::Decoration);
}

void AmuletOfLifeMetadata::fillCardCheckConditions(CheckableCardMetadata::CardCheckConditions &conditions)
{
    conditions.emplace_back(std::vector{ Skill::Intelligence, Skill::Charms }, 4);
}

AmuletOfLife::~AmuletOfLife() {

}

int AmuletOfLife::getTypeId() const {
    return 200;
}
