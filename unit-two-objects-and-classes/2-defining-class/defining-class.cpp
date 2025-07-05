// defining-class.cpp
// Demonstrates defining a class with data members and member functions
#include <iostream>

class Rectangle {
private:
    int width;
    int height;
public:
    void setDimensions(int w, int h) {
        width = w;
        height = h;
    }
    int area() const {
        return width * height;
    }
};

int main() {
    Rectangle rect;
    rect.setDimensions(4, 5);
    std::cout << "Area: " << rect.area() << std::endl;
    return 0;
} 