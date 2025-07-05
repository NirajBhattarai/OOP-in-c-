// overloadable-operators.cpp
// Demonstrates which operators can be overloaded in C++
#include <iostream>

class Demo {
private:
    int value;
public:
    Demo(int value) : value(value) {}
    // Overload +, -, *, ==, and assignment =
    Demo operator+(const Demo& other) const { return Demo(value + other.value); }
    Demo operator-(const Demo& other) const { return Demo(value - other.value); }
    Demo operator*(const Demo& other) const { return Demo(value * other.value); }
    bool operator==(const Demo& other) const { return value == other.value; }
    Demo& operator=(const Demo& other) { value = other.value; return *this; }
    int getValue() const { return value; }
};

int main() {
    Demo a(2), b(3);
    Demo c = a + b;
    Demo d = a * b;
    bool isEqual = (a == b);
    std::cout << "a + b = " << c.getValue() << std::endl;
    std::cout << "a * b = " << d.getValue() << std::endl;
    std::cout << "a == b: " << (isEqual ? "true" : "false") << std::endl;
    return 0;
} 