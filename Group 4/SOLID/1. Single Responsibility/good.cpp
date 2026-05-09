struct Circle : IShape {
    double radius;
    double area() const override { return 3.14159 * radius * radius; }
};

// Separate class, separate reason to change
class ShapeSerializer {
public:
    std::string toJson(const IShape& s) const {
        return "{\"area\":" + std::to_string(s.area()) + "}";
    }
};