// constructor.cpp
// Demonstrates constructors in C++
#include <iostream>

class Box {
private:
    int length;
public:
    Box() : length(0) {
        std::cout << "Default constructor" << std::endl;
    }
    Box(int l) : length(l) {
        std::cout << "Parameterized constructor" << std::endl;
    }
    void print() const {
        std::cout << "Length: " << length << std::endl;
    }
};

int main() {
    Box b1;
    Box b2(10);
    b1.print();
    b2.print();
    return 0;
} 