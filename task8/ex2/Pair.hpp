// Pair.hpp

#ifndef EX2_PAIR_HPP
#define EX2_PAIR_HPP

#include <stdexcept>

template <typename Type1, typename Type2>
class Pair {
public:
    Type1 first;
    Type2 second;
    Pair<Type1, Type2>(Type1 p1_, Type2 p2_) : first(p1_), second(p2_) {}

    Pair operator+(const Pair &p2) const {
        if (typeid(this->first) != typeid(p2.first)) {
            throw std::invalid_argument("First elements of pairs don't match");
        } else if (typeid(this->second) != typeid(p2.second)) {
            throw std::invalid_argument("Second elements of pairs don't match");
        }
        Type1 first_element = this->first + p2.first;
        Type2 second_element = this->second + p2.second;
        return Pair<Type1, Type2>(first_element, second_element);
    }

    // forutsetter her at begge klassene har samme typer på de respektive delene av parene, og at
    // disse kan sammenlignes. Det største paret er det paret som har den største totale differansen
    bool operator>(const Pair &p2) const {
        if (typeid(this->first) != typeid(p2.first)) {
            throw std::invalid_argument("First elements of pairs don't match");
        } else if (typeid(this->second) != typeid(p2.second)) {
            throw std::invalid_argument("Second elements of pairs don't match");
        }
        double diff1 = this->first - p2.first;
        double diff2 = this->second - p2.second;
        double diff = diff1 + diff2;
        return diff > 0;
    }
};

#endif //EX2_PAIR_HPP
