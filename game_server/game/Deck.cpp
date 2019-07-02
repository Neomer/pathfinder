//
// Created by kir on 02.07.19.
//

#include <algorithm>
#include <iostream>
#include "Deck.h"
#include "cards/Card.h"

Deck::Deck()
{

}

void Deck::push(std::shared_ptr<Card> card)
{
    auto toIdx = rand() % _deck.size();
    _deck.insert(_deck.begin() + toIdx, card);
}

std::shared_ptr<Card> Deck::pop()
{
    return _deck.front();
}

void Deck::shuffle()
{
    auto shuffleCount = _deck.size();
    while (shuffleCount-- > 0) {
        auto fromIdx = rand() % _deck.size();
        auto toIdx = rand() % _deck.size();
        std::iter_swap(_deck.begin() + fromIdx, _deck.begin() + toIdx);
    }
}

void Deck::pushBack(std::shared_ptr<Card> card)
{
    _deck.push_back(card);
}
