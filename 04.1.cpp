
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

enum class Color {
    WHITE, GREEN, RED
};

class Balloon {
private:
    double price;
    Color color;

public:
    Balloon() : price(0) {
    color=Color::WHITE;
    }

    Balloon(double p, Color c) {
        price = p;
        color = c;
    }

    void setPrice(double newPrice) {
        price = newPrice;
    }

    void setColor(Color newColor) {
        color = newColor;
    }

    double getPrice() const {
        return price;
    }

    Color getColor() const {
        return color;
    }
};
