## Program

```cpp
// constructor.cpp
// Demonstrates constructors in C++
#include <iostream>

class Box {
private:
    int length;
public:
    Box() : length(0) {
        std::cout << "Default constructor" << std::endl;
    }
    Box(int l) : length(l) {
        std::cout << "Parameterized constructor" << std::endl;
    }
    void print() const {
        std::cout << "Length: " << length << std::endl;
    }
};

int main() {
    Box b1;
    Box b2(10);
    b1.print();
    b2.print();
    return 0;
}
```

## Output

```
Default constructor
Parameterized constructor
Length: 0
Length: 10
```

## Detailed Explanation

- The `Box` class has two constructors: a default constructor and a parameterized constructor.
- `Box b1;` calls the default constructor, initializing `length` to 0.
- `Box b2(10);` calls the parameterized constructor, initializing `length` to 10.
- Constructors are used to initialize objects in different ways.

## Edge Cases

### 1. Overloading constructors
```cpp
class Demo {
public:
    Demo() {}
    Demo(int) {}
};
Demo d1;
Demo d2(5);
```
- You can define multiple constructors with different parameter lists.

### 2. Delegating constructors (C++11)
```cpp
class Demo {
    int x;
public:
    Demo() : Demo(0) {}
    Demo(int x) : x(x) {}
};
```
- One constructor can call another constructor in the same class.

### 3. Explicit constructor
```cpp
class Demo {
public:
    explicit Demo(int) {}
};
Demo d1 = 5; // Error
Demo d2(5);  // OK
```
- The `explicit` keyword prevents implicit conversions.

### 4. Private constructor (Singleton pattern)
```cpp
class Singleton {
private:
    Singleton() {}
public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }
};
```
- Private constructors can be used to restrict object creation (e.g., Singleton pattern).
``` 