// base-and-derived-class.cpp
// Demonstrates base and derived classes in C++
#include <iostream>

class Vehicle {
public:
    void start() const {
        std::cout << "Vehicle starts" << std::endl;
    }
};

class Car : public Vehicle {
public:
    void drive() const {
        std::cout << "Car drives" << std::endl;
    }
};

int main() {
    Car c;
    c.start(); // Inherited from Vehicle
    c.drive(); // Defined in Car
    return 0;
} 