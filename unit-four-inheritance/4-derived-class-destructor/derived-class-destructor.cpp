// derived-class-destructor.cpp
// Demonstrates destructors in derived classes in C++
#include <iostream>

class Base {
public:
    ~Base() {
        std::cout << "Base destructor" << std::endl;
    }
};

class Derived : public Base {
public:
    ~Derived() {
        std::cout << "Derived destructor" << std::endl;
    }
};

int main() {
    Derived d;
    return 0;
} 