//
// Created by vinokurov on 29.06.2019.
//

#include "ElderSkeletonCard.h"

std::shared_ptr<Card> ElderSkeletonCardMetadata::createInstance() const {
    return std::shared_ptr<Card>(new ElderSkeletonCard());
}

std::string_view ElderSkeletonCardMetadata::getCardTitle() const {
    return "Ветхий скелет";
}

const char *ElderSkeletonCardMetadata::getTypeName() const {
    return "ElderSkeleton";
}

int ElderSkeletonCardMetadata::TypeId() const {
    return 300;
}

void ElderSkeletonCardMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes) {
    attributes.push_back(CardAttribute::Undead);
    attributes.push_back(CardAttribute::Skeleton);
}

int ElderSkeletonCard::getTypeId() const {
    return 300;
}
