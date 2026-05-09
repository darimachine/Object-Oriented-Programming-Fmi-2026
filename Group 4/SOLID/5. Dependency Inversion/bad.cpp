class ShapeRenderer {
public:
    void render(const IShape& s) const { s.render(); }
};

class Canvas {
    ShapeRenderer renderer_;  // BAD: Canvas decides what renderer it gets
    std::vector<std::unique_ptr<IShape>> shapes_;
public:
    void add(std::unique_ptr<IShape> s) { shapes_.push_back(std::move(s)); }

    void draw() const {
        for (const auto& s : shapes_)
            renderer_.render(*s);  // hardwired to ShapeRenderer
    }
};