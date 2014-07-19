#ifndef DECK_H
#define DECK_H
#include <vector>
#include "Card.hpp"
#include "CardType.hpp"

namespace Deck {
    std::vector< std::vector<Card> > getDeck(size_t numPlayers);
}

#endif//DECK_H
