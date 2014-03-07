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
         std::vector<size_t> ages,
         size_t age,
         Color color,
         std::vector<Produce> cost,
         std::string chainName,
         std::vector<Produce> produce)
        // If produce is a constant, make a function that just returns it
        : Card(name, age, players, color, cost, chainName,
               [produce](const Player&){return produce; })
        {
    }
    Card(std::string name,
         size_t age,
         std::vector<size_t> players,
         Color color,
         std::vector<Produce> cost,
         std::string chainName,
         std::function<std::vector<Produce> (const Player& p)> produce);

    // Create no-args constructor for testing
    Card() : Card("Empty Card", 1, {3},
                  Color::BROWN, std::vector<Produce>{}, "",
                  std::vector<Produce>{}) {
    }

    // Returns what the card gives the given player
    std::vector<Produce> getProduce(const Player& p) const;

    // Returns if this card can be played for given player
    Pay canPlay(const Player& p) const;
 
    // Accessors
    std::string getName() const { return name_; }
    std::vector<size_t> getAges() const { return ages_; }
    std::vector<size_t> getPlayers() const { return players_; }
    Color getColor() const { return color_; }
    std::vector<Produce> getCost() const { return cost_; }


private:
    std::string name_;
    size_t age_;
    std::vector<size_t> players_;
    Color color_;
    std::vector<Produce> cost_;
    std::string chainName_;
    // Function that returns what the card produces
    std::function<std::vector<Produce> (const Player& p) > getProduce_;
};

std::ostream& operator<< (std::ostream& o, const Card& c);

#endif//CARD_H
