//
// Created by vinokurov on 29.06.2019.
//

#include "Game.h"
#include "cards/locations/LocationCard.h"
#include "CardMetadataProvider.h"

Game::Game(Card *scenario) :
    _scenario{ scenario }
{
    _scenarioMetadata = dynamic_cast<const ScenarioMetadata *>
    (CardMetadataProvider::getInstance().getMetadata(scenario->getTypeId()));
}

void Game::run(int numPlayers) {
    std::for_each(_scenarioMetadata.getLocationsByPlayers().begin(), _scenarioMetadata.getLocationsByPlayers().end(),
            [this, numPlayers](const std::pair<int, int> &loc) {
                if (loc.first <= numPlayers) {
                    auto location = CardMetadataProvider::getInstance().getMetadata(loc.second)->createInstance();
                    dynamic_cast<LocationCard *>(location.get())->createDeck();
                    this->_locations.push_back(location);
                }
            });
}
