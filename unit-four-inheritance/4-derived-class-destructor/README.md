# Derived Class Destructor

A derived class destructor is responsible for cleaning up resources used by the derived class. In C++, destructors are called in the reverse order of construction: the derived class destructor runs first, then the base class destructor. 

## Program

```cpp
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
```

## Output

```
Derived destructor
Base destructor
```

## Detailed Explanation

- The `Base` class has a destructor that prints a message.
- The `Derived` class inherits from `Base` and has its own destructor.
- When a `Derived` object is destroyed, the `Derived` destructor runs first, then the `Base` destructor.
- This demonstrates the order of destructor calls: derived class first, then base class, ensuring proper cleanup. 

## Edge Cases

### 1. Non-virtual destructor in base class
```cpp
class Base { public: ~Base() {} };
class Derived : public Base { public: ~Derived() {} };
Base* b = new Derived();
delete b; // Only Base destructor called, Derived destructor not called
```
- If the base class destructor is not virtual, deleting a derived object through a base pointer leads to undefined behavior.

### 2. Virtual destructor in base class
```cpp
class Base { public: virtual ~Base() {} };
class Derived : public Base { public: ~Derived() {} };
Base* b = new Derived();
delete b; // Both destructors called
```
- Always declare a virtual destructor in base classes meant for inheritance. 