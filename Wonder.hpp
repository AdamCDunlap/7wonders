class Wonder;
#ifndef WONDER_H
#define WONDER_H

#include "Produce.hpp"
#include <vector>
#include <string>
#include <functional>

// Forward declare
class Player;

class Wonder {
public:
    Wonder(std::string name,
           std::vector< std::vector< std::vector<Produce> > > costs,
           std::vector< std::vector< std::function< std::vector<Produce> (const Player& p) > > > getProduces)
        : sideA_{true},
          numCompleted_{0},
          name_{name},
          costs_{costs},
          getProduces_{getProduces}
    {
    }
    Wonder() : name_{"INVALID WONDER"}
    {
    }

    void setSide(bool sideA) { sideA_ = sideA; }

    void build() { ++numCompleted_; }
    bool isFull() const { return numCompleted_ == costs_[!sideA_].size(); }

    bool isSideA() const { return sideA_; }
    size_t getNumCompleted() const { return numCompleted_; }
    std::string getName() const { return name_; }
    std::vector<Produce> getCost() const { return costs_[!sideA_][numCompleted_]; }
    std::vector<Produce> getProduce(const Player& p) const {
        std::vector<Produce> produce;
        for (size_t i=0; i<=numCompleted_; ++i) {
            std::vector<Produce> thisProduce = getProduces_[!sideA_][i](p);
            produce.insert(produce.end(), thisProduce.begin(), thisProduce.end());
        }
        return produce;
    }
    std::vector<Produce> getProduceFromNext(const Player& p) const { return getProduces_[!sideA_][numCompleted_+1](p); }

private:
    bool sideA_;
    size_t numCompleted_;

    std::string name_;
    // side, then stage
    std::vector< std::vector< std::vector<Produce> > > costs_;
    // Note: For getProduces_, stages are 1 indexed; stage 0 is the resource given at start
    std::vector< std::vector< std::function< std::vector<Produce> (const Player& p) > > > getProduces_;
};

inline std::ostream& operator<< (std::ostream& o, const Wonder& w) {
    return o << w.getName();
}

#endif//WONDER_H
