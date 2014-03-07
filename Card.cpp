#include "Card.h"

using namespace std;

Card::Card(const string name,
           age,
           vector<size_t> players,
           Color color,
           const vector<Produce> cost,
           const string chainName,
           const function<vector<Produce> (const Player& p)> getProduce)
    : name_{name},
      age_{age},
      players_{players},
      color_{color},
      cost_{cost},
      chainName_{chainName},
      getProduce_{getProduce}
    {
    
}

//Card& Card::operator=(const Card& c) {
//    if (this != &c) {
//        name_ = c.name_;
//        cost_ = c.cost_;
//        chainName_ = c.chainName_;
//        getProduce_ = c.getProduce_;
//    }
//    return *this;
//}

//int Card::getVP() {
//    vector<Produce> produce = getProduce_();
//    vector<Produce> VPs;
//    copy_if(produce.begin(), produce.end(), VPs.begin(), 
//        [](const Produce& p) { return p == Produce::VP; });
//    return VPs.size();
//}

 vector<Produce> Card::getProduce(const Player& p) const {
    return getProduce_(p);
}

Pay Card::canPlay(const Player& player) const {

    // First, check for chains
    vector<Card> cards = player.getCards();
    if (any_of(cards.begin(), cards.end(),
            [this](const Card& c) { return c.getName() == chainName_; })) {
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

    return Pay{-1, -1, -1};
}

std::ostream& operator<< (std::ostream& o, const Card& c) {
    o << c.getName();
    return o;
}

