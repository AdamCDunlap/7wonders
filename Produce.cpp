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
    case Produce::FREE_STRUCTURE: o << "FREE_STRUCTURE"; break;
    case Produce::FROM_DISCARD: o << "FROM_DISCARD"; break;
    case Produce::BUILD_SEVENTH: o << "BUILD_SEVENTH"; break;
    }
    return o;
}

// o    case Produce::WOOD: o << "WOOD"; break;21k^"nyw21j:s/WOOD//g
#if 0
:%s/WOOD/Produce::WOOD/gi:%s/STONE/Produce::STONE/gi:%s/ORE/Produce::ORE/gi:%s/BRICK/Produce::BRICK/gi:%s/PAPER/Produce::PAPER/gi:%s/CLOTH/Produce::CLOTH/gi:%s/GLASS/Produce::GLASS/gi:%s/VP/Produce::VP/gi:%s/GEAR/Produce::GEAR/gi:%s/COMPASS/Produce::COMPASS/gi:%s/TABLET/Produce::TABLET/gi:%s/ANY_SCIENCE/Produce::ANY_SCIENCE/gi:%s/COIN/Produce::COIN/gi:%s/SHIELD/Produce::SHIELD/gi:%s/WOOD_OR_BRICK/Produce::WOOD_OR_BRICK/gi:%s/Produce::STONE_OR_BRICK/Produce::Produce::STONE_OR_BRICK/gi:%s/BRICK_OR_ORE/Produce::BRICK_OR_ORE/gi:%s/Produce::STONE_OR_WOOD/Produce::Produce::STONE_OR_WOOD/gi:%s/WOOD_OR_ORE/Produce::WOOD_OR_ORE/gi:%s/ORE/Produce::ORE/gi:%s/BRICK/Produce::BRICK/gi:%s/PAPER/Produce::PAPER/gi:%s/ORE_OR_Produce::STONE/Produce::ORE_OR_Produce::STONE/gi:%s/RAW_MATERIAL/Produce::RAW_MATERIAL/gi:%s/MANUFACTURED_GOOD/Produce::MANUFACTURED_GOOD/gi:%s/LEFT_RAW_CHEAP/Produce::LEFT_RAW_CHEAP/gi:%s/RIGHT_RAW_CHEAP/Produce::RIGHT_RAW_CHEAP/gi:%s/MANUFACTURED_CHEAP/Produce::MANUFACTURED_CHEAP/gi:%s/FREE_STRUCTURE/Produce::FREE_STRUCTURE/gi:%s/BUILD_SEVENTH/Produce::BUILD_SEVENTH/gi
#endif


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

std::vector<Produce> simplifyForBuy(const Produce& p) {
    switch(p) {
    case Produce::RAW_MATERIAL:
    case Produce::MANUFACTURED_GOOD: return std::vector<Produce>{p};
    default: return simplify(p);
    }
}
