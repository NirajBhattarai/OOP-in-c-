// static-data-members.cpp
// Demonstrates static data members in C++
#include <iostream>

class Counter {
public:
    static int count;
    Counter() { ++count; }
};

int Counter::count = 0;

int main() {
    Counter a, b, c;
    std::cout << "Count: " << Counter::count << std::endl;
    return 0;
} 