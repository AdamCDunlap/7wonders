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

Pay Card::canPlay(const Player& player) const {

    // First, check for chains
    vector<Card> cards = player.getCards();
    //if (any_of(cards.begin(), cards.end(),
    //        [this](const Card& c) { return c.getName() == chainName_; })) {

    // if any of the cards match any of our chain names
    if(std::find_first_of(cards.begin(), cards.end(), chainNames_.begin(), chainNames_.end(),
           [](const Card& c, const string& n){return c.getName() == n;}
        ) != cards.end()) {
        return Pay{0,0,0};
    }

    // Make two lists of what we need and what we have, and remove matching
    // elements.
    vector<Produce> toBePaid = cost_;
    vector<Produce> stillHave = player.getProduce();
    // Sort them
    //sort(toBePaid.begin(), toBePaid.end());
    //sort(stillHave.begin(), stillHaver.end());
    //// Take the set difference to remove all the resources we have
    //set_difference(
    
    for (auto i = toBePaid.begin(), end = toBePaid.end(); i != end; ++i) {
        auto pos = find(stillHave.begin(), stillHave.end(), *i);
        if (pos != stillHave.end()) {
            stillHave.erase(pos);
            toBePaid.erase(i);
        }
    }
    // TODO: Deal with OR resources
    if (toBePaid.empty()) {
        return Pay{0, 0, 0};
    }

    // TODO: Buy resources
    return Pay{-1, -1, -1};
}

std::ostream& operator<< (std::ostream& o, const Card& c) {
    o << c.getName();
    return o;
}

