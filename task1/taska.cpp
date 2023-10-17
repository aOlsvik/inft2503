#include <iostream>

using namespace std;

int main() {
    double x1, x2, x3, x4, x5;
    int u10=0;
    int m10_20 = 0;
    int o20 = 0;

    cout << "Skriv inn 5 temperaturer" << endl;
    cout << "Temperatur 1:";
    cin >> x1;
    if(x1>20) o20++;
    else if (x1<10) u10++;
    else m10_20++;

    cout << "Temperatur 2:";
    cin >> x2;
    if(x2>20) o20++;
    else if (x2<10) u10++;
    else m10_20++;

    cout << "Temperatur 3:";
    cin >> x3;
    if(x3>20) o20++;
    else if (x3<10) u10++;
    else m10_20++;

    cout << "Temperatur 4:";
    cin >> x4;
    if(x4>20) o20++;
    else if (x4<10) u10++;
    else m10_20++;

    cout << "Temperatur 5:";
    cin >> x5;
    if(x5>20) o20++;
    else if (x5<10) u10++;
    else m10_20++;

    cout << "Antall under 10: " << u10 << endl;
    cout << "Antall mellom 10 og 20: " << m10_20 << endl;
    cout << "Antall over 20: " << o20 << endl;

    return 0;
}
