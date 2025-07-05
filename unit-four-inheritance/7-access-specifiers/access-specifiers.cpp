// access-specifiers.cpp
// Demonstrates public, private, and protected access specifiers in C++
#include <iostream>

class Parent {
public:
    int publicVar;
protected:
    int protectedVar;
private:
    int privateVar;
public:
    Parent() : publicVar(1), protectedVar(2), privateVar(3) {}
    void show() const {
        std::cout << "Parent: public=" << publicVar << ", protected=" << protectedVar << ", private=" << privateVar << std::endl;
    }
};

class Child : public Parent {
public:
    void showChild() const {
        std::cout << "Child: public=" << publicVar << ", protected=" << protectedVar << std::endl;
        // privateVar is not accessible here
    }
};

int main() {
    Child c;
    c.show();
    c.showChild();
    // c.publicVar is accessible
    // c.protectedVar and c.privateVar are not accessible here
    return 0;
} 