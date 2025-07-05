// static-member-functions.cpp
// Demonstrates static member functions in C++
#include <iostream>

class Math {
public:
    static int add(int a, int b) {
        return a + b;
    }
};

int main() {
    std::cout << "Sum: " << Math::add(3, 4) << std::endl;
    return 0;
} 