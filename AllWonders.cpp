
#include "AllWonders.hpp"
#include "Card.hpp"
#include "Player.hpp"
using namespace std;

// Define helper conversion from vector to functional
static function< vector<Produce> (const Player&) > v2f(vector<Produce> v) {
    return [v](const Player&) { return v; };
}

std::vector<Wonder> AllWonders::getAllWonders() {
    vector<Wonder> wonders;

    wonders.push_back(Wonder{
        "The Colossus of Rhodes",
        { { {Produce::WOOD, Produce::WOOD}, {Produce::BRICK, Produce::BRICK, Produce::BRICK}, {Produce::ORE, Produce::ORE, Produce::ORE, Produce::ORE} },
          { {Produce::STONE, Produce::STONE}, {Produce::ORE, Produce::ORE, Produce::ORE, Produce::ORE} } },
        { { v2f({Produce::ORE}), v2f({Produce::VP, Produce::VP, Produce::VP}), v2f({Produce::SHIELD, Produce::SHIELD}), v2f({Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP})},
          { v2f({Produce::ORE}), v2f({Produce::SHIELD, Produce::VP, Produce::VP, Produce::VP, Produce::COIN, Produce::COIN, Produce::COIN}), v2f({Produce::SHIELD, Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::COIN, Produce::COIN, Produce::COIN, Produce::COIN})}}
    });
    wonders.push_back(Wonder{
        "The Lighthouse of Alexandria",
        { { {Produce::STONE, Produce::STONE}, {Produce::ORE, Produce::ORE}, {Produce::GLASS, Produce::GLASS} },
          { {Produce::BRICK, Produce::BRICK}, {Produce::WOOD, Produce::WOOD}, {Produce::STONE, Produce::STONE} } },
        { { v2f({Produce::GLASS}), v2f({Produce::VP, Produce::VP, Produce::VP}), v2f({Produce::RAW_MATERIAL}), v2f({Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP})},
          { v2f({Produce::GLASS}), v2f({Produce::RAW_MATERIAL}), v2f({Produce::MANUFACTURED_GOOD}), v2f({Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP})}}
    });
    wonders.push_back(Wonder{
        "The Temple of Artemis in Ephesus",
        { { {Produce::STONE, Produce::STONE}, {Produce::WOOD, Produce::WOOD}, {Produce::PAPER, Produce::PAPER} },
          { {Produce::STONE, Produce::STONE}, {Produce::WOOD, Produce::WOOD}, {Produce::PAPER, Produce::CLOTH, Produce::GLASS} } },
        { { v2f({Produce::PAPER}), v2f({Produce::VP, Produce::VP, Produce::VP}), v2f({Produce::COIN, Produce::COIN, Produce::COIN, Produce::COIN, Produce::COIN, Produce::COIN, Produce::COIN, Produce::COIN, Produce::COIN}), v2f({Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP})},
          { v2f({Produce::PAPER}), v2f({Produce::VP, Produce::VP, Produce::COIN, Produce::COIN, Produce::COIN, Produce::COIN}), v2f({Produce::VP, Produce::VP, Produce::VP, Produce::COIN, Produce::COIN, Produce::COIN, Produce::COIN}), v2f({Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::COIN, Produce::COIN, Produce::COIN, Produce::COIN})}}
    });
    wonders.push_back(Wonder{
        "The Hanging Gardens of Babylon",
        { { {Produce::BRICK, Produce::BRICK}, {Produce::WOOD, Produce::WOOD, Produce::WOOD}, {Produce::BRICK, Produce::BRICK, Produce::BRICK, Produce::BRICK} },
          { {Produce::CLOTH, Produce::BRICK}, {Produce::GLASS, Produce::WOOD, Produce::WOOD}, {Produce::PAPER, Produce::BRICK, Produce::BRICK, Produce::BRICK} } },
        { { v2f({Produce::BRICK}), v2f({Produce::VP, Produce::VP, Produce::VP}), v2f({Produce::ANY_SCIENCE}), v2f({Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP})},
          { v2f({Produce::BRICK}), v2f({Produce::VP, Produce::VP, Produce::VP}), v2f({Produce::BUILD_SEVENTH}), v2f({Produce::ANY_SCIENCE})}}
    });
    wonders.push_back(Wonder{
        "The Statue of Zeus in Olympia",
        { { {Produce::WOOD, Produce::WOOD}, {Produce::STONE, Produce::STONE}, {Produce::ORE, Produce::ORE} },
          { {Produce::WOOD, Produce::WOOD}, {Produce::STONE, Produce::STONE}, {Produce::CLOTH, Produce::ORE, Produce::ORE} } },
        { { v2f({Produce::WOOD}), v2f({Produce::VP, Produce::VP, Produce::VP}), v2f({Produce::FREE_STRUCTURE}), v2f({Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP})},
          { v2f({Produce::WOOD}), v2f({Produce::LEFT_RAW_CHEAP, Produce::RIGHT_RAW_CHEAP}), v2f({Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP}),
            [](const Player& p){
                // Return a number of VP equal to the highest that would be gotten from the purple cards on either side
                size_t most_points = 0;
                for (const Card& c : p.getLeftPlayer()->getCards()) {
                    if(c.getColor() != Color::PURPLE) continue;
                    // Assume that every produce is a victory point because that's true for all the current guilds
                    size_t vp = c.getProduce(p).size();
                    if (vp > most_points) most_points = vp;
                }
                for (const Card& c : p.getRightPlayer()->getCards()) {
                    if(c.getColor() != Color::PURPLE) continue;
                    // Assume that every produce is a victory point because that's true for all the current guilds
                    size_t vp = c.getProduce(p).size();
                    if (vp > most_points) most_points = vp;
                }
                return vector<Produce>(most_points, Produce::VP);
            }}}
    });
    wonders.push_back(Wonder{
        "The Mausoleum of Halicarnassus",
        { { {Produce::BRICK, Produce::BRICK}, {Produce::ORE, Produce::ORE, Produce::ORE}, {Produce::CLOTH, Produce::CLOTH} },
          { {Produce::ORE, Produce::ORE}, {Produce::BRICK, Produce::BRICK, Produce::BRICK}, {Produce::GLASS, Produce::PAPER, Produce::CLOTH} } },
        { { v2f({Produce::CLOTH}), v2f({Produce::VP, Produce::VP, Produce::VP}),
            v2f({Produce::FROM_DISCARD}), v2f({Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP})},
          { v2f({Produce::CLOTH}), v2f({Produce::VP, Produce::VP, Produce::FROM_DISCARD}), v2f({Produce::VP, Produce::FROM_DISCARD}), v2f({Produce::FROM_DISCARD})}}
    });
    wonders.push_back(Wonder{
        "The Pyramids of Giza",
        { { {Produce::STONE, Produce::STONE}, {Produce::WOOD, Produce::WOOD, Produce::WOOD}, {Produce::STONE, Produce::STONE, Produce::STONE, Produce::STONE} },
          { {Produce::WOOD, Produce::WOOD}, {Produce::STONE, Produce::STONE, Produce::STONE}, {Produce::BRICK, Produce::BRICK, Produce::BRICK}, {Produce::PAPER, Produce::STONE, Produce::STONE, Produce::STONE, Produce::STONE} } },
        { { v2f({Produce::STONE}), v2f({Produce::VP, Produce::VP, Produce::VP}), v2f({Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP}), v2f({Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP})},
          { v2f({Produce::STONE}), v2f({Produce::VP, Produce::VP, Produce::VP}), v2f({Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP}), v2f({Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP}), v2f({Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP, Produce::VP})}}
    });

    return wonders;

}
