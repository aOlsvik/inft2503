//
// Created by aleks on 17.10.2023.
//


#include "Set.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

Set::Set() {
    elements = std::vector<int>();
}

Set::Set(const std::vector<int> &elements_) : elements(elements_) {}

Set Set::operator+(const Set &other) const {
    return Set();
}


Set &Set::operator+=(int element) {
    if(std::find(elements.begin(), elements.end(), element) != elements.end()){
        return *this;
    }
    elements.emplace_back(element);
    return *this;
}

Set &Set::operator=(const Set &other) {
    elements = other.elements;
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Set &set) {
    out << "{";
    for(auto i = set.elements.begin(); i != set.elements.end(); ++i){
        out << *i;
        if(i != set.elements.end() - 1){
            out << ", ";
        }
    }
    out << "}";
    return out;
}






