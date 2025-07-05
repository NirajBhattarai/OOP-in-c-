// derived-class-constructor.cpp
// Demonstrates constructors in derived classes in C++
#include <iostream>

class Person {
public:
    Person(const std::string& name) {
        std::cout << "Person constructor: " << name << std::endl;
    }
};

class Student : public Person {
public:
    Student(const std::string& name, int id) : Person(name) {
        std::cout << "Student constructor: ID " << id << std::endl;
    }
};

int main() {
    Student s("Alice", 101);
    return 0;
} 