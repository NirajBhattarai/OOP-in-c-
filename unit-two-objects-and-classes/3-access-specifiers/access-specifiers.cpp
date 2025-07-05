// access-specifiers.cpp
// Demonstrates access specifiers in C++
#include <iostream>

class Demo {
public:
    int publicVar;
protected:
    int protectedVar;
private:
    int privateVar;
public:
    Demo() : publicVar(1), protectedVar(2), privateVar(3) {}
    void show() const {
        std::cout << "public=" << publicVar << ", protected=" << protectedVar << ", private=" << privateVar << std::endl;
    }
};

class Child : public Demo {
public:
    void showChild() const {
        std::cout << "public=" << publicVar << ", protected=" << protectedVar << std::endl;
        // privateVar is not accessible here
    }
};

int main() {
    Demo d;
    d.show();
    Child c;
    c.showChild();
    return 0;
} 