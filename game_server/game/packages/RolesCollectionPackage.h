//
// Created by vinokurov on 08.07.2019.
//

#ifndef GAME_SERVER_ROLESCOLLECTIONPACKAGE_H
#define GAME_SERVER_ROLESCOLLECTIONPACKAGE_H

#include "CardCollectionPackage.h"

class RolesCollectionPackage : public CardCollectionPackage
{
public:
    RolesCollectionPackage(const std::vector<const CardMetadata *> &cards);

    uint32_t getEventId() const override;
};


#endif //GAME_SERVER_ROLESCOLLECTIONPACKAGE_H
