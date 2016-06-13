#include "Game.hpp"
#include "Deck.hpp"
#include "Utility.hpp"
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

    vector<Wonder> allWonders = AllWonders::getAllWonders();
    random_shuffle(allWonders.begin(), allWonders.end());
    for(size_t i=0; i<players_.size(); ++i) {
        players_[i].setGame(this);
        players_[i].giveWonder(allWonders[i]);
        players_[i].chooseWonderSide();
    }
}

void Game::discard(const Card& c) {
    discard_.push_back(c);
}

vector<Card>& Game::getDiscard() {
    return discard_;
}

void Game::play() {
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
                // Add size of players*turn so that it's not negative before modulus
                size_t handNo = (players_.size()*turn + playerNo + ((age % 2 != 0? 1 : -1) * turn)) % players_.size();
                players_[playerNo].giveHand(&hands[handNo]);
            }

            for (size_t i=0; i<Player::turnRounds; ++i) {
                for (size_t playerNo = 0; playerNo < players_.size(); ++playerNo) {
                    players_[playerNo].takeTurn(i);
                }
            }
        }
        //for (size_t playerNo = 0; playerNo < players_.size(); ++playerNo) {
        //    players_[playerNo].revealAction();
        //}
        for (size_t playerNo = 0; playerNo < players_.size(); ++playerNo) {
            players_[playerNo].postAge();
        }

        // Military time
        for (Player& p : players_) {
            const vector<Produce> thisProduce  = p.getProduce();
            const vector< vector<Produce> > sideProduce{
                                  p.getLeftPlayer() ->getProduce(),
                                  p.getRightPlayer()->getProduce()};
            size_t thisMilitary  = std::count(thisProduce.begin(),  thisProduce.end(),  Produce::SHIELD);
            for (const vector<Produce>& s : sideProduce) {
                int militaryDiff = thisMilitary - std::count(s.begin(), s.end(), Produce::SHIELD);
                if (militaryDiff > 0) {
                    // We won!
                    p.militaryWin(2 * age + 1);
                } else if (militaryDiff < 0) {
                    p.militaryLoss();
                }
            }
        }
    }

    // Count up the points and determine a winner
    int winningPoints = INT_MIN;
    vector<const Player*> winners;
    for (const Player& p : players_) {
        const vector<Produce> finalProduce = p.getProduce();
        size_t gears     = std::count(finalProduce.begin(), finalProduce.end(), Produce::GEAR),
               tablets   = std::count(finalProduce.begin(), finalProduce.end(), Produce::TABLET),
               compasses = std::count(finalProduce.begin(), finalProduce.end(), Produce::COMPASS);
        size_t sciencePts = 0;
        for (size_t i=std::count(finalProduce.begin(), finalProduce.end(), Produce::ANY_SCIENCE); i>0; --i) {

            // TODO: This isn't right... it only works for 1 ANY_SCIENCE


            ++gears;
            size_t pts = std::min({gears, tablets, compasses})*7 + gears*gears + tablets*tablets + compasses*compasses;
            if(pts > sciencePts) sciencePts = pts;
            --gears;
            ++tablets;
            pts = std::min({gears, tablets, compasses})*7 + gears*gears + tablets*tablets + compasses*compasses;
            if(pts > sciencePts) sciencePts = pts;
            --tablets;
            ++compasses;
            pts = std::min({gears, tablets, compasses})*7 + gears*gears + tablets*tablets + compasses*compasses;
            if(pts > sciencePts) sciencePts = pts;
            --compasses;
        }
        int points = std::count(finalProduce.begin(), finalProduce.end(), Produce::VP)
                     + p.getMilitaryPts()
                     + p.getCoins() / 3
                     + sciencePts;
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
