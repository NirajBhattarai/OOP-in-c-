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