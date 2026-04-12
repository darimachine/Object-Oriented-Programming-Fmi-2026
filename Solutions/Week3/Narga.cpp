#include <cstring>
#include <iostream>
#include <print>
constexpr int MAX = 1024;

enum class Taste {
    BLUEBERRY,
    QUEEN,
    MANGO,
    WATERMELON,
    STRAWBERRY
};

class Narga {
private:
    double price{};
    char brand[MAX]{};
    Taste taste{};

public:
    Narga() = default;

    Narga(double price_, const char* brand_, Taste taste_) : price(price_), taste(taste_) {
        strcpy(brand, brand_);
    }

    void setPrice(double newPrice) {
        price = newPrice;
    }

    void setBrand(const char* newBrand) {
        strcpy(brand, newBrand);
    }

    void setTaste(Taste newTaste) {
        taste = newTaste;
    }

    double getPrice() const {
        return price;
    }

    const char* getBrand() const {
        return brand;
    }

    Taste getTaste() const {
        return taste;
    }

    void read() {
        std::print("Enter price: ");
        std::cin >> price;
        std::cin.ignore();

        std::print("Enter brand: ");
        char tmp[MAX];
        std::cin.getline(tmp, MAX);
        strcpy(brand, tmp);

        int t;
        std::print("Enter taste (1 - Blueberry, 2 - Queen, 3 - Mango, 4 - Watermelon, 5 - Strawberry): ");
        std::cin >> t;
        t--;
        if (t >= 0 && t <= 4) {
            taste = static_cast<Taste>(t);
        }
    }

    void print() const {
        const char* tasteName = "";
        switch (taste) {
            case Taste::BLUEBERRY: tasteName = "Blueberry"; break;
            case Taste::QUEEN: tasteName = "Queen"; break;
            case Taste::MANGO: tasteName = "Mango"; break;
            case Taste::WATERMELON: tasteName = "Watermelon"; break;
            case Taste::STRAWBERRY: tasteName = "Strawberry"; break;
        }
        std::print("Price: {}, Brand: {}, Taste: {}\n", price, brand, tasteName);
    }
};