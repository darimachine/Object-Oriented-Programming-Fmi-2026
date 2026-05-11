class Circle {
public:
    double radius;

    double area() const { return 3.14159 * radius * radius; }

    // BAD: serialization has nothing to do with being a circle
    std::string toJson() const {
        return "{\"type\":\"circle\",\"radius\":" + std::to_string(radius) + "}";
    }
};