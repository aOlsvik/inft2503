//
// Created by aleks on 07.09.2023.
//

#include <iostream>
#include <fstream>

using namespace std;

void read_temperatures(double temperatures[], int length);

int main() {
    setlocale(LC_ALL, "C");
    int length = 5;
    double temperatures[length];

    read_temperatures(temperatures, length);

    int o20 = 0;
    int m10_20 = 0;
    int u10 = 0;
    int i = 0;
    while (i < length){
        cout << "Temperatur " << i+1 << ": ";
        cout << temperatures[i] << endl;
        if(temperatures[i] > 20) o20++;
        else if(temperatures[i] < 10) u10++;
        else m10_20++;
        i++;
    }

    cout << "\nAntall under 10: " << u10 << endl;
    cout << "Antall mellom 10 og 20: " << m10_20 << endl;
    cout << "Antall over 20: " << o20 << endl;
    return 0;
}

void read_temperatures(double temperatures[], int length) {
    // her plasserer du koden i funksjonen, vi sier at vi definerer funksjonen
    ifstream myFile("temperatures.txt");
    int i = 0;
    while (i < length){
        myFile >> temperatures[i];
        i++;
    }
    myFile.close();
}
