# Single Inheritance and Multiple Inheritance

Single inheritance means a class inherits from one base class. Multiple inheritance means a class inherits from more than one base class. C++ supports both, allowing complex relationships between classes. 

## Program

```cpp
// single-and-multiple-inheritance.cpp
// Demonstrates single and multiple inheritance in C++
#include <iostream>

class A {
public:
    void showA() const {
        std::cout << "Class A" << std::endl;
    }
};

class B {
public:
    void showB() const {
        std::cout << "Class B" << std::endl;
    }
};

class Single : public A {};

class Multiple : public A, public B {};

int main() {
    Single s;
    s.showA();
    Multiple m;
    m.showA();
    m.showB();
    return 0;
}
```

## Output

```
Class A
Class A
Class B
```

## Detailed Explanation

- The `Single` class inherits from one base class (`A`), demonstrating single inheritance.
- The `Multiple` class inherits from two base classes (`A` and `B`), demonstrating multiple inheritance.
- In `main()`, a `Single` object can use methods from `A`, and a `Multiple` object can use methods from both `A` and `B`.
- This shows how C++ supports both single and multiple inheritance, allowing a class to inherit from one or more base classes. 

## Edge Cases

### 1. Ambiguity in multiple inheritance
```cpp
class A { public: void show() { std::cout << "A"; } };
class B { public: void show() { std::cout << "B"; } };
class C : public A, public B {};
C c; c.show(); // Error: ambiguous
```
- If two base classes have methods with the same name, the derived class must specify which one to use.

### 2. Diamond problem
```cpp
class A { public: void show() { std::cout << "A"; } };
class B : public A {};
class C : public A {};
class D : public B, public C {};
// D d; d.show(); // Error: ambiguous
```
- Multiple inheritance can cause ambiguity if not handled with virtual inheritance.

### 3. Virtual inheritance to solve diamond problem
```cpp
class A { public: void show() { std::cout << "A"; } };
class B : virtual public A {};
class C : virtual public A {};
class D : public B, public C {};
D d; d.show(); // OK: only one A
```
- Virtual inheritance ensures only one instance of the base class exists in the derived class. 