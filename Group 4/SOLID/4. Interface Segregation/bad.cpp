struct IShape {
    virtual double area()         const = 0;
    virtual double volume()       const = 0; // BAD: 2D shapes have no volume
    virtual void   serialize()    const = 0; // BAD: unrelated to geometry
    virtual void   render()       const = 0; // BAD: unrelated to geometry
    virtual ~IShape() = default;
};

struct Circle : IShape {
    double radius;
    double area()      const override { return 3.14159 * radius * radius; }
    double volume()    const override { return 0; }  // meaningless
    void   serialize() const override { /* forced to implement */ }
    void   render()    const override { /* forced to implement */ }
};