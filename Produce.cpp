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
    case Produce::ANTI_VP: o << "ANTI_VP"; break;
    case Produce::GEAR: o << "GEAR"; break;
    case Produce::COMPASS: o << "COMPASS"; break;
    case Produce::TABLET: o << "TABLET"; break;
    case Produce::SCIENCE: o << "SCIENCE"; break;
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
    }
    return o;
}

// o    case Produce::WOOD: o << "WOOD"; break;21k^"nyw21j:s/WOOD//g
