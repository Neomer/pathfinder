//
// Created by vinokurov on 01.07.2019.
//

#include "Ogre.h"

int Ogre::getTypeId() const {
    return 411;
}

std::string_view OgreMetadata::getCardTitle() const {
    return "Огр";
}

const char *OgreMetadata::getTypeName() const {
    return "Ogre";
}

const char *OgreMetadata::getDescription() const {
    return CardMetadata::getDescription();
}

std::shared_ptr<Card> OgreMetadata::createInstance() const {
    return std::shared_ptr<Card>(new Ogre());
}

int OgreMetadata::TypeId() const {
    return 411;
}

void OgreMetadata::fillAttributes(std::vector<ActiveCardMetadata::CardAttribute> &attributes) {
    attributes.push_back(CardAttribute::Giant);
    attributes.push_back(CardAttribute::Ogre);

}
