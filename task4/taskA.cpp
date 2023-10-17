//
// Created by Aleksander Olsvik on 20.09.2023.
//

#include "vector"
#include "iostream"
#include "algorithm"
using namespace std;

int main() {
    vector<double> doubles;

    for(int i=0; i<5; i++){
        doubles.emplace_back((3*i)/(i + 1));
    }

    cout << "front: " << doubles.front() << endl;
    cout << "back: " << doubles.back() << endl;

    doubles.emplace(doubles.begin() + 1, 2.34);

    cout << "front after emplace begin+1: " << doubles.front() << endl;

    auto it = find(doubles.begin(), doubles.end(), 2.43);
    auto it2 = find(doubles.begin(), doubles.end(), 2.34);

    if(it != doubles.end()) cout << "found " << (*it) << endl;
    else cout << "Couldn't find 2.43" << endl;

    if(it2 != doubles.end()) cout << "found " << (*it2) << endl;
    else cout << "Couldn't find 2.34" << endl;
}