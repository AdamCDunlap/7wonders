#include "Card.hpp"
#include "Player.hpp"
#include "Utility.hpp"

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
        return vector<Pay>{Pay{}};
    }
    return payForResources(player, cost_);
}

std::ostream& operator<< (std::ostream& o, const Card& c) {
    o << c.getName();
    return o;
}

