// initializing-objects.cpp
// Demonstrates object initialization in C++
#include <iostream>

class Point {
private:
    int x, y;
public:
    Point() : x(0), y(0) {
        std::cout << "Default constructor" << std::endl;
    }
    Point(int x, int y) : x(x), y(y) {
        std::cout << "Parameterized constructor" << std::endl;
    }
    Point(const Point& p) : x(p.x), y(p.y) {
        std::cout << "Copy constructor" << std::endl;
    }
    void print() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

int main() {
    Point p1;
    Point p2(3, 4);
    Point p3 = p2;
    p1.print();
    p2.print();
    p3.print();
    return 0;
} 