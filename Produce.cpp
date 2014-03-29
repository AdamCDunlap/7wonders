#include "Produce.h"

std::ostream& operator<< (std::ostream& o, const Produce& p) {
    switch(p) {
    case Produce::WOOD: o << "WOOD"; break;
    case Produce::STONE: o << "STONE"; break;
    case Produce::ORE: o << "ORE"; break;
    case Produce::BRICK: o << "BRICK"; break;
    case Produce::PAPER: o << "PAPER"; break;
    case Produce::CLOTH: o << "CLOTH"; break;
    case Produce::GLASS: o << "GLASS"; break;
    case Produce::VP: o << "VP"; break;
    case Produce::GEAR: o << "GEAR"; break;
    case Produce::COMPASS: o << "COMPASS"; break;
    case Produce::TABLET: o << "TABLET"; break;
    case Produce::ANY_SCIENCE: o << "ANY_SCIENCE"; break;
    case Produce::COIN: o << "COIN"; break;
    case Produce::SHIELD: o << "SHIELD"; break;
    case Produce::WOOD_OR_BRICK: o << "WOOD_OR_BRICK"; break;
    case Produce::STONE_OR_BRICK: o << "STONE_OR_BRICK"; break;
    case Produce::BRICK_OR_ORE: o << "BRICK_OR_ORE"; break;
    case Produce::STONE_OR_WOOD: o << "STONE_OR_WOOD"; break;
    case Produce::WOOD_OR_ORE: o << "WOOD_OR_ORE"; break;
    case Produce::ORE_OR_STONE: o << "ORE_OR_STONE"; break;
    case Produce::RAW_MATERIAL: o << "RAW_MATERIAL"; break;
    case Produce::MANUFACTURED_GOOD: o << "MANUFACTURED_GOOD"; break;
    case Produce::LEFT_RAW_CHEAP: o << "LEFT_RAW_CHEAP"; break;
    case Produce::RIGHT_RAW_CHEAP: o << "RIGHT_RAW_CHEAP"; break;
    case Produce::MANUFACTURED_CHEAP: o << "MANUFACTURED_CHEAP"; break;
    }
    return o;
}

// o    case Produce::WOOD: o << "WOOD"; break;21k^"nyw21j:s/WOOD//g

std::vector<Produce> simplify(const Produce& p) {
    switch(p) {
    case Produce::ANY_SCIENCE:       return std::vector<Produce>{Produce::GEAR,  Produce::COMPASS, Produce::TABLET};
    case Produce::WOOD_OR_BRICK:     return std::vector<Produce>{Produce::WOOD,  Produce::BRICK};
    case Produce::STONE_OR_BRICK:    return std::vector<Produce>{Produce::STONE, Produce::BRICK};
    case Produce::BRICK_OR_ORE:      return std::vector<Produce>{Produce::BRICK, Produce::ORE};
    case Produce::STONE_OR_WOOD:     return std::vector<Produce>{Produce::STONE, Produce::WOOD};
    case Produce::WOOD_OR_ORE:       return std::vector<Produce>{Produce::WOOD,  Produce::ORE};
    case Produce::ORE_OR_STONE:      return std::vector<Produce>{Produce::ORE,   Produce::STONE};
    case Produce::RAW_MATERIAL:      return std::vector<Produce>{Produce::WOOD,  Produce::STONE, Produce::ORE, Produce::BRICK};
    case Produce::MANUFACTURED_GOOD: return std::vector<Produce>{Produce::PAPER, Produce::CLOTH, Produce::GLASS};
    default: return std::vector<Produce>{p};
    }
}
