// this-operator.cpp
// Demonstrates the use of the this operator in C++
#include <iostream>

class Number {
private:
    int value;
public:
    Number(int value) {
        this->value = value; // Use this to resolve naming conflict
    }
    Number& setValue(int value) {
        this->value = value;
        return *this; // Return the object itself
    }
    void print() const {
        std::cout << "Value: " << value << std::endl;
    }
};

int main() {
    Number n(5);
    n.print();
    n.setValue(10).print(); // Chaining using this
    return 0;
} 