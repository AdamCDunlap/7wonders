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


    void takeTurn();
    void giveHand(std::list<Card>* hand);
    void giveCoins(size_t numCoins);

    std::string getName() const { return name_; }
    const Player* getLeftPlayer() const { return leftPlayer_; }
    const Player* getRightPlayer() const { return rightPlayer_; }
    size_t getCoins() const { return coins_; }
private:
    const std::string name_;
    std::vector<Card> cards_;
    std::list<Card>* hand_;
    Player* leftPlayer_;
    Player* rightPlayer_;
    size_t coins_;
};

std::ostream& operator<< (std::ostream& o, const Player& player);

#endif//PLAYER_H
