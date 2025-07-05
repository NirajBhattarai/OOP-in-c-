// introduction-to-objects-and-classes.cpp
// Demonstrates basic class and object creation in C++
#include <iostream>

class Person {
public:
    void greet() const {
        std::cout << "Hello!" << std::endl;
    }
};

int main() {
    Person p; // Object of class Person
    p.greet();
    return 0;
} 