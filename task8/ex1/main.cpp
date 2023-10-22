#include <iostream>
#include <cmath>

// Template function for equal with template types
template <typename Type>
bool equal(Type a, Type b) {
    std::cout << "Using the template function for type " << typeid(a).name() << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    bool result = a == b;
    std::cout << "a == b: " << std::boolalpha << result << std::endl;
    return result;
}

// Function for equal with specific double values
bool equal(double a, double b) {
    std::cout << "Using the function for double" << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    // Check if the difference is less than 0.0001
    bool result = std::fabs(a - b) < 0.00001;
    std::cout << "a == b: " << std::boolalpha << result << std::endl;
    return result;
}

int main() {
    {
        int a = 2;
        int b = 3;
        int c = 2;
        equal(a, b);
        equal(a, c);
    }

    double a = 0.5;
    double b = 0.5001;
    double c = 0.50001;
    equal(a, b);
    equal(a, c);
}