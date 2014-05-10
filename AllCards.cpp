
#include "AllCards.h"
using namespace std;

std::vector<CardType> AllCards::getAllCards() {
    vector<CardType> cards;

    cards.push_back(CardType{
        "Lumber Yard",
        1,
        vector<size_t>{3, 4},
        Color::BROWN,
        vector<Produce>{},
        vector<string>{},
        vector<Produce>{Produce::WOOD}
    });
    cards.push_back(CardType{
        "Stone Pit",
        1,
        vector<size_t>{3, 5},
        Color::BROWN,
        vector<Produce>{},
        vector<string>{},
        vector<Produce>{Produce::STONE}
    });
    cards.push_back(CardType{
        "Clay Pool",
        1,
        vector<size_t>{3, 5},
        Color::BROWN,
        vector<Produce>{},
        vector<string>{},
        vector<Produce>{Produce::BRICK}
    });
    cards.push_back(CardType{
        "Ore Vein",
        1,
        vector<size_t>{3, 4},
        Color::BROWN,
        vector<Produce>{},
        vector<string>{},
        vector<Produce>{Produce::ORE}
    });
    cards.push_back(CardType{
        "Tree Farm",
        1,
        vector<size_t>{6},
        Color::BROWN,
        vector<Produce>{Produce::COIN},
        vector<string>{},
        vector<Produce>{Produce::WOOD_OR_BRICK}
    });
    cards.push_back(CardType{
        "Excavation",
        1,
        vector<size_t>{4},
        Color::BROWN,
        vector<Produce>{Produce::COIN},
        vector<string>{},
        vector<Produce>{Produce::STONE_OR_BRICK}
    });
    cards.push_back(CardType{
        "Clay Pit",
        1,
        vector<size_t>{3},
        Color::BROWN,
        vector<Produce>{Produce::COIN},
        vector<string>{},
        vector<Produce>{Produce::BRICK_OR_ORE}
    });
    cards.push_back(CardType{
        "Timber Yard",
        1,
        vector<size_t>{3},
        Color::BROWN,
        vector<Produce>{Produce::COIN},
        vector<string>{},
        vector<Produce>{Produce::STONE_OR_WOOD}
    });
    cards.push_back(CardType{
        "Forest Cave",
        1,
        vector<size_t>{5},
        Color::BROWN,
        vector<Produce>{Produce::COIN},
        vector<string>{},
        vector<Produce>{Produce::WOOD_OR_ORE}
    });
    cards.push_back(CardType{
        "Mine",
        1,
        vector<size_t>{6},
        Color::BROWN,
        vector<Produce>{Produce::COIN},
        vector<string>{},
        vector<Produce>{Produce::ORE_OR_STONE}
    });



    cards.push_back(CardType{
        "Sawmill",
        2,
        vector<size_t>{3, 4},
        Color::BROWN,
        vector<Produce>{Produce::COIN},
        vector<string>{},
        vector<Produce>{Produce::WOOD, Produce::WOOD}
    });
    cards.push_back(CardType{
        "Quarry",
        2,
        vector<size_t>{3, 4},
        Color::BROWN,
        vector<Produce>{Produce::COIN},
        vector<string>{},
        vector<Produce>{Produce::STONE, Produce::STONE}
    });
    cards.push_back(CardType{
        "Brickyard",
        2,
        vector<size_t>{3, 4},
        Color::BROWN,
        vector<Produce>{Produce::COIN},
        vector<string>{},
        vector<Produce>{Produce::BRICK, Produce::BRICK}
    });
    cards.push_back(CardType{
        "Foundry",
        2,
        vector<size_t>{3, 4},
        Color::BROWN,
        vector<Produce>{Produce::COIN},
        vector<string>{},
        vector<Produce>{Produce::ORE, Produce::ORE}
    });



    cards.push_back(CardType{
        "Loom",
        1,
        vector<size_t>{3, 6},
        Color::GRAY,
        vector<Produce>{},
        vector<string>{},
        vector<Produce>{Produce::CLOTH}
    });
    cards.push_back(CardType{
        "Glassworks",
        1,
        vector<size_t>{3, 6},
        Color::GRAY,
        vector<Produce>{},
        vector<string>{},
        vector<Produce>{Produce::GLASS}
    });
    cards.push_back(CardType{
        "Press",
        1,
        vector<size_t>{3, 6},
        Color::GRAY,
        vector<Produce>{},
        vector<string>{},
        vector<Produce>{Produce::PAPER}
    });

    cards.push_back(CardType{
        "Loom",
        2,
        vector<size_t>{3, 5},
        Color::GRAY,
        vector<Produce>{},
        vector<string>{},
        vector<Produce>{Produce::CLOTH}
    });
    cards.push_back(CardType{
        "Glassworks",
        2,
        vector<size_t>{3, 5},
        Color::GRAY,
        vector<Produce>{},
        vector<string>{},
        vector<Produce>{Produce::GLASS}
    });
    cards.push_back(CardType{
        "Press",
        2,
        vector<size_t>{3, 5},
        Color::GRAY,
        vector<Produce>{},
        vector<string>{},
        vector<Produce>{Produce::PAPER}
    });



    cards.push_back(CardType{
        "Pawnshop",
        1,
        vector<size_t>{4, 7},
        Color::BLUE,
        vector<Produce>{},
        vector<string>{},
        vector<Produce>{Produce::VP, Produce::VP, Produce::VP}
    });
    cards.push_back(CardType{
        "Baths",
        1,
        vector<size_t>{3, 7},
        Color::BLUE,
        vector<Produce>{Produce::BRICK},
        vector<string>{},
        vector<Produce>{Produce::VP, Produce::VP, Produce::VP}
    });
    cards.push_back(CardType{
        "Altar",
        1,
        vector<size_t>{3, 5},
        Color::BLUE,
        vector<Produce>{},
        vector<string>{},
        vector<Produce>{Produce::VP, Produce::VP}
    });
    cards.push_back(CardType{
        "Theater",
        1,
        vector<size_t>{3, 6},
        Color::BLUE,
        vector<Produce>{},
        vector<string>{},
        vector<Produce>{Produce::VP, Produce::VP}
    });
    cards.push_back(CardType{
        "Aqueduct",
        2,
        vector<size_t>{3, 7},
        Color::BLUE,
        vector<Produce>{Produce::BRICK, Produce::BRICK, Produce::BRICK},
        vector<string>{"Baths"},
        vector<Produce>{Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP}
    });
    cards.push_back(CardType{
        "Temple",
        2,
        vector<size_t>{3, 6},
        Color::BLUE,
        vector<Produce>{Produce::WOOD, Produce::BRICK, Produce::GLASS},
        vector<string>{"Altar"},
        vector<Produce>{Produce::VP, Produce::VP, Produce::VP}
    });
    cards.push_back(CardType{
        "Statue",
        2,
        vector<size_t>{3, 7},
        Color::BLUE,
        vector<Produce>{Produce::WOOD, Produce::ORE, Produce::ORE},
        vector<string>{"Theater"},
        vector<Produce>{Produce::VP, Produce::VP, Produce::VP, Produce::VP}
    });
    cards.push_back(CardType{
        "Courthouse",
        2,
        vector<size_t>{3, 5},
        Color::BLUE,
        vector<Produce>{Produce::BRICK, Produce::BRICK, Produce::CLOTH},
        vector<string>{"Scriptorium"},
        vector<Produce>{Produce::VP, Produce::VP, Produce::VP, Produce::VP}
    });
    cards.push_back(CardType{
        "Pantheon",
        3,
        vector<size_t>{3, 6},
        Color::BLUE,
        vector<Produce>{Produce::BRICK, Produce::BRICK, Produce::ORE, Produce::PAPER, Produce::CLOTH, Produce::GLASS},
        vector<string>{"Temple"},
        vector<Produce>{Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP}
    });
    cards.push_back(CardType{
        "Gardens",
        3,
        vector<size_t>{3, 4},
        Color::BLUE,
        vector<Produce>{Produce::WOOD, Produce::BRICK, Produce::GLASS},
        vector<string>{"Statue"},
        vector<Produce>{Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP}
    });
    cards.push_back(CardType{
        "Town Hall",
        3,
        vector<size_t>{3, 5, 6},
        Color::BLUE,
        vector<Produce>{Produce::GLASS, Produce::ORE, Produce::STONE, Produce::STONE},
        vector<string>{},
        vector<Produce>{Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP}
    });
    cards.push_back(CardType{
        "Palace",
        3,
        vector<size_t>{3, 7},
        Color::BLUE,
        vector<Produce>{Produce::GLASS, Produce::PAPER, Produce::CLOTH, Produce::BRICK, Produce::WOOD, Produce::BRICK, Produce::ORE},
        vector<string>{},
        vector<Produce>{Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP}
    });
    cards.push_back(CardType{
        "Senate",
        3,
        vector<size_t>{3, 5},
        Color::BLUE,
        vector<Produce>{Produce::ORE, Produce::BRICK, Produce::WOOD, Produce::WOOD},
        vector<string>{"Library"},
        vector<Produce>{Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP}
    });



    cards.push_back(CardType{
        "Stockade",
        1,
        vector<size_t>{3, 7},
        Color::RED,
        vector<Produce>{Produce::WOOD},
        vector<string>{},
        vector<Produce>{Produce::SHIELD}
    });
    cards.push_back(CardType{
        "Barracks",
        1,
        vector<size_t>{3, 5},
        Color::RED,
        vector<Produce>{Produce::ORE},
        vector<string>{},
        vector<Produce>{Produce::SHIELD}
    });
    cards.push_back(CardType{
        "Guard Tower",
        1,
        vector<size_t>{3, 4},
        Color::RED,
        vector<Produce>{Produce::BRICK},
        vector<string>{},
        vector<Produce>{Produce::SHIELD}
    });

    cards.push_back(CardType{
        "Walls",
        2,
        vector<size_t>{3, 7},
        Color::RED,
        vector<Produce>{Produce::STONE, Produce::STONE, Produce::STONE},
        vector<string>{},
        vector<Produce>{Produce::SHIELD, Produce::SHIELD}
    });
    cards.push_back(CardType{
        "Training Ground",
        2,
        vector<size_t>{4, 6, 7},
        Color::RED,
        vector<Produce>{Produce::WOOD, Produce::ORE, Produce::ORE},
        vector<string>{},
        vector<Produce>{Produce::SHIELD, Produce::SHIELD}
    });
    cards.push_back(CardType{
        "Stables",
        2,
        vector<size_t>{3, 5},
        Color::RED,
        vector<Produce>{Produce::ORE, Produce::BRICK, Produce::WOOD},
        vector<string>{"Apothecary"},
        vector<Produce>{Produce::SHIELD, Produce::SHIELD}
    });
    cards.push_back(CardType{
        "Archery Range",
        2,
        vector<size_t>{3, 6},
        Color::RED,
        vector<Produce>{Produce::WOOD, Produce::WOOD, Produce::ORE},
        vector<string>{"Workshop"},
        vector<Produce>{Produce::SHIELD, Produce::SHIELD}
    });

    cards.push_back(CardType{
        "Fortifications",
        3,
        vector<size_t>{3, 7},
        Color::RED,
        vector<Produce>{Produce::BRICK, Produce::ORE, Produce::ORE, Produce::ORE},
        vector<string>{"Walls"},
        vector<Produce>{Produce::SHIELD, Produce::SHIELD, Produce::SHIELD}
    });
    cards.push_back(CardType{
        "Circus",
        3,
        vector<size_t>{4, 5, 6},
        Color::RED,
        vector<Produce>{Produce::BRICK, Produce::BRICK, Produce::BRICK, Produce::ORE},
        vector<string>{"Training Ground"},
        vector<Produce>{Produce::SHIELD, Produce::SHIELD, Produce::SHIELD}
    });
    cards.push_back(CardType{
        "Aresenal",
        3,
        vector<size_t>{3, 4, 7},
        Color::RED,
        vector<Produce>{Produce::ORE, Produce::WOOD, Produce::WOOD, Produce::CLOTH},
        vector<string>{},
        vector<Produce>{Produce::SHIELD, Produce::SHIELD, Produce::SHIELD}
    });
    cards.push_back(CardType{
        "Siege Workshop",
        3,
        vector<size_t>{3, 5},
        Color::RED,
        vector<Produce>{Produce::WOOD, Produce::BRICK, Produce::BRICK, Produce::BRICK},
        vector<string>{"Laboratory"},
        vector<Produce>{Produce::SHIELD, Produce::SHIELD, Produce::SHIELD}
    });



    cards.push_back(CardType{
        "Apothecary",
        1,
        vector<size_t>{3, 5},
        Color::GREEN,
        vector<Produce>{Produce::CLOTH},
        vector<string>{},
        vector<Produce>{Produce::COMPASS}
    });
    cards.push_back(CardType{
        "Workshop",
        1,
        vector<size_t>{3, 7},
        Color::GREEN,
        vector<Produce>{Produce::GLASS},
        vector<string>{},
        vector<Produce>{Produce::GEAR}
    });
    cards.push_back(CardType{
        "Scriptorium",
        1,
        vector<size_t>{3, 4},
        Color::GREEN,
        vector<Produce>{Produce::PAPER},
        vector<string>{},
        vector<Produce>{Produce::TABLET}
    });

    cards.push_back(CardType{
        "Dispensary",
        2,
        vector<size_t>{3, 4},
        Color::GREEN,
        vector<Produce>{Produce::ORE, Produce::ORE, Produce::GLASS},
        vector<string>{"Apothecary"},
        vector<Produce>{Produce::COMPASS}
    });
    cards.push_back(CardType{
        "Laboratory",
        2,
        vector<size_t>{3, 5},
        Color::GREEN,
        vector<Produce>{Produce::BRICK, Produce::BRICK, Produce::PAPER},
        vector<string>{"Workshop"},
        vector<Produce>{Produce::GEAR}
    });
    cards.push_back(CardType{
        "Library",
        2,
        vector<size_t>{3, 6},
        Color::GREEN,
        vector<Produce>{Produce::BRICK, Produce::BRICK, Produce::PAPER},
        vector<string>{"Scriptorium"},
        vector<Produce>{Produce::TABLET}
    });
    cards.push_back(CardType{
        "School",
        2,
        vector<size_t>{3, 7},
        Color::GREEN,
        vector<Produce>{Produce::WOOD, Produce::PAPER},
        vector<string>{},
        vector<Produce>{Produce::TABLET}
    });

    cards.push_back(CardType{
        "Lodge",
        3,
        vector<size_t>{3, 6},
        Color::GREEN,
        vector<Produce>{Produce::BRICK, Produce::BRICK, Produce::CLOTH, Produce::PAPER},
        vector<string>{"Dispensary"},
        vector<Produce>{Produce::COMPASS}
    });
    cards.push_back(CardType{
        "Observatory",
        3,
        vector<size_t>{3, 7},
        Color::GREEN,
        vector<Produce>{Produce::ORE, Produce::ORE, Produce::GLASS, Produce::CLOTH},
        vector<string>{"Laboratory"},
        vector<Produce>{Produce::GEAR}
    });
    cards.push_back(CardType{
        "University",
        3,
        vector<size_t>{3, 4},
        Color::GREEN,
        vector<Produce>{Produce::WOOD, Produce::WOOD, Produce::PAPER, Produce::GLASS},
        vector<string>{"Library"},
        vector<Produce>{Produce::TABLET}
    });
    cards.push_back(CardType{
        "Academy",
        3,
        vector<size_t>{3, 7},
        Color::GREEN,
        vector<Produce>{Produce::STONE, Produce::STONE, Produce::STONE, Produce::GLASS},
        vector<string>{"School"},
        vector<Produce>{Produce::COMPASS}
    });
    cards.push_back(CardType{
        "Study",
        3,
        vector<size_t>{3, 5},
        Color::GREEN,
        vector<Produce>{Produce::WOOD, Produce::PAPER, Produce::CLOTH},
        vector<string>{"School"},
        vector<Produce>{Produce::GEAR}
    });



    cards.push_back(CardType{
        "Tavern",
        1,
        vector<size_t>{4, 5, 7},
        Color::YELLOW,
        vector<Produce>{},
        vector<string>{},
        vector<Produce>{Produce::COIN, Produce::COIN, Produce::COIN, Produce::COIN, Produce::COIN}
    });
    cards.push_back(CardType{
        "East Trading Post",
        1,
        vector<size_t>{3, 7},
        Color::YELLOW,
        vector<Produce>{},
        vector<string>{},
        vector<Produce>{Produce::RIGHT_RAW_CHEAP}
    });
    cards.push_back(CardType{
        "West Trading Post",
        1,
        vector<size_t>{3, 7},
        Color::YELLOW,
        vector<Produce>{},
        vector<string>{},
        vector<Produce>{Produce::LEFT_RAW_CHEAP}
    });
    cards.push_back(CardType{
        "Marketplace",
        1,
        vector<size_t>{3, 6},
        Color::YELLOW,
        vector<Produce>{},
        vector<string>{},
        vector<Produce>{Produce::MANUFACTURED_CHEAP}
    });
    cards.push_back(CardType{
        "Forum",
        2,
        vector<size_t>{3, 6, 7},
        Color::YELLOW,
        vector<Produce>{Produce::BRICK, Produce::BRICK},
        vector<string>{"East Trading Post", "West Trading Post"},
        vector<Produce>{Produce::MANUFACTURED_GOOD}
    });
    cards.push_back(CardType{
        "Caravansery",
        2,
        vector<size_t>{3, 5, 6},
        Color::YELLOW,
        vector<Produce>{Produce::WOOD, Produce::WOOD},
        vector<string>{"Marketplace"},
        vector<Produce>{Produce::RAW_MATERIAL}
    });
    cards.push_back(CardType{
        "Vineyard",
        2,
        vector<size_t>{3, 6},
        Color::YELLOW,
        vector<Produce>{},
        vector<string>{},
        [](const Player& p){
            vector<Card> ourCards = p.getCards(),
                         leftCards = p.getLeftPlayer()->getCards(),
                         rightCards = p.getRightPlayer()->getCards();
            size_t numBrown = 0;
            numBrown += std::count_if(ourCards.begin(), ourCards.end(), [](const Card& c){ return c.getColor() == Color::BROWN; });
            numBrown += std::count_if(leftCards.begin(), leftCards.end(), [](const Card& c){ return c.getColor() == Color::BROWN; });
            numBrown += std::count_if(rightCards.begin(), rightCards.end(), [](const Card& c){ return c.getColor() == Color::BROWN; });
            return vector<Produce>(numBrown, Produce::COIN);
        }
    });
    cards.push_back(CardType{
        "Bazar",
        2,
        vector<size_t>{4, 7},
        Color::YELLOW,
        vector<Produce>{},
        vector<string>{},
        [](const Player& p){
            vector<Card> ourCards = p.getCards(),
                         leftCards = p.getLeftPlayer()->getCards(),
                         rightCards = p.getRightPlayer()->getCards();
            size_t numGray = 0;
            numGray += std::count_if(ourCards.begin(), ourCards.end(), [](const Card& c){ return c.getColor() == Color::GRAY; });
            numGray += std::count_if(leftCards.begin(), leftCards.end(), [](const Card& c){ return c.getColor() == Color::GRAY; });
            numGray += std::count_if(rightCards.begin(), rightCards.end(), [](const Card& c){ return c.getColor() == Color::GRAY; });
            return vector<Produce>(2*numGray, Produce::COIN);
        }
    });

    cards.push_back(CardType{
        "Haven",
        3,
        vector<size_t>{3, 4},
        Color::YELLOW,
        vector<Produce>{Produce::CLOTH, Produce::ORE, Produce::WOOD},
        vector<string>{"Forum"},
        [](const Player& p){
            vector<Card> ourCards = p.getCards();
            size_t numBrown = 0;
            numBrown += std::count_if(ourCards.begin(), ourCards.end(), [](const Card& c){ return c.getColor() == Color::BROWN; });
            vector<Produce> ret(numBrown, Produce::COIN);
            ret.insert(ret.end(), numBrown, Produce::VP);
            return ret;
        }
    });
    cards.push_back(CardType{
        "Lighthouse",
        3,
        vector<size_t>{3, 6},
        Color::YELLOW,
        vector<Produce>{Produce::GLASS, Produce::STONE},
        vector<string>{"Caravansery"},
        [](const Player& p){
            vector<Card> ourCards = p.getCards();
            size_t numYellow = 0;
            numYellow += std::count_if(ourCards.begin(), ourCards.end(), [](const Card& c){ return c.getColor() == Color::YELLOW; });
            vector<Produce> ret(numYellow, Produce::COIN);
            ret.insert(ret.end(), numYellow, Produce::VP);
            return ret;
        }
    });
    cards.push_back(CardType{
        "Chamber of Commerce",
        3,
        vector<size_t>{4, 6},
        Color::YELLOW,
        vector<Produce>{Produce::BRICK, Produce::BRICK, Produce::PAPER},
        vector<string>{},
        [](const Player& p){
            vector<Card> ourCards = p.getCards();
            size_t numGray = 0;
            numGray += std::count_if(ourCards.begin(), ourCards.end(), [](const Card& c){ return c.getColor() == Color::GRAY; });
            vector<Produce> ret(2*numGray, Produce::COIN);
            ret.insert(ret.end(), 2*numGray, Produce::VP);
            return ret;
        }
    });
    cards.push_back(CardType{ // TODO
        "Arena",
        3,
        vector<size_t>{3, 5, 7},
        Color::YELLOW,
        vector<Produce>{Produce::ORE, Produce::STONE, Produce::STONE},
        vector<string>{"Dispensary"},
        vector<Produce>{}
    });


// PURPLE
    cards.push_back(CardType{
        "Workers Guild",
        3,
        vector<size_t>{},
        Color::PURPLE,
        vector<Produce>{Produce::ORE, Produce::ORE, Produce::BRICK, Produce::STONE, Produce::WOOD},
        vector<string>{},
        [](const Player& p){
            vector<Card> leftCards = p.getLeftPlayer()->getCards(),
                         rightCards = p.getRightPlayer()->getCards();
            size_t numBrown = 0;
            numBrown += std::count_if(leftCards.begin(), leftCards.end(), [](const Card& c){ return c.getColor() == Color::BROWN; });
            numBrown += std::count_if(rightCards.begin(), rightCards.end(), [](const Card& c){ return c.getColor() == Color::BROWN; });
            return vector<Produce>(numBrown, Produce::VP);
        }
    });
    cards.push_back(CardType{
        "Craftmens Guild",
        3,
        vector<size_t>{},
        Color::PURPLE,
        vector<Produce>{Produce::ORE, Produce::ORE, Produce::STONE, Produce::STONE},
        vector<string>{},
        [](const Player& p){
            vector<Card> leftCards = p.getLeftPlayer()->getCards(),
                         rightCards = p.getRightPlayer()->getCards();
            size_t numGray = 0;
            numGray += std::count_if(leftCards.begin(), leftCards.end(), [](const Card& c){ return c.getColor() == Color::GRAY; });
            numGray += std::count_if(rightCards.begin(), rightCards.end(), [](const Card& c){ return c.getColor() == Color::GRAY; });
            return vector<Produce>(2*numGray, Produce::VP);
        }
    });
    cards.push_back(CardType{
        "Traders Guild",
        3,
        vector<size_t>{},
        Color::PURPLE,
        vector<Produce>{Produce::CLOTH, Produce::PAPER, Produce::GLASS},
        vector<string>{},
        [](const Player& p){
            vector<Card> leftCards = p.getLeftPlayer()->getCards(),
                         rightCards = p.getRightPlayer()->getCards();
            size_t numYellow = 0;
            numYellow += std::count_if(leftCards.begin(), leftCards.end(), [](const Card& c){ return c.getColor() == Color::YELLOW; });
            numYellow += std::count_if(rightCards.begin(), rightCards.end(), [](const Card& c){ return c.getColor() == Color::YELLOW; });
            return vector<Produce>(numYellow, Produce::VP);
        }
    });
    cards.push_back(CardType{
        "Philosophers Guild",
        3,
        vector<size_t>{},
        Color::PURPLE,
        vector<Produce>{Produce::BRICK, Produce::BRICK, Produce::BRICK, Produce::CLOTH, Produce::PAPER},
        vector<string>{},
        [](const Player& p){
            vector<Card> leftCards = p.getLeftPlayer()->getCards(),
                         rightCards = p.getRightPlayer()->getCards();
            size_t numGreen = 0;
            numGreen += std::count_if(leftCards.begin(), leftCards.end(), [](const Card& c){ return c.getColor() == Color::GREEN; });
            numGreen += std::count_if(rightCards.begin(), rightCards.end(), [](const Card& c){ return c.getColor() == Color::GREEN; });
            return vector<Produce>(numGreen, Produce::VP);
        }
    });
    cards.push_back(CardType{
        "Spies Guild",
        3,
        vector<size_t>{},
        Color::PURPLE,
        vector<Produce>{Produce::BRICK, Produce::BRICK, Produce::BRICK, Produce::GLASS},
        vector<string>{},
        [](const Player& p){
            vector<Card> leftCards = p.getLeftPlayer()->getCards(),
                         rightCards = p.getRightPlayer()->getCards();
            size_t numRed = 0;
            numRed += std::count_if(leftCards.begin(), leftCards.end(), [](const Card& c){ return c.getColor() == Color::RED; });
            numRed += std::count_if(rightCards.begin(), rightCards.end(), [](const Card& c){ return c.getColor() == Color::RED; });
            return vector<Produce>(numRed, Produce::VP);
        }
    });
    cards.push_back(CardType{
        "Strategists Guild",
        3,
        vector<size_t>{},
        Color::PURPLE,
        vector<Produce>{Produce::ORE, Produce::ORE, Produce::STONE, Produce::CLOTH},
        vector<string>{},
        [](const Player& p){
            size_t numLosses = p.getLeftPlayer()->getMilitaryLosses() + p.getRightPlayer()->getMilitaryLosses();
            return vector<Produce>(numLosses, Produce::VP);
        }
    });
    cards.push_back(CardType{
        "Shipowners Guild",
        3,
        vector<size_t>{},
        Color::PURPLE,
        vector<Produce>{Produce::WOOD, Produce::WOOD, Produce::WOOD, Produce::PAPER, Produce::GLASS},
        vector<string>{},
        [](const Player& p){
            vector<Card> ourCards = p.getCards();
            size_t numVPs = 0;
            numVPs += std::count_if(ourCards.begin(), ourCards.end(), [](const Card& c){
                return c.getColor() == Color::BROWN || c.getColor() == Color::GRAY || c.getColor() == Color::PURPLE;
            });
            return vector<Produce>(numVPs, Produce::VP);
        }
    });
    cards.push_back(CardType{
        "Scientists Guild",
        3,
        vector<size_t>{},
        Color::PURPLE,
        vector<Produce>{Produce::WOOD, Produce::WOOD, Produce::ORE, Produce::ORE, Produce::PAPER},
        vector<string>{},
        vector<Produce>{Produce::ANY_SCIENCE}
    });
    cards.push_back(CardType{
        "Magistrates Guild",
        3,
        vector<size_t>{},
        Color::PURPLE,
        vector<Produce>{Produce::WOOD, Produce::WOOD, Produce::WOOD, Produce::STONE, Produce::CLOTH},
        vector<string>{},
        [](const Player& p){
            vector<Card> leftCards = p.getLeftPlayer()->getCards(),
                         rightCards = p.getRightPlayer()->getCards();
            size_t numBlue = 0;
            numBlue += std::count_if(leftCards.begin(), leftCards.end(), [](const Card& c){ return c.getColor() == Color::BLUE; });
            numBlue += std::count_if(rightCards.begin(), rightCards.end(), [](const Card& c){ return c.getColor() == Color::BLUE; });
            return vector<Produce>(numBlue, Produce::VP);
        }
    });
    cards.push_back(CardType{
        "Builders Guild",
        3,
        vector<size_t>{},
        Color::PURPLE,
        vector<Produce>{Produce::STONE, Produce::STONE, Produce::BRICK, Produce::BRICK, Produce::GLASS},
        vector<string>{},
        vector<Produce>{}
    });

    return cards;

}
