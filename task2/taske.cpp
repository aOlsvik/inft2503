//
// Created by Aleksander Olsvik on 12.09.2023.
//
#include "iostream"
using namespace std;

int find_sum(const int *table, int length);

int main() {
    int table[20];
    for (int i = 0; i < 20; ++i) {
        table[i] = i+1;
    }

    int *pointer = table;
    cout << "Sum of first 10 numbers: " << find_sum(pointer, 10) << endl;

    pointer = &table[10];
    cout << "Sum of the next five numbers: " << find_sum(pointer, 5) << endl;

    pointer = &table[end(table) - begin(table) - 5];
    cout << "Sum of the last five numbers: " << find_sum(pointer, 5) << endl;

}

int find_sum(const int *table, int length) {
    int sum = 0;
    for(int i = 0; i<length; i++) {
        sum+=*table;
        table++;
    }
    return sum;
}