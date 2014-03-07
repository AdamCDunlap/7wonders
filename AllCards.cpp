
#include "AllCards.h"
using namespace std;

std::vector<Card> AllCards::getAllCards() {
    vector<Card> cards;

    cards.push_back(Card{
        "Lumber Yard",
        vector<size_t>{1},
        vector<size_t>{3, 4},
        Color::BROWN,
        vector<Produce>{},
        "",
        vector<Produce>{Produce::WOOD}
    });
    cards.push_back(Card{
        "Stone Pit",
        vector<size_t>{1},
        vector<size_t>{3, 5},
        Color::BROWN,
        vector<Produce>{},
        "",
        vector<Produce>{Produce::ORE}
    });
    cards.push_back(Card{
        "Clay Pool",
        vector<size_t>{1},
        vector<size_t>{3, 5},
        Color::BROWN,
        vector<Produce>{},
        "",
        vector<Produce>{Produce::BRICK}
    });
    cards.push_back(Card{
        "Ore Vein",
        vector<size_t>{1},
        vector<size_t>{3, 4},
        Color::BROWN,
        vector<Produce>{},
        "",
        vector<Produce>{Produce::WOOD}
    });
    cards.push_back(Card{
        "Tree Farm",
        vector<size_t>{1},
        vector<size_t>{6},
        Color::BROWN,
        vector<Produce>{Produce::COIN},
        "",
        vector<Produce>{Produce::WOOD_OR_BRICK}
    });
    cards.push_back(Card{
        "Excavation",
        vector<size_t>{1},
        vector<size_t>{4},
        Color::BROWN,
        vector<Produce>{Produce::COIN},
        "",
        vector<Produce>{Produce::STONE_OR_BRICK}
    });
    cards.push_back(Card{
        "Clay Pit",
        vector<size_t>{1},
        vector<size_t>{3},
        Color::BROWN,
        vector<Produce>{Produce::COIN},
        "",
        vector<Produce>{Produce::BRICK_OR_ORE}
    });
    cards.push_back(Card{
        "Timber Yard",
        vector<size_t>{1},
        vector<size_t>{3},
        Color::BROWN,
        vector<Produce>{Produce::COIN},
        "",
        vector<Produce>{Produce::STONE_OR_WOOD}
    });
    cards.push_back(Card{
        "Forest Cave",
        vector<size_t>{1},
        vector<size_t>{5},
        Color::BROWN,
        vector<Produce>{Produce::COIN},
        "",
        vector<Produce>{Produce::WOOD_OR_ORE}
    });
    cards.push_back(Card{
        "Mine",
        vector<size_t>{1},
        vector<size_t>{6},
        Color::BROWN,
        vector<Produce>{Produce::COIN},
        "",
        vector<Produce>{Produce::ORE_OR_STONE}
    });



    cards.push_back(Card{
        "Sawmill",
        vector<size_t>{2},
        vector<size_t>{3, 4},
        Color::BROWN,
        vector<Produce>{Produce::COIN},
        "",
        vector<Produce>{Produce::WOOD, Produce::WOOD}
    });
    cards.push_back(Card{
        "Quarry",
        vector<size_t>{2},
        vector<size_t>{3, 4},
        Color::BROWN,
        vector<Produce>{Produce::COIN},
        "",
        vector<Produce>{Produce::STONE, Produce::STONE}
    });
    cards.push_back(Card{
        "Brickyard",
        vector<size_t>{2},
        vector<size_t>{3, 4},
        Color::BROWN,
        vector<Produce>{Produce::COIN},
        "",
        vector<Produce>{Produce::ORE, Produce::ORE}
    });
    cards.push_back(Card{
        "Foundry",
        vector<size_t>{2},
        vector<size_t>{3, 4},
        Color::BROWN,
        vector<Produce>{Produce::COIN},
        "",
        vector<Produce>{Produce::ORE, Produce::ORE}
    });

    return cards;

}
