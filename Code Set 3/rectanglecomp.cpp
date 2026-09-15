#include <iostream>

class Rectangle {
public:
    double length;
    double width;

    Rectangle(double l, double w) : length(l), width(w) {}

    double getArea() {
        return length * width;
    }

    bool hasEqualArea(Rectangle other) {
        return this->getArea() == other.getArea();
    }
};

Rectangle mergeRectangles(Rectangle r1, Rectangle r2) {
    double newLength = r1.length + r2.length;
    double newWidth = r1.width + r2.width;
    return Rectangle(newLength, newWidth);
}

int main() {
    Rectangle rect1(5.0, 4.0);
    Rectangle rect2(2.0, 10.0);
    Rectangle rect3(3.0, 3.0);

    if (rect1.hasEqualArea(rect2)) {
        std::cout << "rect1 and rect2 have equal area." << std::endl;
    } else {
        std::cout << "rect1 and rect2 do not have equal area." << std::endl;
    }

    if (rect1.hasEqualArea(rect3)) {
        std::cout << "rect1 and rect3 have equal area." << std::endl;
    } else {
        std::cout << "rect1 and rect3 do not have equal area." << std::endl;
    }

    Rectangle merged = mergeRectangles(rect1, rect2);
    std::cout << "Merged Rectangle - Length: " << merged.length << ", Width: " << merged.width << std::endl;

    return 0;
}
