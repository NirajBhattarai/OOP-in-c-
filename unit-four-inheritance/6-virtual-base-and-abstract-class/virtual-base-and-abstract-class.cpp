// virtual-base-and-abstract-class.cpp
// Demonstrates virtual base classes and abstract classes in C++
#include <iostream>

class Abstract {
public:
    virtual void display() const = 0; // Pure virtual function
};

class Concrete : public Abstract {
public:
    void display() const override {
        std::cout << "Concrete implementation" << std::endl;
    }
};

class Base {
public:
    void show() const {
        std::cout << "Base class" << std::endl;
    }
};

class Derived1 : virtual public Base {};
class Derived2 : virtual public Base {};
class MostDerived : public Derived1, public Derived2 {};

int main() {
    Concrete c;
    c.display();
    MostDerived md;
    md.show(); // Only one Base subobject
    return 0;
} 