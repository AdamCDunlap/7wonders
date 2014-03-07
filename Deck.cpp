#include <cassert>
#include <algorithm>
#include "Deck.h"
#include "AllCards.h"

using namespace std;
vector< vector<Card> > Deck::getDeck(size_t numPlayers) {
    assert(numPlayers >= 3);
    size_t cardsPerAge = 7 * numPlayers;

    // Deck is a vector of cards in each age: the 0th element is a vector
    //  of cards in age 1, etc
    vector< vector<Card> > deck(3);
    vector<Card> allCards = AllCards::getAllCards();

    for (size_t age = 1; age <= 3; ++age) {

        std::copy_if(allCards.begin(), allCards.end(), deck[age].begin(),
            [numPlayers, age](const Card& c){
                vector<size_t> ages = c.getAges();
                vector<
                return std::find(
                       c.getPlayers() <= numPlayers; }
        );
    }

    return deck;
}
