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

Set::Set(const std::vector<int> &elements_) {
    elements = std::vector<int>();
    for(auto i = elements_.begin(); i != elements_.end(); i++){
        if(std::find(elements.begin(), elements.end(), *i) == elements.end()){
            elements.emplace_back(*i);
        }
    }
}

Set Set::operator+(const Set &other) const {
    Set set1(elements);

    for(auto i = other.elements.begin(); i != other.elements.end(); i++){
        if(std::find(elements.begin(), elements.end(), *i) == elements.end()){
            set1+=*i;
        }
    }
    return set1;
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






