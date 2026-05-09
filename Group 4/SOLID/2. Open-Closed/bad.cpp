enum class ShapeType { Circle, Rectangle };

struct Shape {
    ShapeType type;
    double a, b; // radius, or width+height depending on type
};

void render(const Shape& s) {
    switch (s.type) {
        case ShapeType::Circle:
            std::cout << "rendering circle r=" << s.a << "\n";
            break;
        case ShapeType::Rectangle:
            std::cout << "rendering rect " << s.a << "x" << s.b << "\n";
            break;
        // adding Triangle: come back here, add a case, recompile, retest
    }
}

double area(const Shape& s) {
    switch (s.type) {
        case ShapeType::Circle:    return 3.14159 * s.a * s.a;
        case ShapeType::Rectangle: return s.a * s.b;
        // and here too
    }
    return 0;
}