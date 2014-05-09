#ifndef UTILITY_H
#define UTILITY_H
#include <vector>

template<typename T>
std::vector< std::vector< std::vector<T> > > splitIntoTwo(typename std::vector<T>::const_iterator begin, typename std::vector<T>::const_iterator end);

template<typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v);


#include "Utility-private.hpp"


#endif//UTILITY_H
