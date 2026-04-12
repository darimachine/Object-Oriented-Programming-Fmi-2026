#include <iostream>
#include <cstring>

enum class Color {
    WHITE,
    GREEN,
    RED
};

class Baloon {
private:
    double price{};
    Color color{};

public:
    Baloon() = default;

    Baloon(double price_, Color color_) : price(price_), color(color_) {

    }

    double getPrice() const {
        return price;
    }

    Color getColor() const {
        return color;
    }

    void setPrice(double newPrice) {
        price = newPrice;
    }

    void setColor(Color newColor) {
        color = newColor;
    }

};