//
// Created by vinokurov on 08.07.2019.
//

#ifndef GAME_SERVER_LOCATIONSCOLLECTIONPACKAGE_H
#define GAME_SERVER_LOCATIONSCOLLECTIONPACKAGE_H

#include "CardCollectionPackage.h"

class LocationsCollectionPackage : public CardCollectionPackage
{
public:
    LocationsCollectionPackage(const std::vector<const CardMetadata *> &cards);

    uint32_t getEventId() const override;
};


#endif //GAME_SERVER_LOCATIONSCOLLECTIONPACKAGE_H
