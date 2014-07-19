#ifndef PAY_H
#define PAY_H
#include <ostream>

struct Pay {
    size_t bank = 0;
    size_t left = 0;
    size_t right = 0;
    size_t getTotal() const { return bank + left + right; }
};

bool operator==(const Pay& p1, const Pay& p2);
std::ostream& operator<< (std::ostream& o, const Pay& p);

#endif//PAY_H
