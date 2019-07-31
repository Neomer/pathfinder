//
// Created by kir on 25.07.19.
//

#ifndef GAME_SERVER_ACTION_H
#define GAME_SERVER_ACTION_H

class GameContext;

class Player;

class Action
{
public:
    virtual void execute(GameContext &gameConext, Player &player) = 0;
};


#endif //GAME_SERVER_ACTION_H
