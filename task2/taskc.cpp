//
// Created by aleks on 11.09.2023.
//
#include <iostream>
using namespace std;

/**
int a = 5;
int &b;
int *c;
c = &b;
*a = *b + *c;
&b = 2;
**/

int main() {
    int a = 5;
    // b blir definert som en referanse, men ble ikke gitt en verdi å referere til
    int &b = a;
    int *c;
    c = &b;
    // Siden a er en int, ikke en peker, kan ikke *a brukes
    // b er en referanse / alias for a, så *b er det samme som *a og fungerer heller ikke
    a = b + *c;
    // Referanser kan ikke endres, så &b = 2 fungerer ikke
    // b = 2 fungerer, og vil endre verdien til a til 2
    b = 2;
}

