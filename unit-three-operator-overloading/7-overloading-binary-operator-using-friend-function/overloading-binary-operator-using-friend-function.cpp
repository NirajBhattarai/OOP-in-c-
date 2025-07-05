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