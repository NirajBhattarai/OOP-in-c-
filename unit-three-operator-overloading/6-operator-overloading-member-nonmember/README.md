# Operator Overloading: Member and Nonmember Functions

Operators can be overloaded as member functions or nonmember (friend) functions. Member functions have access to the class's private data and are called on the left operand. Nonmember functions can be used when the left operand is not a class object or when access to private data is needed via friendship. 

## Program Explanation

This program demonstrates operator overloading with member and nonmember (friend) functions using a `Box` class:

- The `Box` class has a private integer member `length` and a constructor.
- The `operator+` is overloaded as a member function to add the lengths of two `Box` objects.
- The `operator-` is overloaded as a friend function to subtract the lengths of two `Box` objects.
- The `getLength()` method returns the length.
- In `main()`, two `Box` objects are created. The overloaded `+` and `-` operators are used, and the results are printed. 

## Program

```cpp
// operator-overloading-member-nonmember.cpp
// Demonstrates operator overloading with member and nonmember (friend) functions
#include <iostream>

class Box {
private:
    int length;
public:
    Box(int length) : length(length) {}
    // Member function overload for +
    Box operator+(const Box& other) const {
        return Box(length + other.length);
    }
    int getLength() const { return length; }
    // Friend function overloads
    friend Box operator-(const Box& a, const Box& b);
    friend Box& operator++(Box& b);      // Pre-increment
    friend Box operator++(Box& b, int);  // Post-increment
};

// Nonmember (friend) function for -
Box operator-(const Box& a, const Box& b) {
    return Box(a.length - b.length);
}
// Friend function for pre-increment
Box& operator++(Box& b) {
    ++b.length;
    return b;
}
// Friend function for post-increment
Box operator++(Box& b, int) {
    Box temp = b;
    ++b.length;
    return temp;
}

int main() {
    Box b1(10), b2(4);
    Box b3 = b1 + b2; // Member function
    Box b4 = b1 - b2; // Friend function
    std::cout << "b1 + b2 = " << b3.getLength() << std::endl;
    std::cout << "b1 - b2 = " << b4.getLength() << std::endl;
    std::cout << "Initial b1: " << b1.getLength() << std::endl;
    ++b1;
    std::cout << "After friend pre-increment (++b1): " << b1.getLength() << std::endl;
    b1++;
    std::cout << "After friend post-increment (b1++): " << b1.getLength() << std::endl;
    return 0;
}
```

## Output

```
b1 + b2 = 14
b1 - b2 = 6
Initial b1: 10
After friend pre-increment (++b1): 11
After friend post-increment (b1++): 12
```

## Output Explanation

- Two `Box` objects are created with lengths 10 and 4.
- The overloaded `+` operator (member function) adds the lengths, resulting in 14.
- The overloaded `-` operator (friend function) subtracts the lengths, resulting in 6.
- The program then demonstrates pre-increment and post-increment on `b1` using friend functions:
  - `++b1` (pre-increment) increases the length to 11 using a friend function.
  - `b1++` (post-increment) increases the length to 12 using a friend function (but the value before increment is used in the expression).
- Each step prints the current value, demonstrating both unary operator overloads as friend functions in the `Box` class. 