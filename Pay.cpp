#include "Pay.hpp"

bool operator==(const Pay& p1, const Pay& p2)
{
    return p1.bank == p2.bank && p1.left == p2.left && p1.right == p2.right;
}
std::ostream& operator<< (std::ostream& o, const Pay& p)
{
    o << "Bank: " << p.bank << ", Left: " << p.left << ", Right: " << p.right;
    return o;
}

