#ifndef PAY_H
#define PAY_H
#include <ostream>

struct Pay {
    size_t bank;
    size_t left;
    size_t right;
    size_t getTotal() { return bank + left + right; }
};

bool operator==(const Pay& p1, const Pay& p2);
std::ostream& operator<< (std::ostream& o, const Pay& p);

#endif//PAY_H
