#include "Game.h"
#include "Deck.h"
#include <ctime>
#include <list>
#include <algorithm>
#include <climits>

using namespace std;

Game::Game(vector<string> names) {
    // We already know how many players there will be, so reserve it
    players_.reserve(names.size());
    // Construct players_ with the names given
    std::copy( names.begin(), names.end(), back_inserter(players_) );

    // Tell each player who's on their sides
    // Start with the edge cases
    players_[0]
            .setLeftRightPlayers(&players_[1],
                                 &players_[players_.size() - 1]);
    players_[players_.size() - 1]
            .setLeftRightPlayers(&players_[0],
                                 &players_[players_.size() - 2]);
    for (size_t i = 1; i < players_.size() - 1; ++i) {
        players_[i].setLeftRightPlayers(&players_[i+1], &players_[i-1]);
    }

    deck_ = Deck::getDeck(players_.size());
}

void Game::play() {
    srand ( unsigned ( std::time(0) ) );
    for (int age = 0; age < 3; ++age) {

        // Make the hands for this age 
        random_shuffle(deck_[age].begin(), deck_[age].end());
        vector< list<Card> > hands;
        hands.reserve(players_.size());
        for (auto it = deck_[age].begin(); it != deck_[age].end(); it += 7) {
            hands.push_back( list<Card>(&it[0], &it[7]) );
        }

        // Take turns
        for (int turn = 0; turn < 6; ++turn) {
            for (size_t playerNo = 0; playerNo < players_.size(); ++playerNo) {

                // Give the player a hand, which is shifted each turn
                size_t handNo = (playerNo + turn) % players_.size();
                players_[playerNo].giveHand(&hands[handNo]);

                players_[playerNo].takeTurn();
            }
        }
    }

    // Count up the points and determine a winner
    int winningPoints = INT_MIN;
    vector<const Player*> winners;
    for (const Player& p : players_) {
        const vector<Produce> finalProduce = p.getProduce();
        int points = std::count(finalProduce.begin(), finalProduce.end(), Produce::VP)
                   - std::count(finalProduce.begin(), finalProduce.end(), Produce::MILITARY_LOSS);
        cout << p << " got " << points << " points!" << endl;
        if (points == winningPoints) {
            winners.push_back(&p);
        } else if (points > winningPoints) {
            winners.clear();
            winners.push_back(&p);
            winningPoints = points;
        }
        
        //int points = filter([](const Produce& r){ return r == Produce::VP; }, finalProduce).size();
    }
    if (winners.size() > 1) {
        cout << "Players ";
        for (size_t i=0; i < winners.size() - 2; ++i) {
            cout << *winners[i] << " and ";
        }
        cout << *winners[winners.size() - 1];
        cout << " tied!";
    } else {
        cout << *winners[0] << " won!" << endl;
    }

}
