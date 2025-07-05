// syntax-and-rules-of-operator-overloading.cpp
// Demonstrates syntax and rules of operator overloading in C++
#include <iostream>

class Point {
private:
    int x, y;
public:
    Point(int x, int y) : x(x), y(y) {}
    // Overload + operator
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }
    void print() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

int main() {
    Point p1(1, 2), p2(3, 4);
    Point p3 = p1 + p2;
    p3.print();
    return 0;
} 