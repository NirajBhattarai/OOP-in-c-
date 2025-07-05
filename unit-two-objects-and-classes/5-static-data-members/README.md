# Static Data Members

Static data members are shared among all objects of a class. They are declared with the `static` keyword and exist independently of any object instance. 

## Program

```cpp
// static-data-members.cpp
// Demonstrates static data members in C++
#include <iostream>

class Counter {
public:
    static int count;
    Counter() { ++count; }
};

int Counter::count = 0;

int main() {
    Counter a, b, c;
    std::cout << "Count: " << Counter::count << std::endl;
    return 0;
}
```

## Output

```
Count: 3
```

## Detailed Explanation

- `static int count;` is a static data member, shared by all objects of the class.
- It is defined outside the class with `int Counter::count = 0;`.
- Each time a `Counter` object is created, the constructor increments `count`.
- After creating three objects, `Counter::count` is 3.
- Static data members exist independently of any object instance and can be accessed using the class name.

## Edge Cases

### 1. Static member initialization order
```cpp
class Demo {
public:
    static int x;
};
int Demo::x = 5;
```
- Static members must be defined outside the class. If not, linker errors occur.

### 2. Modifying static members through objects
```cpp
Counter a, b;
a.count = 10;
std::cout << b.count << std::endl; // Prints 10
```
- Modifying a static member through one object affects all objects.

### 3. Const static members
```cpp
class Demo {
public:
    static const int x = 42;
};
```
- Const static integral members can be initialized inside the class.

### 4. Static members in inheritance
```cpp
class Base { public: static int x; };
class Derived : public Base {};
int Base::x = 1;
Derived d;
d.x = 5;
std::cout << Base::x << std::endl; // Prints 5
```
- Static members are shared across the inheritance hierarchy. 