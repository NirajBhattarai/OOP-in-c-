# Binary Operator Overloading

Binary operators operate on two operands. In C++, you can overload binary operators (e.g., +, -, *, /, ==, !=) for user-defined types. This is done by defining a member or non-member function with the `operator` keyword. Example: `TypeName operator+(const TypeName& other);`. 

## Program Explanation

This program demonstrates binary operator overloading using a `Complex` class:

- The `Complex` class has two private double members, `real` and `imag`, and a constructor.
- The `operator+` is overloaded to add two `Complex` numbers, returning a new `Complex` object with summed real and imaginary parts.
- The `print()` method displays the complex number in standard form.
- In `main()`, two `Complex` objects are created and added using the overloaded `+` operator. The result is printed. 

## Program

```cpp
// binary-operator-overloading.cpp
// Demonstrates binary operator overloading in C++
#include <iostream>

class Complex {
private:
    double real, imag;
public:
    Complex(double real, double imag) : real(real), imag(imag) {}
    // Overload + operator
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }
    void print() const {
        std::cout << real << " + " << imag << "i" << std::endl;
    }
};

int main() {
    Complex c1(1.5, 2.5), c2(2.0, 3.0);
    Complex c3 = c1 + c2;
    c3.print();
    return 0;
}
```

## Output

```
3.5 + 5.5i
```

## Output Explanation

- Two `Complex` objects are created with values (1.5, 2.5) and (2.0, 3.0).
- The overloaded `+` operator adds their real and imaginary parts, resulting in (3.5, 5.5).
- The result is printed as `3.5 + 5.5i`. 