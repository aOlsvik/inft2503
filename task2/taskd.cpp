//
// Created by aleks on 11.09.2023.
//

#include "iostream"
using namespace std;

int main() {
    double number;
    double *pointer = &number;
    double &ref = number;

    // way 1
    number = 2.6;
    cout << "Number value after change: " << number << endl;

    // way 2
    *pointer = 7.8;
    cout << "Number value after pointer change: " << number << endl;

    // way 3
    ref = 4.1;
    cout << "Number value after ref change: " << number << endl;

}