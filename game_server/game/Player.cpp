//
// Created by vinokurov on 29.06.2019.
//

#include "Player.h"

const std::string &Player::getName() const {
    return _name;
}

void Player::setName(const std::string &name) {
    _name = name;
}

const std::shared_ptr<Card> &Player::getRole() const {
    return _role;
}

void Player::setRole(const std::shared_ptr<Card> &role) {
    _role = role;
}

const std::shared_ptr<Card> &Player::getLocation() const {
    return _location;
}

void Player::setLocation(const std::shared_ptr<Card> &location) {
    _location = location;
}
