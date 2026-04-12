#include <iostream>

class Point {
private:
    double x = 0;
    double y = 0;

public:
    Point() = default;

    Point(int x, int y) : x(x), y(y) {}

    // getters must be const because they don't modify the object
    // for primitive types like int, you can return them by copy
    double getX() const {
        return x;
    }

    // setters shouldn't be const because they modify the object
    void setX(double x) {
        this->x = x;
    }

    double getY() const {
        return y;
    }

    void setY(double y) {
        this->y = y;
    }
};

class Circle {
private:
    Point center;
    double radius = 5.0;

public:
    Circle() = default;
    Circle(double x, double y, double radius) : center(x, y), radius(radius) {}

    Circle(const Point& center, double radius) : Circle(center.getX(), center.getY(), radius) {}

    // for non-primitive types like Point, you should return them by const reference
    const Point& getCenter() const {
        return center;
    }

    void setCenter(const Point& center) {
        this->center = center;
    }

    double getRadius() const {
        return radius;
    }

    void setRadius(double radius) {
        this->radius = radius;
    }
};

int main() {
    Circle c;
    std::cout << c.getCenter().getX() << " " << c.getCenter().getY() << " " << c.getRadius() << std::endl;

    Circle c2(3, 4, 5);
    std::cout << c2.getCenter().getX() << " " << c2.getCenter().getY() << " " << c2.getRadius() << std::endl;

    c2.setCenter(Point(1, 2));
    c2.setRadius(10);
    std::cout << c2.getCenter().getX() << " " << c2.getCenter().getY() << " " << c2.getRadius() << std::endl;
}
