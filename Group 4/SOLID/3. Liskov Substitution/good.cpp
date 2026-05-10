struct IShape {
    virtual double area() const = 0;
    virtual ~IShape() = default;
};

struct Rectangle : IShape {
    double width, height;
    double area() const override { return width * height; }
};

// Square is NOT a Rectangle — it is its own shape
struct Square : IShape {
    double side;
    double area() const override { return side * side; }
};

void printArea(const IShape& s) {
    // works correctly for every subtype, no surprises
    std::cout << s.area() << "\n";
}