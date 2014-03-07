#include "Player.h"
#include <iostream>
#include <iterator>
using namespace std;

Player::Player(string name) :
    name_{name},
    leftPlayer_{nullptr},
    rightPlayer_{nullptr} {
    // cards_ will eventualy contain 18 elements, so let's reserve that much
    // space in the vector
    cards_.reserve(18);
}

void Player::setLeftRightPlayers(const Player* left, const Player* right) {
    leftPlayer_ = left;
    rightPlayer_ = right;
}

vector<Card> Player::getCards() const {
    return cards_;
}

vector<Produce> Player::getProduce() const {
    // Concatenate produce of each card
    vector<Produce> produce;
    for (const Card& c : cards_) {
        vector<Produce> cProduce = c.getProduce(*this);
        produce.insert(produce.end(), cProduce.begin(), cProduce.end());
    }
    return produce;
}

void Player::takeTurn() {
    // Print out what cards, etc. the player has
    //cout << *this << endl;
    cout << endl << endl << endl << endl;
    cout << "Name: " << getName() << endl;

    // Print out the cards
    cout << "You have: " << endl;
    for (size_t i=0; i<cards_.size(); ++i) {
        cout << cards_[i] << ", ";
    }
    cout << endl;

    // Print out hand
    cout << "You want to play: " << endl;
    {
        auto it = hand_-> begin();
        for (size_t i = 1; it != hand_->end(); ++it, ++i) {
            cout << i << ": " << *it << ", ";
        }
    }
    cout << endl;

    // Figure out what card to play
    size_t cardNum = 0;
    while(cardNum == 0 || cardNum > hand_->size()) {
        cin >> cardNum;
    }

    // Iterate to the card specified
    auto cardIt = hand_->begin();
    for(size_t i = 0; i < cardNum-1; ++i) {
        ++cardIt;
    }
    // Add the card to our list of cards
    cards_.push_back(*cardIt);

    hand_->erase(cardIt);
}

void Player::giveHand(list<Card>* hand) {
    hand_ = hand;
}

std::ostream& operator<< (std::ostream& o, const Player& p) {
    o << p.getName();


    //o << "Cards: ";
    //const vector<Card> cards = p.getCards();
    //for (const Card& c : cards) {
    //    o << c << ", ";
    //}
    //o << endl;
    ////copy(cards.begin(), cards.end(), ostream_iterator<Card>(o, ", "));


    //o << "Produce: ";
    //const vector<Produce> produce = p.getProduce();
    //for (const Produce& p : produce) {
    //    o << p << ", ";
    //}
    //o << endl;


    ////copy(produce.begin(), produce.end(), ostream_iterator<Produce>(o, ", "));
    //o << "End of Player" << endl;
    return o;
}
