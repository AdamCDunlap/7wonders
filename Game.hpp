class Game;
#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include "Card.hpp"
#include "Player.hpp"
#include "Produce.hpp"
#include "Wonder.hpp"
#include "AllWonders.hpp"

class Game {
public:
    Game(std::vector<std::string> names);

    void play();
    void discard(const Card& c);
    std::vector<Card>& getDiscard();
private:
    std::vector< std::vector<Card> > deck_;
    std::vector< Player > players_;
    std::vector< Card > discard_;

};

#endif//GAME_H
