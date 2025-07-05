# Derived Class Constructor

A derived class constructor initializes its own members and can also call the base class constructor to initialize inherited members. In C++, the base class constructor is called using an initializer list in the derived class constructor. 

## Program

```cpp
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
```

## Output

```
Person constructor: Alice
Student constructor: ID 101
```

## Detailed Explanation

- The `Person` class has a constructor that takes a name and prints a message.
- The `Student` class is derived from `Person` and has its own constructor that takes a name and an ID.
- The `Student` constructor uses an initializer list to call the `Person` constructor, ensuring the base part of the object is initialized first.
- In `main()`, creating a `Student` object prints both constructor messages, showing the order of construction: base class first, then derived class. 

## Edge Cases

### 1. Base class without default constructor
```cpp
class Base { public: Base(int) {} };
class Derived : public Base {
public:
    Derived() : Base(0) {} // Must explicitly call Base(int)
};
```
- If the base class does not have a default constructor, the derived class must explicitly call a base constructor.

### 2. Order of initialization
```cpp
class Base { public: Base() { std::cout << "Base"; } };
class Derived : public Base {
    int x;
public:
    Derived() : x(5) { std::cout << "Derived"; }
};
```
- Base class is always initialized before derived class members, regardless of order in initializer list.

### 3. Member initialization order
```cpp
class Derived {
    int a;
    int b;
public:
    Derived() : b(2), a(1) {} // a is initialized before b, order in class definition matters
};
```
- Members are initialized in the order they are declared in the class, not the order in the initializer list. 