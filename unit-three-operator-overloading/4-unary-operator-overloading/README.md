# Unary Operator Overloading

Unary operators operate on a single operand. In C++, you can overload unary operators (e.g., +, -, ++, --, !) for user-defined types. This is typically done by defining a member function or a friend function with the `operator` keyword. Example: `TypeName operator++();`. 

## Program Explanation

This program demonstrates unary operator overloading using a `Counter` class:

- The `Counter` class has a private integer member `count` and a constructor.
- The prefix increment operator `++` is overloaded to increase the `count` by 1.
- The `getCount()` method returns the current count.
- In `main()`, a `Counter` object is created and incremented using the overloaded `++` operator. The result is printed. 

## Program

```cpp
// unary-operator-overloading.cpp
// Demonstrates unary operator overloading in C++
#include <iostream>

class Counter {
private:
    int count;
public:
    Counter(int count) : count(count) {}
    // Overload prefix ++
    Counter& operator++() {
        ++count;
        return *this;
    }
    // Overload postfix ++
    Counter operator++(int) {
        Counter temp = *this;
        ++count;
        return temp;
    }
    // Overload prefix --
    Counter& operator--() {
        --count;
        return *this;
    }
    // Overload postfix --
    Counter operator--(int) {
        Counter temp = *this;
        --count;
        return temp;
    }
    int getCount() const { return count; }
};

int main() {
    Counter c(5);
    std::cout << "Initial: " << c.getCount() << std::endl;
    ++c;
    std::cout << "After pre-increment (++c): " << c.getCount() << std::endl;
    c++;
    std::cout << "After post-increment (c++): " << c.getCount() << std::endl;
    --c;
    std::cout << "After pre-decrement (--c): " << c.getCount() << std::endl;
    c--;
    std::cout << "After post-decrement (c--): " << c.getCount() << std::endl;
    return 0;
}
```

## Output

```
Initial: 5
After pre-increment (++c): 6
After post-increment (c++): 7
After pre-decrement (--c): 6
After post-decrement (c--): 5
```

## Output Explanation

- The program starts with a `Counter` object initialized to 5.
- `++c` (pre-increment) increases the value to 6 before use.
- `c++` (post-increment) increases the value to 7 after use.
- `--c` (pre-decrement) decreases the value to 6 before use.
- `c--` (post-decrement) decreases the value to 5 after use.
- Each step prints the current value, demonstrating all four unary operator overloads. 