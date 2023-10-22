#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

ostream &operator<<(ostream &out, const vector<int> &table) {
    for (auto &e : table)
        out << e << " ";
    return out;
}

int main() {
    vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};
    cout << "v1: " << v1 << endl;
    vector<int> v2 = {2, 3, 12, 14, 24};
    cout << "v2: " << v2 << endl;

    cout << "\ntask a" << endl;
    auto first_15 = find_if(v1.begin(), v1.end(), [](int element) {
        return element > 15;
    });

    if(first_15 != v1.end()){
        cout << "Første element med verdi over 15 i v1 er " << *first_15 << endl;
    }
    else {
        cout << "Didn't find an element with value above 15 in v1: " << v1 << endl;
    }

    cout << "\ntask b" << endl;
    bool approx_equal = equal(v1.begin(), v1.begin() + 5, v2.begin(), [](int a, int b){
        return abs(a-b) <= 2;
    });

    cout << "Intervallene v1[0:5] og v2 er 'omtrent lik': " << boolalpha << approx_equal << endl;

    // will not compile due to different lengths of the intervals
    bool approx_equal_invalid = equal(v1.begin(), v1.begin() + 4, v2.begin(),  [](int a, int b){
        return abs(a-b) < 2;
    });

    cout << "Intervallene v1[0:4] og v2 er 'omtrent lik': " << boolalpha << approx_equal_invalid << endl;

    cout << "\ntask c" << endl;
    vector<int> copy;
    copy.resize(v1.size());
    replace_copy_if(v1.begin(), v1.end(), copy.begin(), [](int number){
        return number % 2 != 0;
    }, 100);
    cout << "Original v1: " << v1 << endl;
    cout << "Kopi av v1 hvor oddetall -> 100: " << copy << endl;


}
