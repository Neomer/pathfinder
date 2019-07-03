//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_PLAYER_H
#define GAME_SERVER_PLAYER_H

#include <memory>
#include <string>
#include <string_view>
#include "cards/RoleCard.h"
#include "Deck.h"

class Player {
public:
    Player(std::string_view name);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::shared_ptr<Card> &getRole() const;

    void setRole(const std::shared_ptr<Card> &role);

    void createUserDeck();

private:
    Deck _activeDeck, _usedDeck;
    std::string _name;
    std::shared_ptr<Card> _role;
    const RoleCardMetadata *_roleMetadata;
};


#endif //GAME_SERVER_PLAYER_H
