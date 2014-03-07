#ifndef DECK_H
#define DECK_H
#include <vector>
#include "Card.h"

namespace Deck {
    std::vector< std::vector<Card> > getDeck(size_t numPlayers);
}

#endif//DECK_H
