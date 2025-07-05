# Introduction to Inheritance

Inheritance is a fundamental concept in object-oriented programming (OOP) that allows a class (derived class) to inherit properties and behaviors (data members and member functions) from another class (base class). Inheritance promotes code reuse, extensibility, and the creation of hierarchical relationships between classes. 

## Program

```cpp
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
```

## Output

```
Animal speaks
Dog barks
```

## Detailed Explanation

- The `Animal` class defines a method `speak()` that prints "Animal speaks".
- The `Dog` class is derived from `Animal` using public inheritance (`class Dog : public Animal`).
- `Dog` inherits all public members of `Animal`, so it can use `speak()` as if it were its own method.
- `Dog` also defines its own method `bark()`.
- In `main()`, a `Dog` object is created. It calls `speak()` (inherited from `Animal`) and `bark()` (defined in `Dog`).
- This demonstrates how inheritance allows a derived class to reuse and extend the functionality of a base class. 

## Edge Cases

### 1. Inheriting from a class with private members
```cpp
class Base {
private:
    int secret;
public:
    Base() : secret(42) {}
};
class Derived : public Base {
public:
    void tryAccess() {
        // secret is not accessible here
        // std::cout << secret; // Error
    }
};
```
- Private members of the base class are not accessible in the derived class.

### 2. Inheriting from a class with a deleted or private constructor
```cpp
class Base {
private:
    Base() {} // Private constructor
};
class Derived : public Base {
    // Error: Base's constructor is not accessible
};
```
- If the base class constructor is private or deleted, the derived class cannot be instantiated.

### 3. Diamond problem (multiple inheritance)
```cpp
class A { public: void show() { std::cout << "A"; } };
class B : public A {};
class C : public A {};
class D : public B, public C {};
// D d; d.show(); // Error: ambiguous
```
- Multiple inheritance can cause ambiguity if two base classes inherit from the same ancestor.

### 4. Slicing
```cpp
class Base { public: int x; };
class Derived : public Base { public: int y; };
Base b = Derived();
// b only has x, y is sliced off
```
- Assigning a derived object to a base object slices off the derived part. 