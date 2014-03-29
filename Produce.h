#ifndef PRODUCE_H
#define PRODUCE_H
#include <iostream>
#include <vector>

enum class Produce {
    WOOD,
    STONE,
    ORE,
    BRICK,
    PAPER,
    CLOTH,
    GLASS,
    VP,
    GEAR,
    COMPASS,
    TABLET,
    ANY_SCIENCE,
    COIN,
    SHIELD,
    WOOD_OR_BRICK,
    STONE_OR_BRICK,
    BRICK_OR_ORE,
    STONE_OR_WOOD,
    WOOD_OR_ORE,
    ORE_OR_STONE,
    RAW_MATERIAL,
    MANUFACTURED_GOOD,
    LEFT_RAW_CHEAP,
    RIGHT_RAW_CHEAP,
    MANUFACTURED_CHEAP,
};

std::vector<Produce> simplify(const Produce& p);

//bool operator<(const Produce& lhs, const Produce& rhs) {
//    return static_cast<int>(lhs) < static_cast<int>(rhs);
//}

std::ostream& operator<< (std::ostream& o, const Produce& p);

#endif//PRODUCE_H
