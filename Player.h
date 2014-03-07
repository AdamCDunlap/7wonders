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
    void setLeftRightPlayers(const Player* left, const Player* right);
    std::vector<Card> getCards() const ;
    std::vector<Produce> getProduce() const;

    void takeTurn();
    void giveHand(std::list<Card>* hand);
    std::string getName() const { return name_; }
private:
    const std::string name_;
    std::vector<Card> cards_;
    std::list<Card>* hand_;
    const Player* leftPlayer_;
    const Player* rightPlayer_;
};

std::ostream& operator<< (std::ostream& o, const Player& player);

#endif//PLAYER_H
