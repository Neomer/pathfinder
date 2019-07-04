//
// Created by vinokurov on 29.06.2019.
//

#include "../Logger.h"
#include "Player.h"
#include "cards/RoleCard.h"
#include "CardMetadataProvider.h"
#include "cards/HandTakableCardMetadata.h"

using namespace std::string_literals;

Player::Player(TcpSocket *socket) :
    _socket{ socket },
    _role{ nullptr }
{

}

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
    if (role.get() == nullptr) {
        throw std::logic_error("Null-pointer exception");
    }
    _role = role;
    _roleMetadata = dynamic_cast<const RoleCardMetadata *>(role->getMetadata());
    if (_roleMetadata == nullptr || _roleMetadata->getCardType() != CardMetadata::CardType::Role) {
        throw std::logic_error("This card isn't a role!");
    }
}

void Player::createUserDeck() {
    if (_role.get() == nullptr) {
        throw std::logic_error("User don't select a role!");
    }
    Logger::getInstace().log("Start generating player's active deck...");
    auto startHandCardTypes = _roleMetadata->getStartHandCardTypes();
    for (auto &cardType : startHandCardTypes) {
        auto availableCards = CardMetadataProvider::getInstance().getMetadata(
                [cardType](const CardMetadata *metadata) -> bool {
                    auto handTakable = dynamic_cast<const HandTakableCardMetadata *>(metadata);
                    return handTakable != nullptr && handTakable->isBeginnerLevel() && handTakable->getCardType() == cardType.first;
                });
        if (availableCards.empty()) {
            continue;
        }
        while (cardType.second--) {
            auto selectedCardMetadata = availableCards.at(rand() % availableCards.size());
            _activeDeck.push(selectedCardMetadata->createInstance());
        }
    }
    Logger::getInstace().log("Player's deck ready!");
}

TcpSocket *Player::getTransportPipe()
{
    return _socket;
}

const TcpSocket *Player::getTransportPipeConst() const
{
    return _socket;
}

