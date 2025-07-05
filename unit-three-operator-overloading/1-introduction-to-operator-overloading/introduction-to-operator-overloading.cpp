// introduction-to-operator-overloading.cpp
// Demonstrates basic operator overloading in C++
#include <iostream>

class Number {
private:
    int value;
public:
    Number(int value) : value(value) {}
    // Overload the + operator
    Number operator+(const Number& other) const {
        return Number(value + other.value);
    }
    int getValue() const { return value; }
};

int main() {
    Number num1(5);
    Number num2(10);
    Number sum = num1 + num2; // Uses overloaded +
    std::cout << "Sum: " << sum.getValue() << std::endl;
    return 0;
} 