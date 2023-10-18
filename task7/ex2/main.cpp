#include <iostream>
#include "Set.hpp"
#include <vector>

int main() {
    Set s1(std::vector<int>({2, 7}));
    Set s2(std::vector<int>({1, 1, 2, 3}));
    Set s3(std::vector<int>({4, 3}));
    Set s4(std::vector<int>({2, 4}));
    Set empty;

    std::cout << "Empty set: " << empty << std::endl;
    std::cout << "Set with elements {1, 1, 2, 3}: " << s2 << std::endl;
    std::cout << "Union of {2, 7} & {4, 3}: " << s1 + s3 << std::endl;
    std::cout << "Union of {4, 3} & {4, 2}: " << s3 + s4 << std::endl;
    s3+=3;
    std::cout << "Set {4, 3} plus element 3: " << s3 << std::endl;
    s3+=5;
    std::cout << "Set {4, 3} plus element 5: " << s3 <<  std::endl;
    std::cout << "Setting a Set equal to another: " << empty << " = " << s2 << std::endl;
    empty = s2;
    std::cout << "Empty set is now: " << empty << std::endl;
    return 0;
}
