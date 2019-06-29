//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_CARDMETADATAPROVIDER_H
#define GAME_SERVER_CARDMETADATAPROVIDER_H


#include <vector>
#include <functional>

class CardMetadata;

class CardMetadataProvider
{
public:
    static CardMetadataProvider &getInstance();

    void init();

    const CardMetadata *getMetadata(int typeId) const;

    std::vector<const CardMetadata *> getMetadata(std::function<bool(const CardMetadata *metadata)> comparator) const;

    void registerMetadata(CardMetadata *metadata);

private:
    CardMetadataProvider();

    ~CardMetadataProvider() = default;

    std::vector<CardMetadata *> _metadataVector;
};



#endif //GAME_SERVER_CARDMETADATAPROVIDER_H
