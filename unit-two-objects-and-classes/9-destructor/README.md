## Program

```cpp
// destructor.cpp
// Demonstrates destructors in C++
#include <iostream>

class Resource {
public:
    Resource() {
        std::cout << "Resource acquired" << std::endl;
    }
    ~Resource() {
        std::cout << "Resource released" << std::endl;
    }
};

int main() {
    Resource r;
    return 0;
}
```

## Output

```
Resource acquired
Resource released
```

## Detailed Explanation

- The `Resource` class has a constructor and a destructor.
- The constructor prints a message when a `Resource` object is created.
- The destructor prints a message when the object goes out of scope or is destroyed.
- Destructors are used to release resources and perform cleanup.

## Edge Cases

### 1. Destructor and dynamic allocation
```cpp
Resource* r = new Resource();
delete r; // Destructor called
```
- Destructors are called when objects are deleted.

### 2. Destructor and arrays
```cpp
Resource* arr = new Resource[3];
delete[] arr; // Destructor called for each element
```
- Use `delete[]` for arrays to call destructors for all elements.

### 3. Virtual destructor
```cpp
class Base { public: virtual ~Base() {} };
class Derived : public Base { public: ~Derived() {} };
Base* b = new Derived();
delete b; // Both destructors called
```
- Use virtual destructors in base classes for proper cleanup in inheritance.

### 4. Destructor and exceptions
```cpp
class Demo {
public:
    ~Demo() { throw 1; } // Not recommended
};
```
- Throwing exceptions from destructors is dangerous and should be avoided. 