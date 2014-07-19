#include "CardType.hpp"

using namespace std;

CardType::CardType(const string name,
           size_t age,
           vector<size_t> players,
           Color color,
           const vector<Produce> cost,
           const vector<string> chainNames,
           const function<vector<Produce> (const Player& p)> getProduce)
    : name_{name},
      age_{age},
      players_{players},
      color_{color},
      cost_{cost},
      chainNames_{chainNames},
      getProduce_{getProduce}
    {
    
}

Card CardType::createCard() const {
    return Card{name_, color_, cost_, chainNames_, getProduce_};
}

std::ostream& operator<< (std::ostream& o, const CardType& c) {
    o << c.getName();
    return o;
}

