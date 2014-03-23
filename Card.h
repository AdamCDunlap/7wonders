class Card;
#ifndef CARD_H
#define CARD_H
#include <functional> // For std::function
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include "Player.h"
#include "Produce.h"
#include "Color.h"
#include "Pay.h"

class Card {
public:
    Card(std::string name,
         Color color,
         std::vector<Produce> cost,
         std::vector<std::string> chainNames,
         std::function<std::vector<Produce> (const Player& p)> produce);

    // Returns what the card gives the given player
    std::vector<Produce> getProduce(const Player& p) const;

    // Returns all possible options for paying for card
    std::vector<Pay> canPlay(const Player& p) const;
 
    // Accessors
    std::string getName() const { return name_; }
    Color getColor() const { return color_; }
    std::vector<Produce> getCost() const { return cost_; }


private:
    std::string name_;
    Color color_;
    std::vector<Produce> cost_;
    std::vector<std::string> chainNames_;
    // Function that returns what the card produces
    std::function<std::vector<Produce> (const Player& p) > getProduce_;
};

std::ostream& operator<< (std::ostream& o, const Card& c);

#endif//CARD_H
