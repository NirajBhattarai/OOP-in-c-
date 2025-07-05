# Syntax and Rules of Operator Overloading

Operator overloading in C++ is done by defining special member or non-member functions using the `operator` keyword. The function signature depends on the operator being overloaded. Some rules:
- At least one operand must be a user-defined type.
- You cannot create new operators, only overload existing ones.
- Some operators cannot be overloaded (e.g., ::, ., .*, ?:).
- Operator precedence and associativity cannot be changed.

## Program

```cpp
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
```

## Output

```
(4, 6)
```

## Output Explanation

- Two `Point` objects are created with coordinates (1, 2) and (3, 4).
- The overloaded `+` operator adds their coordinates, resulting in (4, 6).
- The result is printed as `(4, 6)`. 