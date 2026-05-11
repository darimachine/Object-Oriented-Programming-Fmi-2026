struct IShape {
    virtual double area() const = 0;
    virtual ~IShape() = default;
};

struct IRenderable {
    virtual void render() const = 0;
    virtual ~IRenderable() = default;
};

// Circle only carries what it needs
struct Circle : IShape {
    double radius;
    double area() const override { return 3.14159 * radius * radius; }
};

// A shape that also renders implements both — but separately
struct Rectangle : IShape, IRenderable {
    double width, height;
    double area()   const override { return width * height; }
    void   render() const override { std::cout << "drawing rectangle...\n"; }
};