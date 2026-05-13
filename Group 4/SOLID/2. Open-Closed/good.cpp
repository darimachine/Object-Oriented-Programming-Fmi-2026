struct IShape {
    virtual void   render() const = 0;
    virtual double area()   const = 0;
    virtual ~IShape() = default;
};

struct Circle : IShape {
    double radius;
    void   render() const override {
        std::cout << "rendering circle r=" << radius << "\n";
    }
    double area() const override { return 3.14159 * radius * radius; }
};

struct Rectangle : IShape {
    double width, height;
    void   render() const override {
        std::cout << "rendering rect " << width << "x" << height << "\n";
    }
    double area() const override { return width * height; }
};

// Added later — zero changes to anything above
struct Triangle : IShape {
    double base, height;
    void   render() const override {
        std::cout << "rendering triangle b=" << base << " h=" << height << "\n";
    }
    double area() const override { return 0.5 * base * height; }
};