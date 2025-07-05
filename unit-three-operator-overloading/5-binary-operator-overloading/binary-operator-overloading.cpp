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