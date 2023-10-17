//
// Created by Aleksander Olsvik on 11.09.2023.
//

#include <iostream>

using namespace std;

int main(){
    int i = 3;
    int j = 5;
    int *p = &i;
    int *q = &j;


    const char* names[4] = {"i", "j", "p", "q"};

    // verdien til p, altså i, endres til 7
    *p = 7;

    // verdien til q, altså j, plusses på 4, slik at j=9
    *q += 4;

    // verdien som q peker på endres til verdien som p peker på (i=7) pluss 1, altså 8
    *q = *p + 1;

    // p peker nå på q, altså j
    p = q;

    //forventer da at:
    // i = 7
    // j = 8
    // *p = j = 8
    // *q = j = 8

    int table[4] = {i, j, *p, *q};
    for(int k = 0; k < 4; k++){
        cout << names[k] << ": " << "Address:" << &table[k] << " Value:" << table[k] << endl;
    }

}