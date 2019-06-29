//
// Created by vinokurov on 29.06.2019.
//

#include "AmuletOfLife.h"

std::string_view AmuletOfLifeMetadata::getCardTitle() const {
    return "Амулет жизни";
}

const char *AmuletOfLifeMetadata::getTypeName() const {
    return "AmuletOfLifr";
}

const char *AmuletOfLifeMetadata::getDescription() const {
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> AmuletOfLifeMetadata::createInstance() const {
    return std::shared_ptr<Card>(new AmuletOfLife());
}

bool AmuletOfLifeMetadata::isBeginnerLevel() const {
    return true;
}

int AmuletOfLifeMetadata::TypeId() const {
    return 200;
}

void AmuletOfLifeMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes) {
    attributes.push_back(CardAttribute::Magic);
    attributes.push_back(CardAttribute::Decoration);
}

AmuletOfLife::~AmuletOfLife() {

}

int AmuletOfLife::getTypeId() const {
    return 200;
}
