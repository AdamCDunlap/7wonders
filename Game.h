class Game;
#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include "Card.h"
#include "Player.h"
#include "Produce.h"
#include "Wonder.h"
#include "AllWonders.h"

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
