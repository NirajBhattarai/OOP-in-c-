# Static Member Functions

Static member functions are functions that can be called on the class itself, not on a specific object. They can only access static data members and other static member functions. 

## Program

```cpp
// static-member-functions.cpp
// Demonstrates static member functions in C++
#include <iostream>

class Math {
public:
    static int add(int a, int b) {
        return a + b;
    }
};

int main() {
    std::cout << "Sum: " << Math::add(3, 4) << std::endl;
    return 0;
}
```

## Output

```
Sum: 7
```

## Detailed Explanation

- `static int add(int a, int b)` is a static member function.
- It can be called using the class name, e.g., `Math::add(3, 4)`.
- Static member functions can only access static data members and other static member functions.
- They do not have access to `this` pointer or non-static members.

## Edge Cases

### 1. Calling static member function from object
```cpp
Math m;
m.add(1, 2); // Valid, but not recommended. Prefer Math::add(1, 2)
```
- Static member functions can be called from objects, but should be called using the class name.

### 2. Accessing non-static members
```cpp
class Demo {
    int x;
public:
    static void f() {
        // x = 5; // Error: cannot access non-static member
    }
};
```
- Static member functions cannot access non-static members.

### 3. Static member functions and inheritance
```cpp
class Base { public: static void f() { std::cout << "Base"; } };
class Derived : public Base { public: static void f() { std::cout << "Derived"; } };
Derived::f(); // Prints "Derived"
Base::f();    // Prints "Base"
```
- Static member functions can be hidden in derived classes, but not overridden.

### 4. Static member function as callback
```cpp
void call(void (*f)()) { f(); }
class Demo {
public:
    static void hello() { std::cout << "Hello"; }
};
call(Demo::hello); // OK
```
- Static member functions can be used as function pointers. 