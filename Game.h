#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include "Card.h"
#include "Player.h"
#include "Produce.h"

class Game {
public:
    Game(std::vector<std::string> names);

    void play();
private:
    std::vector< std::vector<Card> > deck_;
    std::vector< Player > players_;
    
};

#endif//GAME_H
