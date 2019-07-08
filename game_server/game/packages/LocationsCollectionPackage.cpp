//
// Created by vinokurov on 08.07.2019.
//

#include "LocationsCollectionPackage.h"

uint32_t LocationsCollectionPackage::getEventId() const {
    return 4;
}

LocationsCollectionPackage::LocationsCollectionPackage(const std::vector<const CardMetadata *> &cards)
        : CardCollectionPackage(cards)
{

}
