# Base Class and Derived Class

A base class is a general class that defines common properties and behaviors. A derived class inherits from the base class and can add or override functionality. In C++, inheritance is specified using a colon and an access specifier (public, protected, or private). 

## Program

```cpp
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
```

## Output

```
Vehicle starts
Car drives
```

## Detailed Explanation

- The `Vehicle` class is a base class with a method `start()`.
- The `Car` class is a derived class that inherits from `Vehicle` and adds its own method `drive()`.
- In `main()`, a `Car` object is created. It can call both `start()` (from `Vehicle`) and `drive()` (from `Car`).
- This shows how a derived class can extend the functionality of a base class by adding new methods. 

## Edge Cases

### 1. Method hiding
```cpp
class Base { public: void show() { std::cout << "Base"; } };
class Derived : public Base { public: void show() { std::cout << "Derived"; } };
Derived d; d.show(); // Prints "Derived"
Base* b = &d; b->show(); // Prints "Base"
```
- If a derived class defines a method with the same name as the base, it hides the base method (unless virtual).

### 2. Object slicing
```cpp
class Base { public: int x; };
class Derived : public Base { public: int y; };
Base b = Derived(); // Only x is copied, y is lost
```
- Assigning a derived object to a base object slices off the derived part.

### 3. Accessing protected members
```cpp
class Base { protected: int x; };
class Derived : public Base { public: void setX(int v) { x = v; } };
```
- Derived classes can access protected members, but not private members, of the base class. 