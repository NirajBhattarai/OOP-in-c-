// destructor.cpp
// Demonstrates destructors in C++
#include <iostream>

class Resource {
public:
    Resource() {
        std::cout << "Resource acquired" << std::endl;
    }
    ~Resource() {
        std::cout << "Resource released" << std::endl;
    }
};

int main() {
    Resource r;
    return 0;
} 