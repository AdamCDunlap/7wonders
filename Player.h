class Player;

#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <list>
#include <string>
#include <iostream>
#include "Card.h"
#include "Pay.h"
#include "Produce.h"
#include "Wonder.h"
#include "Game.h"

class Player {
public:
    Player(std::string name);
    void setLeftRightPlayers(Player* left, Player* right);
    void setGame(Game* gm);

    void chooseWonder(std::vector<Wonder>& options);
    void giveWonder(const Wonder& w);
    void chooseWonderSide();

    void takeTurn();
    void postTurn(); // Called after everyone has played a card
    void revealAction();
    void postAge(); // Called after the age is done
    void giveHand(std::list<Card>* hand);
    void giveCoins(size_t numCoins);

    void militaryWin(size_t pts) { militaryWinPts_ += pts; }
    void militaryLoss() { ++militaryLosses_; }

    std::vector<Card> getCards() const ;
    std::vector<Produce> getProduce() const;
    std::string getName() const { return name_; }
    const Player* getLeftPlayer() const { return leftPlayer_; }
    const Player* getRightPlayer() const { return rightPlayer_; }
    size_t getCoins() const { return coins_; }
    size_t getMilitaryPts() const { return militaryWinPts_ - militaryLosses_; }
    size_t getMilitaryLosses() const { return militaryLosses_; }
    bool isLeftRawCheap() const;
    bool isRightRawCheap() const;
    bool isManufacturedCheap() const;
private:

    // Takes the coins for playing the card and adds it to list of cards
    void playCard(const Card& c);
    bool selectPayment(std::vector<Pay> payPossibilities, bool canUseFreeBuild);
    void processProduce(const std::vector<Produce>& produce);

    const std::string name_;
    Wonder wonder_;
    Game* game_;
    std::vector<Card> cards_;
    std::list<Card>* hand_;
    size_t militaryWinPts_;
    size_t militaryLosses_;
    Player* leftPlayer_;
    Player* rightPlayer_;
    size_t coins_;

    bool playFromDiscard_;
    bool usedFreeBuild_;

    // Stuff to know what to do at end of turn
    enum class Action { BURY, BURN, PLAY } nextAction;
    Card cardToPlay_;
    Pay amountToPay_;
};

std::ostream& operator<< (std::ostream& o, const Player& player);
std::vector<Produce> cancelResources(const Player& player, std::vector<Produce> produce, bool forSelf = true);
std::vector<Pay> payForResources(const Player& player, std::vector<Produce> toBePaid);

#endif//PLAYER_H
