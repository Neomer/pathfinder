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
#include "../network/TcpSocket.h"

class Player {
public:
    Player(TcpSocket *socket);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::shared_ptr<Card> &getRole() const;

    void setRole(const std::shared_ptr<Card> &role);

    const std::shared_ptr<Card> &getLocation() const;

    void setLocation(const std::shared_ptr<Card> &location);

    void createUserDeck();

    TcpSocket *getTransportPipe();

    const TcpSocket *getTransportPipeConst() const;

private:
    TcpSocket *_socket;
    Deck _activeDeck, _usedDeck;
    std::string _name;
    std::shared_ptr<Card> _role;
    std::shared_ptr<Card> _location;
    const RoleCardMetadata *_roleMetadata;
};


#endif //GAME_SERVER_PLAYER_H
