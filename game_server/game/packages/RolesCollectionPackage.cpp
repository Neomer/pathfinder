//
// Created by vinokurov on 08.07.2019.
//

#include "RolesCollectionPackage.h"

uint32_t RolesCollectionPackage::getEventId() const {
    return 1;
}

RolesCollectionPackage::RolesCollectionPackage(const std::vector<const CardMetadata *> &cards) :
        CardCollectionPackage(cards)
{

}
