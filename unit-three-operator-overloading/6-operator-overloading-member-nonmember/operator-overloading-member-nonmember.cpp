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