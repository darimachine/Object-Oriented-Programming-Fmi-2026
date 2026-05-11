// The abstraction both sides depend on
struct IRenderer {
    virtual void render(const IShape&) const = 0;
    virtual ~IRenderer() = default;
};

// Low-level module — depends on IShape abstraction, not on Canvas
class ShapeRenderer : public IRenderer {
public:
    void render(const IShape& s) const override { s.render(); }
};

// Another low-level module — trivial to add, Canvas never changes
class SvgRenderer : public IRenderer {
public:
    void render(const IShape& s) const override {
        std::cout << "<shape area=\"" << s.area() << "\"/>\n";
    }
};

// High-level module — depends on IRenderer, never on a concrete renderer
class Canvas {
    IRenderer& renderer_;   // injected, not constructed here
    std::vector<std::unique_ptr<IShape>> shapes_;
public:
    explicit Canvas(IRenderer& r) : renderer_(r) {}

    void add(std::unique_ptr<IShape> s) { shapes_.push_back(std::move(s)); }

    void draw() const {
        for (const auto& s : shapes_)
            renderer_.render(*s);
    }
};

int main() {
    ShapeRenderer screenRenderer;
    Canvas canvas{screenRenderer};

    auto c = std::make_unique<Circle>();    c->radius = 5;
    auto r = std::make_unique<Rectangle>(); r->width = 4; r->height = 6;
    canvas.add(std::move(c));
    canvas.add(std::move(r));
    canvas.draw();

    // Swap renderer without touching Canvas at all
    SvgRenderer svgRenderer;
    Canvas svgCanvas{svgRenderer};
    svgCanvas.add(std::make_unique<Circle>());
    svgCanvas.draw();
}