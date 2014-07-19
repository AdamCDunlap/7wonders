class CardType;
#ifndef CARDTYPE_H
#define CARDTYPE_H
#include <functional> // For std::function
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include "Card.hpp"
#include "Player.hpp"
#include "Produce.hpp"
#include "Color.hpp"
#include "Pay.hpp"

class CardType {
public:
    CardType(std::string name,
         size_t age,
         std::vector<size_t> players,
         Color color,
         std::vector<Produce> cost,
         std::vector<std::string> chainNames,
         std::vector<Produce> produce)
        // If produce is a constant, make a function that just returns it
        : CardType(name, age, players, color, cost, chainNames,
               [produce](const Player&){return produce; })
        {
    }
    CardType(std::string name,
         size_t age,
         std::vector<size_t> players,
         Color color,
         std::vector<Produce> cost,
         std::vector<std::string> chainNames,
         std::function<std::vector<Produce> (const Player& p)> produce);

    // Accessors
    std::string getName() const { return name_; }
    size_t getAge() const { return age_; };
    std::vector<size_t> getPlayers() const { return players_; };
    Color getColor() const { return color_; }
    std::vector<Produce> getCost() const { return cost_; }
    std::vector<std::string> getChainNames() const { return chainNames_; }
    std::function<std::vector<Produce> (const Player& p) > getGetProduce() const { return getProduce_; }

    Card createCard() const;

private:
    std::string name_;
    size_t age_;
    std::vector<size_t> players_;
    Color color_;
    std::vector<Produce> cost_;
    std::vector<std::string> chainNames_;
    // Function that returns what the card produces
    std::function<std::vector<Produce> (const Player& p) > getProduce_;
};

std::ostream& operator<< (std::ostream& o, const Card& c);

#endif//CARDTYPE_H
