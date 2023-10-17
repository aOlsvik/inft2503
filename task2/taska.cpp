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

    int table[4] = {i, j, *p, *q};
    const char* names[4] = {"i", "j", "p", "q"};

    for(int k = 0; k < 4; k++){
        cout << names[k] << ": " << "Address:" << &table[k] << " Value:" << table[k] << endl;
    }
}