#include <ostream>
//#include "Utility.hpp"
//#include <cassert>

template<typename T>
std::vector< std::vector< std::vector<T> > > split(
        size_t n,
        typename std::vector<T>::const_iterator begin,
        typename std::vector<T>::const_iterator end)
{
    // Start with one option: n empty paritions
    if (begin == end) {
        return std::vector< std::vector< std::vector<T> > > { std::vector< std::vector<T> >(n, std::vector<T>{}) };
    }
    std::vector< std::vector< std::vector<T> > > ret{};
    // outer: list of ways to do it
    // middle: two sides
    // inner: produce in each side
    //
    // for each in outer
    // add two to new, one with it in the first and one with it in the second
    
    typename std::vector<T>::const_iterator beginPlusOne{begin};
    ++beginPlusOne;
    const std::vector< std::vector< std::vector<T> > > payRest = splitIntoTwo<T>(beginPlusOne, end);

    for(const std::vector< std::vector<T> >& pay : payRest) {
        for(size_t i=0; i<n; ++i) {
            std::vector< std::vector<T> > payCopy = pay;
            payCopy[i].push_back(*begin);
            ret.push_back(payCopy);
        }
    }
    return ret;
}

template<typename T>
std::vector< std::vector< std::vector<T> > > splitIntoTwo(
        typename std::vector<T>::const_iterator begin,
        typename std::vector<T>::const_iterator end)
{
    // Start with one option: two empty paritions
    if (begin == end) {
        return std::vector< std::vector< std::vector<T> > > { std::vector< std::vector<T> >{std::vector<T>{}, std::vector<T>{}} };
    }
    std::vector< std::vector< std::vector<T> > > ret{};
    if (begin != end) {
        // outer: list of ways to do it
        // middle: two sides
        // inner: produce in each side
        //
        // for each in outer
        // add two to new, one with it in the first and one with it in the second
        
        typename std::vector<T>::const_iterator beginPlusOne{begin};
        ++beginPlusOne;
        const std::vector< std::vector< std::vector<T> > > payRest = splitIntoTwo<T>(beginPlusOne, end);

        for(std::vector< std::vector<T> > payRight : payRest) {
            std::vector< std::vector<T> > payLeft = payRight;
            payRight[0].push_back(*begin);
            payLeft[1].push_back(*begin);
            ret.push_back(payRight);
            ret.push_back(payLeft);
        }
    }
    return ret;
}

//template<typename T>
//static std::ostream& operator<<(std::ostream& o, const std::vector<T>& v) {
//    copy(v.begin(), v.end(), infix_std::ostream_iterator<T>(o, ", "));
//    //o << v[0] << std::endl;
//    return o;
//}

template<typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
    int last = v.size() - 1;
    out << "{";
    for(int i = 0; i < last; i++)
        out << v[i] << ", ";
    if(last >= 0) out << v[last];
    out << "}";
    return out;
}

//template<typename T>
//static std::ostream& printN(std::ostream& out, size_t n, const T& t)
//{
//    for(size_t i=0; i < n; ++i) {
//        out << t;
//    }
//    return out;
//}
//
//static size_t spaces = 0;
//template<typename T>
//static std::ostream& operator<< (std::ostream& out, const std::vector<T>& v)
//{
//    //printN(out, spaces, '-');
//    out << '{' << std::endl;
//    spaces += 4;
//    for (const T& it : v) {
//        printN(out, spaces, ' ');
//        out << it << std::endl;
//    }
//    spaces -= 4;
//    printN(out, spaces, ' ');
//    out << '}' << std::endl;
//
//    return out;
//}


//static size_t spaces = 0;
//template<typename T>
//static std::ostream& output(std::ostream& out, const T& i)
//{
//    for (size_t j = 0; j < spaces; ++j) {
//        out << '-';
//    }
//    //spaces += 4;
//    out << i;
//    //spaces -= 4;
//    //out << std::endl;
//    return out;
//}
//
//template<typename T>
//std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
//
//    for(size_t i = 0; i < v.size(); i++) {
//        cout << '{';// << std::endl;
//        //output(out, '{');
//        //spaces += 2;
//        output(out, v[i]);
//        //spaces -= 2;
//        output(out, '}');
//    }
//    return out;
//}


//int main() {
//    //std::vector< std::vector< std::vector<int> > > expected1{ std::vector< std::vector<int> > {std::vector<int>{1
//    std::vector<int> test{1, 2, 3, 4, 5};
//    std::cout << (splitIntoTwo<int>(test.begin(), test.end()) == split<int>(2, test.begin(), test.end())) << std::endl;
//    //cout << splitIntoTwo<int>(test.begin(), test.end()) << std::endl;
//}
