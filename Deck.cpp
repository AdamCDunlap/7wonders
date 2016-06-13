#include <cassert>
#include <algorithm>
#include <iterator>
#include "Deck.hpp"
#include "AllCards.hpp"

using namespace std;
vector< vector<Card> > Deck::getDeck(size_t numPlayers) {
    assert(numPlayers >= 3 && numPlayers <= 7);
    size_t cardsPerAge = 7 * numPlayers;
    size_t numGuilds = numPlayers + 2;

    // Deck is a vector of cards in each age: the 0th element is a vector
    //  of cards in age 1, etc
    vector< vector<Card> > deck(3);
    for (vector<Card>& d : deck) {
        d.reserve(cardsPerAge);
    }

    const vector<CardType> allCards = AllCards::getAllCards();

    for (const CardType& ct : allCards) {
        // Put as many cards as players less than our number
        for (size_t playerNo : ct.getPlayers()) {
            if (playerNo > numPlayers) break;
            deck[ct.getAge()-1].push_back(ct.createCard());
            //for( auto i = deck.begin(); i != deck.end(); ++i) {
            //    copy(i->begin(), i->end(), ostream_iterator<Card>(cout, ", "));
            //    cout << ":::::";
            //}
            //cout << endl;
        }
    }


    // Guilds now
    vector<CardType> guilds;
    guilds.reserve(10);
    std::copy_if(allCards.begin(), allCards.end(), back_inserter(guilds),
        [](const CardType& c){ return c.getColor() == Color::PURPLE; });

    std::random_shuffle(guilds.begin(), guilds.end());
    std::for_each(guilds.begin(), guilds.begin() + numGuilds,
        [&deck](const CardType& ct) { deck[2].push_back(ct.createCard()); });
    //std::copy(guilds.begin(), guilds.begin() + numGuilds, back_inserter(deck[2]));

    //cout << "Should be all done!" << endl;
    //for( auto i = deck.begin(); i != deck.end(); ++i) {
    //    copy(i->begin(), i->end(), ostream_iterator<Card>(cout, ", "));
    //    cout << "::::: ";
    //}
    //cout << endl;
    for (size_t i=0; i<3; ++i) {
        assert(deck[i].size() == cardsPerAge);
    }

    return deck;
}
