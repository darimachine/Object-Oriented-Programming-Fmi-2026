#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

enum class ShapeType {
    CIRCLE,
    TRIANGLE,
    RECTANGLE
};

namespace CircleNs {
    constexpr double PI = 3.14;

    struct Circle {
        double radius;
    };

    void read(Circle& circle) {
        cout << "Enter the circle radius: ";
        cin >> circle.radius;
    }

    double getArea(const Circle& circle) {
        return PI * circle.radius * circle.radius;
    }
}

namespace TriangleNs {
    struct Triangle {
        double side1;
        double side2;
        double side3;
    };

    void read(Triangle& triangle) {
        cout << "Enter the 3 sides of the triangle: ";
        cin >> triangle.side1 >> triangle.side2 >> triangle.side3;
    }

    double getArea(const Triangle& triangle) {
        double halfp = (triangle.side1 + triangle.side2 + triangle.side3) / 2;

        return sqrt(halfp * (halfp - triangle.side1) * (halfp - triangle.side2) * (halfp - triangle.side3));
    }
}

namespace RectangleNs {
    struct Rectangle {
        double side1;
        double side2;
    };

    void read(Rectangle& rectangle) {
        cout << "Enter both sides of the rectangle: ";
        cin >> rectangle.side1 >> rectangle.side2;
    }

    double getArea(const Rectangle& rectangle) {
        return rectangle.side1 * rectangle.side2;
    }
}

bool areEqual(double d1, double d2) {
    return abs(d1 - d2) < 1e-5;
}

double getAreaShape() {
    int type;
    cout << "Choose shape type(0 -> circle, 1 -> triangle, 2 -> rectangle): ";
    cin >> type;

    switch ((ShapeType)type) {
        case ShapeType::CIRCLE: {
            CircleNs::Circle c;
            CircleNs::read(c);
            return CircleNs::getArea(c);
        }
        case ShapeType::TRIANGLE: {
            TriangleNs::Triangle t;
            TriangleNs::read(t);
            return TriangleNs::getArea(t);
        }
        case ShapeType::RECTANGLE: {
            RectangleNs::Rectangle r;
            RectangleNs::read(r);
            return RectangleNs::getArea(r);
        }
        default: return -1;
    }
}

int main() {
    while(true) {
        double area1 = getAreaShape();
        double area2 = getAreaShape();

        if (area1 == -1 || area2 == -1) {
            cout << "Invalid input" << endl;
            break;
        }

        if (areEqual(area1, area2)) {
            cout << "Both areas are equal: " << area1 << endl;
        } else if (area1 < area2) {
            cout << "Area of second shape is bigger: " << area2 << " > " << area1 << endl;
        } else {
            cout << "Area of first shape is bigger: " << area1 << " > " << area2 << endl;
        }        
    }
}
