// introduction-to-inheritance.cpp
// Demonstrates basic inheritance in C++
#include <iostream>

class Animal {
public:
    void speak() const {
        std::cout << "Animal speaks" << std::endl;
    }
};

class Dog : public Animal {
public:
    void bark() const {
        std::cout << "Dog barks" << std::endl;
    }
};

int main() {
    Dog d;
    d.speak(); // Inherited from Animal
    d.bark();  // Defined in Dog
    return 0;
} 