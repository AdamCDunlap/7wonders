#include "Card.h"

using namespace std;

Card::Card(const string name,
           Color color,
           const vector<Produce> cost,
           const vector<string> chainNames,
           const function<vector<Produce> (const Player& p)> getProduce)
    : name_{name},
      color_{color},
      cost_{cost},
      chainNames_{chainNames},
      getProduce_{getProduce}
    {
    
}

 vector<Produce> Card::getProduce(const Player& p) const {
    return getProduce_(p);
}

template<typename T>
static vector< vector< vector<T> > > splitIntoTwo(typename vector<T>::const_iterator begin, typename vector<T>::const_iterator end) {
    // Start with one option: two empty paritions
    vector< vector< vector<T> > > ret{ vector< vector<T> >{vector<T>{}, vector<T>{}} };
    if (begin != end) {
        // outer: list of ways to do it
        // middle: two sides
        // inner: produce in each side
        //
        // for each in outer
        // add two to new, one with it in the first and one with it in the second
        
        const vector< vector< vector<T> > > payRest = splitIntoTwo<T>(begin+1, end);
        for(vector< vector<T> > payRight : payRest) {
            vector< vector<T> > payLeft = payRight;
            payRight[0].push_back(*begin);
            payLeft[1].push_back(*begin);
            ret.push_back(payRight);
            ret.push_back(payLeft);
        }
    }
    return ret;
}

vector<Pay> Card::canPlay(const Player& player) const {

    vector<Card> cards = player.getCards();
    // Make sure player doesn't already have this card
    
    if (any_of(cards.begin(), cards.end(),
            [this](const Card& c) { return c.getName() == name_; })) {
        // If player already has card of the same name, we can't play it
        return vector<Pay>{};
    }

    // Check for chains
    // if any of the cards match any of our chain names
    if(std::find_first_of(cards.begin(), cards.end(), chainNames_.begin(), chainNames_.end(),
           [](const Card& c, const string& n){return c.getName() == n;}
        ) != cards.end()) {
        return vector<Pay>{Pay{0,0,0}};
    }

    size_t coinsToBank = 0;
    //cout << endl << "Coins: " << coins << endl;

    // Make two lists of what we need and what we have, and remove matching
    // elements.
    vector<Produce> toBePaid = cost_;
    {
        // Remove all the coins and count them
        auto newEnd = std::remove(toBePaid.begin(), toBePaid.end(), Produce::COIN);
        coinsToBank += std::distance(newEnd, toBePaid.end()); // How many coins were removed
        toBePaid.erase(newEnd, toBePaid.end());
    }
    
    toBePaid = cancelResources(player, toBePaid);

    vector<Pay> payPossibilities;

    if (toBePaid.empty()) {
        payPossibilities.push_back(Pay{0,0,0});
    } else {
        
        vector< vector< vector<Produce> > > waysToSplit = splitIntoTwo<Produce>(toBePaid.cbegin(), toBePaid.cend());
        for (const vector< vector<Produce> >& wayToSplit : waysToSplit) {
            
        }
        
        vector<Produce> ourProduce = player.getProduce();
        if (std::find(ourProduce.begin(), ourProduce.end(), Produce::LEFT_RAW_CHEAP) != ourProduce.end()) {
        }
    }
    
    // Get rid of possibilities that are too expensive
    payPossibilities.erase(remove_if(payPossibilities.begin(), payPossibilities.end(),
            [player](const Pay& p) { return p.getTotal() > player.getCoins(); }),
        payPossibilities.end());

    // If we've paid for everything, YAY
    if (toBePaid.empty()) {
        for (Pay& p : payPossibilities) {
            p.bank += coinsToBank;
        }
        return payPossibilities;
    }

    return vector<Pay>{}; // No options
}

std::ostream& operator<< (std::ostream& o, const Card& c) {
    o << c.getName();
    return o;
}

