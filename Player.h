class Player;

#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <list>
#include <string>
#include <iostream>
#include "Card.h"
#include "Produce.h"

class Player {
public:
    Player(std::string name);
    void setLeftRightPlayers(Player* left, Player* right);
    std::vector<Card> getCards() const ;
    std::vector<Produce> getProduce() const;
    // Returns the given vector, but with the resources this player can provide removed


    void takeTurn();
    void giveHand(std::list<Card>* hand);
    void giveCoins(size_t numCoins);


    std::string getName() const { return name_; }
    const Player* getLeftPlayer() const { return leftPlayer_; }
    const Player* getRightPlayer() const { return rightPlayer_; }
    size_t getCoins() const { return coins_; }
    size_t getMilitaryPts() const { return militaryWinPts_ - militaryLosses_; }
    size_t getMilitaryLosses() const { return militaryLosses_; }
    void militaryWin(size_t pts) { militaryWinPts_ += pts; }
    void militaryLoss() { ++militaryLosses_; }
private:

    // Takes the coins for playing the card and adds it to list of cards
    void play_card(const Card& c);

    const std::string name_;
    std::vector<Card> cards_;
    std::list<Card>* hand_;
    size_t militaryWinPts_;
    size_t militaryLosses_;
    Player* leftPlayer_;
    Player* rightPlayer_;
    size_t coins_;
};

std::ostream& operator<< (std::ostream& o, const Player& player);
std::vector<Produce> cancelResources(const Player& player, std::vector<Produce> produce);

#endif//PLAYER_H
