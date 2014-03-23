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

vector<Pay> Card::canPlay(const Player& player) const {

    // First, check for chains
    vector<Card> cards = player.getCards();
    //if (any_of(cards.begin(), cards.end(),
    //        [this](const Card& c) { return c.getName() == chainName_; })) {

    // if any of the cards match any of our chain names
    if(std::find_first_of(cards.begin(), cards.end(), chainNames_.begin(), chainNames_.end(),
           [](const Card& c, const string& n){return c.getName() == n;}
        ) != cards.end()) {
        return vector<Pay>{Pay{0,0,0}};
    }

    Pay coins{0,0,0};
    //cout << endl << "Coins: " << coins << endl;

    // Make two lists of what we need and what we have, and remove matching
    // elements.
    vector<Produce> toBePaid = cost_;
    vector<Produce> stillHave = player.getProduce();
    {
        // Remove all the coins and count them
        auto newEnd = std::remove(toBePaid.begin(), toBePaid.end(), Produce::COIN);
        coins.bank += std::distance(newEnd, toBePaid.end()); // How many coins were removed
        toBePaid.erase(newEnd, toBePaid.end());
    }
    
    // Go through our resources
    // First remove all the ones we don't need
    // Then remove all the ones where we need exactly one of the resources
    // Then remove all where we need two, along with one of the two (it doesn't matter which)
    // Then etc until they're all gone
    for (size_t neededResourcesTarget=0; !(stillHave.empty() || toBePaid.empty());) {
        bool recalc = false;
        //cout << "NeededResourceTarget: " << neededResourcesTarget << endl;
        for (auto ownedIt = stillHave.begin(); ownedIt != stillHave.end();) {
            //cout << "Trying to use: " << *ownedIt << endl;
            vector<Produce> simpleResources = simplify(*ownedIt);
            decltype(toBePaid.begin()) neededPos = toBePaid.end();
            size_t neededResources = 0;
            for (const Produce& p : simpleResources) {
                auto pos = find(toBePaid.begin(), toBePaid.end(), p);
                if(pos != toBePaid.end()) {
                    ++neededResources;
                    neededPos = pos;
                }
            }
            if (neededResources == neededResourcesTarget) {
                stillHave.erase(ownedIt);
                if (neededPos != toBePaid.end()) toBePaid.erase(neededPos);
                // Now recalculate everything
                neededResourcesTarget = 0;
                recalc = true;
                break;
            }
            else {
                ++ownedIt;
            }
        }
        if (!recalc) {
            ++neededResourcesTarget;
        }
    }


    //cout << "Coins: " << coins << endl;
    if (toBePaid.empty()) {
        return vector<Pay>{coins};
    }

    // TODO: Buy resources
    return vector<Pay>{}; // No options
}

std::ostream& operator<< (std::ostream& o, const Card& c) {
    o << c.getName();
    return o;
}

