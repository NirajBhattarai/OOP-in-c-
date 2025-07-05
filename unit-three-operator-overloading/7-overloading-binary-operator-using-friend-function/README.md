# Overloading Binary Operator Using Friend Function

Friend functions can be used to overload binary operators when access to private members is required or when the left operand is not a class object. The friend function is declared inside the class with the `friend` keyword and defined outside the class. 

## Program Explanation

This program demonstrates overloading a binary operator using a friend function with a `Distance` class:

- The `Distance` class has a private integer member `meters` and a constructor.
- The `operator+` is overloaded as a friend function to add the meters of two `Distance` objects.
- The `getMeters()` method returns the distance in meters.
- In `main()`, two `Distance` objects are created and added using the overloaded `+` operator (friend function). The result is printed. 

## Program

```cpp
// overloading-binary-operator-using-friend-function.cpp
// Demonstrates overloading binary and unary operators using friend functions for Complex numbers
#include <iostream>

class Complex {
private:
    double real, imag;
public:
    Complex(double real, double imag) : real(real), imag(imag) {}
    // Friend function to overload +
    friend Complex operator+(const Complex& c1, const Complex& c2);
    // Friend function to overload pre-increment
    friend Complex& operator++(Complex& c);
    // Friend function to overload post-increment
    friend Complex operator++(Complex& c, int);
    void print() const {
        std::cout << real << " + " << imag << "i" << std::endl;
    }
};

Complex operator+(const Complex& c1, const Complex& c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}
Complex& operator++(Complex& c) {
    ++c.real;
    ++c.imag;
    return c;
}
Complex operator++(Complex& c, int) {
    Complex temp = c;
    ++c.real;
    ++c.imag;
    return temp;
}

int main() {
    Complex c1(1.5, 2.5), c2(2.0, 3.0);
    Complex c3 = c1 + c2; // Uses friend function
    std::cout << "c1 + c2 = ";
    c3.print();
    std::cout << "Initial c1: ";
    c1.print();
    ++c1;
    std::cout << "After friend pre-increment (++c1): ";
    c1.print();
    c1++;
    std::cout << "After friend post-increment (c1++): ";
    c1.print();
    return 0;
}
```

## Output

```
c1 + c2 = 3.5 + 5.5i
Initial c1: 1.5 + 2.5i
After friend pre-increment (++c1): 2.5 + 3.5i
After friend post-increment (c1++): 3.5 + 4.5i
```

## Output Explanation

- Two `Complex` objects are created with values (1.5, 2.5) and (2.0, 3.0).
- The overloaded `+` operator (friend function) adds their real and imaginary parts, resulting in (3.5, 5.5).
- The program then demonstrates pre-increment and post-increment on `c1` using friend functions:
  - `++c1` (pre-increment) increases both real and imaginary parts by 1, resulting in (2.5, 3.5).
  - `c1++` (post-increment) increases both real and imaginary parts by 1, resulting in (3.5, 4.5) (but the value before increment is used in the expression).
- Each step prints the current value, demonstrating both unary operator overloads as friend functions in the `Complex` class. 