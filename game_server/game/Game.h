//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_GAME_H
#define GAME_SERVER_GAME_H

#include "cards/scenario/Scenario.h"
#include "../network/IConnectionAcceptedListener.h"
#include "../network/IConnectionClosedListener.h"
#include "../network/IDataArrivedListener.h"
#include "Player.h"
#include "SpectatorsDispatcher.h"
#include "GameContext.h"


class TcpSocket;
class TcpServer;

class Game :
        public IConnectionAcceptedListener,
        public IConnectionClosedListener,
        public IDataArrivedListener
{
public:
    explicit Game(Card *scenario, std::string_view securityKey);

    virtual ~Game();

    void onConnectionAccepted(const TcpServer *server, TcpSocket *socket) override;

    void onConnectionClosed(const TcpSocket *socket) override;

    void onDataArrived(TcpSocket *socket, nlohmann::json &json) override;

    GameContext &getContext();

    const GameContext &getContext() const;

    SpectatorsDispatcher *getSpectatorDispatcher() const;

private:
    Player *getPlayerBySocket(const TcpSocket *socket);

    GameContext _context;

    std::string _securityKey;
    TcpServer *_playerServer;
    SpectatorsDispatcher *_spectatorDispatcher;

};


#endif //GAME_SERVER_GAME_H
