# Virtual Base Classes and Abstract Classes

A virtual base class is used in multiple inheritance to prevent multiple copies of a base class. An abstract class is a class with at least one pure virtual function and cannot be instantiated directly. 

## Program

```cpp
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
```

## Output

```
Concrete implementation
Base class
```

## Detailed Explanation

- The `Abstract` class has a pure virtual function, making it an abstract class that cannot be instantiated directly.
- The `Concrete` class inherits from `Abstract` and provides an implementation for `display()`, so it can be instantiated.
- The `Base` class is used as a virtual base class for `Derived1` and `Derived2`.
- `MostDerived` inherits from both `Derived1` and `Derived2`. Because `Base` is a virtual base, only one `Base` subobject exists in `MostDerived`.
- In `main()`, a `Concrete` object calls `display()`, and a `MostDerived` object calls `show()` from the single `Base` subobject. 

## Edge Cases

### 1. Instantiating an abstract class
```cpp
class Abstract { public: virtual void f() = 0; };
// Abstract a; // Error: cannot instantiate abstract class
```
- Abstract classes cannot be instantiated directly.

### 2. Not overriding pure virtual function
```cpp
class Abstract { public: virtual void f() = 0; };
class Derived : public Abstract {};
// Derived d; // Error: Derived is still abstract
```
- If a derived class does not override all pure virtual functions, it is also abstract.

### 3. Virtual inheritance ambiguity
```cpp
class A { public: int x; };
class B : virtual public A {};
class C : virtual public A {};
class D : public B, public C {};
D d; d.x = 5; // OK: only one x
```
- Virtual inheritance ensures only one instance of the base class member exists in the most derived class. 