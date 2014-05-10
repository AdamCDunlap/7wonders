#include "Player.h"
#include "infix_iterator.h"
#include "Utility.h"
#include <iostream>
#include <iterator>
#include <cassert>
using namespace std;

Player::Player(string name) :
    name_{name},
    game_{nullptr},
    militaryWinPts_{0},
    militaryLosses_{0},
    leftPlayer_{nullptr},
    rightPlayer_{nullptr},
    coins_{3}, // Start with 3 coins
    playFromDiscard_{false},
    usedFreeBuild_{false}
{
    // cards_ will eventualy contain 18 elements, so let's reserve that much
    // space in the vector
    cards_.reserve(18);
}

void Player::setLeftRightPlayers(Player* left, Player* right) {
    leftPlayer_ = left;
    rightPlayer_ = right;
}

void Player::setGame(Game* gm) {
    game_ = gm;
}

void Player::chooseWonder(std::vector<Wonder>& options) {
    cout << "What wonder do you want to have?:" << endl;
    for (size_t i=0; i<options.size(); ++i) {
        cout << i+1 << ": " << options[i];
    }

    size_t wonderNum = 0;
    while(wonderNum <= 0 || wonderNum > options.size()) {
        cin >> wonderNum;
    }
    giveWonder(options[wonderNum-1]);
    options.erase(options.begin() + wonderNum - 1);
}
void Player::giveWonder(const Wonder& w) {
    wonder_ = w;
}
void Player::chooseWonderSide() {
    cout << endl << endl << endl << endl
         << "Name: " << getName() << endl
         << "Your wonder is " << wonder_.getName()
         << ". Side A or B?" << endl;
    while(true) {
        string choice;
        cin >> choice;
        if (choice == "A" || choice == "a") {
            wonder_.setSide(true);
            return;
        } else if (choice == "B" || choice == "b") {
            wonder_.setSide(false);
            return;
        }
        cout << "Give either \"a\" or \"b\"" << endl;
    }
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
    vector<Produce> wProduce = wonder_.getProduce(*this);
    produce.insert(produce.end(), wProduce.begin(), wProduce.end());
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
    cout << "Wonder: " << wonder_ << endl;

    // Print out the cards
    cout << "You have: " << endl;
    cout << coins_ << " Coins" << endl;
    cout << cards_ << endl;
    cout << getProduce() << endl;

    // Print out hand
    cout << "You want to play: " << endl;
    {
        size_t i = 1;
        for (auto it = hand_->begin(); it != hand_->end(); ++it, ++i) {
            cout << i << ": " << *it;

            vector<Pay> payPossibilities = it->canPlay(*this);
            cout << "(";
            if (payPossibilities.size() != 0) {
                if (payPossibilities[0] == Pay{}) {
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
        cout << i++ << ": Bury";
        if (wonder_.isFull()) {
            cout << "(Wonder full)" << endl;
        } else {
            vector<Pay> payPossibilities = payForResources(*this, wonder_.getCost());
            cout << "(";
            if (payPossibilities.size() != 0) {
                if (payPossibilities[0] == Pay{}) {
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
            vector<Produce> produce = wonder_.getProduceFromNext(*this);
            copy(produce.begin(), produce.end(), infix_ostream_iterator<Produce>(cout, ", "));
            cout << endl;
        }
        cout << i++ << ": Burn" << endl;
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
        if (cardNum == hand_->size() + 1)
            nextAction = Action::BURY;
        else if (cardNum == hand_->size() + 2)
            nextAction = Action::BURN;
        else
            nextAction = Action::PLAY;

        switch(nextAction) {
        case Action::PLAY:
        {
            advance(cardIt, cardNum-1);

            // Can we?
            vector<Pay> payPossibilities = cardIt->canPlay(*this);
            moveMade = selectPayment(payPossibilities, true);
            if(moveMade) cardToPlay_ = *cardIt;
            break;
        }
        case Action::BURY:
        case Action::BURN:
        { // We're doing a special action, so ask what card
            assert(cardNum <= hand_->size() + 2);
            
            cardNum = 0;
            cout << "Which card?" << endl;
            while(cardNum <= 0 || cardNum > hand_->size()) {
                cin >> cardNum;
            }
            advance(cardIt, cardNum-1);

            //cout << "CardNum is " << cardNum << endl;
            if(nextAction == Action::BURY) {
                if (wonder_.isFull()) break;
                // Bury the card
                vector<Produce> cost = wonder_.getCost();

                vector<Pay> payPossibilities = payForResources(*this, cost);
                moveMade = selectPayment(payPossibilities, false);
                break;
            } else {
                cardToPlay_ = *cardIt;
                moveMade = true;
                break;
            }
        }
        }
    }

    // Delete the selected card
    hand_->erase(cardIt);
    // Special case for last card: either play it if we can or discard it
    if (hand_->size() == 1) {
        vector<Produce> produce = getProduce();
        if (std::find(produce.begin(), produce.end(), Produce::BUILD_SEVENTH) != produce.end()) {
            // If it's the last turn and we're allowed to build the last one, build it
            takeTurn();
        } else {
            // Discard the last card
            game_->discard(*hand_->begin());
        }
    }

}

void Player::revealAction() {
    switch(nextAction) {
    case Action::PLAY:
        // Actually play the card
        coins_ -= amountToPay_.getTotal();
        leftPlayer_->giveCoins(amountToPay_.left);
        rightPlayer_->giveCoins(amountToPay_.right);
        playCard(cardToPlay_);
        break;
    case Action::BURN:
        game_->discard(cardToPlay_);
        break;
    case Action::BURY:
    {
        vector<Produce> produce = wonder_.getProduceFromNext(*this);
        processProduce(produce);
        wonder_.build();
        break;
    }
    }
}

void Player::postTurn() {

    if (playFromDiscard_) {
        playFromDiscard_ = false; // Only get to do it once

        cout << endl << endl << endl << endl;
        cout << "Name: " << getName() << endl;
        cout << "Wonder: " << wonder_ << endl;

        // Print out the cards
        cout << "You have: " << endl;
        cout << coins_ << " Coins" << endl;
        cout << cards_ << endl;
        cout << getProduce() << endl;

        vector<Card>& discardPile = game_->getDiscard();
        if (discardPile.empty()) {
            cout << "Sorry, but discard pile is empty." << endl;
        } else {
            // Print out discard pile
            cout << "You want to play from discard (all free): " << endl;
            {
                size_t i = 1;
                for (auto it = discardPile.begin(); it != discardPile.end(); ++it, ++i) {
                    cout << i << ": " << *it;
                    cout << ": ";
                    vector<Produce> produce = it->getProduce(*this);
                    copy(produce.begin(), produce.end(), infix_ostream_iterator<Produce>(cout, ", "));
                    cout << endl;
                }
            }
            // Get what card user wants
            size_t cardNum = 0;
            while(cardNum <= 0 || cardNum > discardPile.size()) {
                cin >> cardNum;
            }
            playCard(discardPile[cardNum-1]);
            discardPile.erase(discardPile.begin() + cardNum - 1);
        }
    }
}
void Player::postAge() {
    usedFreeBuild_ = false;
}

bool Player::selectPayment(vector<Pay> payPossibilities, bool canUseFreeBuild) {
    vector<Produce> produce = getProduce();
    bool freeStructureAvailable = canUseFreeBuild && !usedFreeBuild_ && std::find(produce.begin(), produce.end(), Produce::FREE_STRUCTURE) != produce.end();

    if (!freeStructureAvailable && payPossibilities.size() == 0) {
        // Can't play it at all. Don't do anything, don't break
        cout << "You can't do that" << endl;
    } else if (payPossibilities.size() != 0 && payPossibilities[0] == Pay{}) {
        // It's free! Play it! 
        return true;
    } else {
        // Ask which option to do or none
        cout << "It's going to cost you. What do you want to do?" << endl;

        {
            size_t i = 1;
            for (auto it = payPossibilities.begin(); it != payPossibilities.end(); ++it, ++i) {
                cout << i << ": " << *it << endl;
            }
            if (freeStructureAvailable) {
                cout << i++ << ": Build for free (once per age)" << endl;
            }
            cout << i++ << ": Cancel" << endl;
        }
        size_t payNum = 0;
        while(payNum <= 0 || payNum > payPossibilities.size()+1) {
            cin >> payNum;
        }
        if (payNum <= payPossibilities.size()) { // normal
            amountToPay_ = payPossibilities[payNum-1];
            return true;
        } else if (freeStructureAvailable && payNum == payPossibilities.size() + 1) {
            // Using free build for this age
            usedFreeBuild_ = true;
            return true;
        } else {
            cout << "Choose again." << endl;
        }
    }
    return false;
}



void Player::giveHand(list<Card>* hand) {
    hand_ = hand;
}

void Player::playCard(const Card& c) {

    vector<Produce> produce = c.getProduce(*this);
    processProduce(produce);
    cards_.push_back(c);
}

void Player::processProduce(const vector<Produce>& produce) {
    // Count all the coins
    coins_ += std::count(produce.begin(), produce.end(), Produce::COIN);

    // See if we get to build from discard
    if (std::find(produce.begin(), produce.end(), Produce::FROM_DISCARD) != produce.end()) {
        playFromDiscard_ = true;
    }
}


bool Player::isLeftRawCheap() const
{
    vector<Produce> produce = getProduce();
    return std::find(produce.begin(), produce.end(), Produce::LEFT_RAW_CHEAP) != produce.end();
}
bool Player::isRightRawCheap() const
{
    vector<Produce> produce = getProduce();
    return std::find(produce.begin(), produce.end(), Produce::RIGHT_RAW_CHEAP) != produce.end();
}
bool Player::isManufacturedCheap() const
{
    vector<Produce> produce = getProduce();
    return std::find(produce.begin(), produce.end(), Produce::MANUFACTURED_CHEAP) != produce.end();
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



vector<Produce> cancelResources(const Player& player, vector<Produce> toBePaid, bool forSelf) {

    // Go through our resources
    // First remove all the ones we don't need
    // Then remove all the ones where we need exactly one of the resources
    // Then remove all where we need two, along with one of the two (it doesn't matter which)
    // Then etc until they're all gone
    vector<Produce> stillHave = player.getProduce();
    for (size_t neededResourcesTarget=0; !(stillHave.empty() || toBePaid.empty());) {
        bool recalc = false;
        //cout << "NeededResourceTarget: " << neededResourcesTarget << endl;
        for (auto ownedIt = stillHave.begin(); ownedIt != stillHave.end();) {
            //cout << "Trying to use: " << *ownedIt << endl;
            vector<Produce> simpleResources = forSelf? simplify(*ownedIt) : simplifyForBuy(*ownedIt);
            auto neededPos = toBePaid.end();
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
                recalc = true;
                break;
            }
            else {
                ++ownedIt;
            }
        }
        if (recalc) {
            neededResourcesTarget = 0;
        } else {
            ++neededResourcesTarget;
        }
    }
    return toBePaid;
}

vector<Pay> payForResources(const Player& player, vector<Produce> toBePaid)
{
    size_t coinsToBank = 0;
    //cout << endl << "Coins: " << coins << endl;

    {
        // Remove all the coins and count them
        auto newEnd = std::remove(toBePaid.begin(), toBePaid.end(), Produce::COIN);
        coinsToBank += std::distance(newEnd, toBePaid.end()); // How many coins were removed
        toBePaid.erase(newEnd, toBePaid.end());
    }
    
    toBePaid = cancelResources(player, toBePaid);

    vector<Pay> payPossibilities;

    if (toBePaid.empty()) {
        Pay pay;
        pay.bank = coinsToBank;
        payPossibilities.push_back(pay);
    } else {
        
        vector< vector< vector<Produce> > > waysToSplit = splitIntoTwo<Produce>(toBePaid.cbegin(), toBePaid.cend());
        //cout << "Ways to split: " << waysToSplit << endl;
        for (const vector< vector<Produce> >& wayToSplit : waysToSplit) {
            //cout << "Way: " << wayToSplit << endl;
            // See if the left and right players can supply the proposed resource split
            if(!cancelResources(*player.getLeftPlayer(), wayToSplit[0], false).empty()) continue;
            if(!cancelResources(*player.getRightPlayer(), wayToSplit[1], false).empty()) continue;
            //cout << "And it works!" << endl;
            

            // Then see how much we're paying them
            Pay pay;
            const vector<Produce> rawGoods = simplify(Produce::RAW_MATERIAL);
            for (const Produce& p : rawGoods) {
                pay.left += std::count(wayToSplit[0].begin(), wayToSplit[0].end(), p) * (player.isLeftRawCheap()? 1 : 2);
                pay.right += std::count(wayToSplit[1].begin(), wayToSplit[1].end(), p) * (player.isRightRawCheap()? 1 : 2);
                //cout << "Pay total is " << pay.getTotal() << endl;
            }
            //cout << "Time for manufactured" << endl;
            const vector<Produce> manufacturedGoods = simplify(Produce::MANUFACTURED_GOOD);
            for (const Produce& p : manufacturedGoods) {
                pay.left += std::count(wayToSplit[0].begin(), wayToSplit[0].end(), p) * (player.isManufacturedCheap()? 1 : 2);
                pay.right += std::count(wayToSplit[1].begin(), wayToSplit[1].end(), p) * (player.isManufacturedCheap()? 1 : 2);
                //cout << "Pay total is " << pay.getTotal() << endl;
            }
            pay.bank += coinsToBank;
            //cout << endl << pay;
            payPossibilities.push_back(pay);
        }
    }
    
    // Get rid of possibilities that are too expensive
    payPossibilities.erase(remove_if(payPossibilities.begin(), payPossibilities.end(),
            [player](const Pay& p) { return p.getTotal() > player.getCoins(); }),
        payPossibilities.end());

    //cout << endl << payPossibilities << endl;
    return payPossibilities;
}
