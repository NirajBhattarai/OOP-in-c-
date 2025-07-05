// single-and-multiple-inheritance.cpp
// Demonstrates single and multiple inheritance in C++
#include <iostream>

class A {
public:
    void showA() const {
        std::cout << "Class A" << std::endl;
    }
};

class B {
public:
    void showB() const {
        std::cout << "Class B" << std::endl;
    }
};

class Single : public A {};

class Multiple : public A, public B {};

int main() {
    Single s;
    s.showA();
    Multiple m;
    m.showA();
    m.showB();
    return 0;
} 