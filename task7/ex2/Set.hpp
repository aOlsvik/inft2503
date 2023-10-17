//
// Created by aleks on 17.10.2023.
//

#ifndef EX2_SET_HPP
#define EX2_SET_HPP

#include <vector>
#include <iostream>

class Set {
public:
    std::vector<int> elements;
    Set();
    Set(const std::vector<int> &elements);
    Set(const Set &) = default;
    Set operator+(const Set &other) const;
    Set &operator +=(int element);
    Set &operator =(const Set &other);
    friend std::ostream &operator<<(std::ostream &os, const Set &set);
};


#endif //EX2_SET_HPP
