//
// Created by Aleksander Olsvik on 19.09.2023.
//
#include <iostream>
// inkluderer Circle fra taska.cpp
#include "../include/taskA.hpp"

using namespace std;

int main() {
    // variabel av typen Circle
    Circle circle(5);

    // Area er en int
    int area = circle.get_area();
    // skriver ut arealet
    cout << "Arealet er lik " << area << endl;

    // henter omkrets fra circle
    double circumference = circle.get_circumference();
    cout << "Omkretsen er lik " << circumference << endl;
}