class Rectangle {
public:
    double width, height;
    virtual void setWidth(double w)  { width  = w; }
    virtual void setHeight(double h) { height = h; }
    double area() const { return width * height; }
};

class Square : public Rectangle {
public:
    // BAD: breaks the caller's assumption that width and height are independent
    void setWidth(double w)  override { width = height = w; }
    void setHeight(double h) override { width = height = h; }
};

void test(Rectangle& r) {
    r.setWidth(4);
    r.setHeight(5);
    // expects 20 — gets 25 if r is actually a Square
    assert(r.area() == 20);
}