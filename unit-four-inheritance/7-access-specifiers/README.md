# Public, Private, and Protected Access and Control

Access specifiers control the visibility of class members. Public members are accessible from anywhere, protected members are accessible in derived classes, and private members are accessible only within the class itself. 

## Program

```cpp
// access-specifiers.cpp
// Demonstrates public, private, and protected access specifiers in C++
#include <iostream>

class Parent {
public:
    int publicVar;
protected:
    int protectedVar;
private:
    int privateVar;
public:
    Parent() : publicVar(1), protectedVar(2), privateVar(3) {}
    void show() const {
        std::cout << "Parent: public=" << publicVar << ", protected=" << protectedVar << ", private=" << privateVar << std::endl;
    }
};

class Child : public Parent {
public:
    void showChild() const {
        std::cout << "Child: public=" << publicVar << ", protected=" << protectedVar << std::endl;
        // privateVar is not accessible here
    }
};

int main() {
    Child c;
    c.show();
    c.showChild();
    // c.publicVar is accessible
    // c.protectedVar and c.privateVar are not accessible here
    return 0;
}
```

## Output

```
Parent: public=1, protected=2, private=3
Child: public=1, protected=2
```

## Detailed Explanation

- The `Parent` class has public, protected, and private members.
- The `Child` class inherits from `Parent`.
- In `main()`, a `Child` object can access and print the public and protected members, but not the private member.
- The `show()` method in `Parent` can access all members, but `showChild()` in `Child` can only access public and protected members.
- This demonstrates how access specifiers control visibility and accessibility in inheritance. 

## Edge Cases

### 1. Private inheritance
```cpp
class Base { public: int x; };
class Derived : private Base {};
Derived d;
// d.x; // Error: x is private in Derived
```
- Public members of the base class become private in the derived class if inherited privately.

### 2. Protected inheritance
```cpp
class Base { public: int x; };
class Derived : protected Base {};
Derived d;
// d.x; // Error: x is protected in Derived
```
- Public members of the base class become protected in the derived class if inherited as protected.

### 3. Accessing protected members from outside
```cpp
class Base { protected: int x; };
Base b;
// b.x = 5; // Error: x is protected
```
- Protected members are not accessible from outside the class, only from derived classes. 