#include <cstring>

constexpr int MAX_NAME = 128;

class Alcohol {
private:
    char name[MAX_NAME]{};
    double price{};

public:
    Alcohol() = default;

    Alcohol(const char* name_, double price_) : price(price_) {
        strcpy(name, name_);
    }

    void setName(const char* newName) {
        strcpy(name, newName);
    }

    void setPrice(double newPrice) {
        price = newPrice;
    }

    const char* getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }
};