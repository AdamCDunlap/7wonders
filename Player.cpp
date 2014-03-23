#include "Player.h"
#include "infix_iterator.h"
#include <iostream>
#include <iterator>
using namespace std;

Player::Player(string name) :
    name_{name},
    leftPlayer_{nullptr},
    rightPlayer_{nullptr},
    coins_{3} // Start with 3 coins
{
    // cards_ will eventualy contain 18 elements, so let's reserve that much
    // space in the vector
    cards_.reserve(18);
}

void Player::setLeftRightPlayers(Player* left, Player* right) {
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

void Player::giveCoins(size_t numCoins) {
    coins_ += numCoins;
}

void Player::takeTurn() {
    // Print out what cards, etc. the player has
    //cout << *this << endl;
    cout << endl << endl << endl << endl;
    cout << "Name: " << getName() << endl;

    // Print out the cards
    cout << "You have: " << endl;
    cout << coins_ << " Coins" << endl;
    for (size_t i=0; i<cards_.size(); ++i) {
        cout << cards_[i] << ", ";
    }
    cout << endl;

    // Print out hand
    cout << "You want to play: " << endl;
    {
        size_t i = 1;
        for (auto it = hand_->begin(); it != hand_->end(); ++it, ++i) {
            cout << i << ": " << *it;

            vector<Pay> payPossibilities = it->canPlay(*this);
            cout << "(";
            if (payPossibilities.size() != 0) {
                if (payPossibilities[0] == Pay{0,0,0}) {
                    cout << "free";
                } else {
                    cout << "costs: ";
                    copy(payPossibilities.begin(), payPossibilities.end(), infix_ostream_iterator<Pay>(cout, " OR "));
                }
            }
            else {
                cout << "unplayable";
            }
            cout << ")";
            cout << ": ";
            vector<Produce> produce = it->getProduce(*this);
            copy(produce.begin(), produce.end(), infix_ostream_iterator<Produce>(cout, ", "));
            cout << endl;
        }
        cout << i++ << ": Bury" << endl << i++ << ": Burn" << endl;
    }

    decltype(hand_->begin()) cardIt;
    bool moveMade = false;
    while(!moveMade) {
        cardIt = hand_->begin();
        // Get what card user wants
        size_t cardNum = 0;
        while(cardNum <= 0 || cardNum > hand_->size() + 2) { // +2 for bury and burn
            cin >> cardNum;
        }

        if (cardNum > hand_->size()) { // We're doing a special action, so ask what card
            cardNum = 0;
            cout << "Which card?" << endl;
            while(cardNum <= 0 || cardNum > hand_->size()) {
                cin >> cardNum;
            }
            advance(cardIt, cardNum-1);

            if (cardNum == hand_->size() + 1) { // Bury
                // TODO: Figure out if burying is possible
                moveMade = true;
            } else {
                coins_ += 3;
                moveMade = true;
            }
        } else { // Play the card
            advance(cardIt, cardNum-1);

            // Can we?
            vector<Pay> payPossibilities = cardIt->canPlay(*this);
            if (payPossibilities.size() == 0) {
                // Can't play it at all. Don't do anything, don't break
                cout << "You can't play that" << endl;
            } else if (payPossibilities[0] == Pay{0,0,0}) {
                // It's free! Play it! 
                cards_.push_back(*cardIt);
                moveMade = true;
            } else {
                // Ask which option to do or none
                cout << "It's going to cost you. What do you want to do?" << endl;

                {
                    size_t i = 1;
                    for (auto it = payPossibilities.begin(); it != payPossibilities.end(); ++it, ++i) {
                        cout << i << ": " << *it << endl;
                    }
                    cout << i++ << ": Cancel" << endl;
                }
                size_t payNum = 0;
                while(payNum <= 0 || payNum > payPossibilities.size()+1) {
                    cin >> payNum;
                }
                if (payNum <= payPossibilities.size()) { // if not cancelled
                    Pay pay = payPossibilities[payNum-1];
                    coins_ -= pay.getTotal();
                    leftPlayer_->giveCoins(pay.left);
                    rightPlayer_->giveCoins(pay.right);
                    cards_.push_back(*cardIt);
                    moveMade = true; // Sucessful card played!
                }
                else {
                    cout << "Choose again." << endl;
                }
                
            }
        }
    }

    // Delete the selected card
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
