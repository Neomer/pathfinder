//
// Created by kir on 02.07.19.
//

#ifndef GAME_SERVER_DECK_H
#define GAME_SERVER_DECK_H

#include <memory>
#include <vector>
#include <bits/shared_ptr.h>

class Card;

class Deck
{
public:
    Deck();

    void push(std::shared_ptr<Card> card);

    void pushBack(std::shared_ptr<Card> card);

    std::shared_ptr<Card> pop();

    void shuffle();

private:
    std::vector<std::shared_ptr<Card>> _deck;
};


#endif //GAME_SERVER_DECK_H
