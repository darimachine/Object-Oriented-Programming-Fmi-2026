#include <iostream>
#include <fstream>
#include <cstring>
#include <print>

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
};

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

struct Client {
    char name[MAX_NAME];
    char filename[MAX_NAME * 2];
};

constexpr int MAX_BALLOONS = 1024;
constexpr int MAX_ALCOHOLS = 512;
constexpr int MAX_NARGAS = 256;

class NightClub {
private:
    Baloon balloons[MAX_BALLOONS];
    int balloonCount[MAX_BALLOONS]{};
    int totalBalloons{};

    Narga nargas[MAX_NARGAS];
    int nargaCount[MAX_NARGAS]{};
    int totalNargas{};

    Alcohol alcohols[MAX_ALCOHOLS];
    int alcoholCount[MAX_ALCOHOLS]{};
    int totalAlcohols{};

    int findBaloonIndex(Color color) {
        for (int i = 0; i < totalBalloons; i++) {
            if (balloons[i].getColor() == color) {
                return i;
            }
        }
        return -1;
    }

    int findAlcoholIndex(const char* name) {
        for (int i = 0; i < totalAlcohols; i++) {
            if (strcmp(alcohols[i].getName(), name) == 0) {
                return i;
            }
        }
        return -1;
    }

    int findNargaIndex(const char* brand, Taste taste) {
        for (int i = 0; i < totalNargas; i++) {
            if (strcmp(nargas[i].getBrand(), brand) == 0 && nargas[i].getTaste() == taste) {
                return i;
            }
        }
        return -1;
    }

public:
    NightClub() {
        totalBalloons = 0;
        totalAlcohols = 0;
        totalNargas = 0;
    }

    void addBaloon(const Baloon& b) {
        int baloonIndex = findBaloonIndex(b.getColor());
        if (baloonIndex != -1) {
            balloonCount[baloonIndex]++;
        } else {
            balloons[totalBalloons] = b;
            balloonCount[totalBalloons] = 1;
            totalBalloons++;
        }
    }

    void addNarga(const Narga& n) {
        int nargaIndex = findNargaIndex(n.getBrand(), n.getTaste());
        if (nargaIndex != -1) {
            nargaCount[nargaIndex]++;
        } else {
            nargas[totalNargas] = n;
            nargaCount[totalNargas] = 1;
            totalNargas++;
        }
    }

    void addAlcohol(const Alcohol& a) {
        int AlcoholIndex = findAlcoholIndex(a.getName());
        if (AlcoholIndex != -1) {
            alcoholCount[AlcoholIndex]++;
        } else {
            alcohols[totalAlcohols] = a;
            alcoholCount[totalAlcohols] = 1;
            totalAlcohols++;
        }
    }

    void removeBaloon(Color color) {
        int baloonIndex = findBaloonIndex(color);
        if (baloonIndex != -1) {
            balloonCount[baloonIndex]--;
            if (balloonCount[baloonIndex] <= 0) {
                for (int i = baloonIndex; i < totalBalloons - 1; i++) {
                    balloons[i] = balloons[i + 1];
                    balloonCount[i] = balloonCount[i + 1];
                }
                totalBalloons--;
            }
        }
    }

    void removeNarga(const char* brand, Taste taste) {
        int nargaIndex = findNargaIndex(brand, taste);
        if (nargaIndex != -1) {
            nargaCount[nargaIndex]--;
            if (nargaCount[nargaIndex] <= 0) {
                for (int i = nargaIndex; i < totalNargas - 1; i++) {
                    nargas[i] = nargas[i + 1];
                    nargaCount[i] = nargaCount[i + 1];
                }
                totalNargas--;
            }
        }
    }

    void removeAlcohol(const char* name) {
        int AlcoholIndex = findAlcoholIndex(name);
        if (AlcoholIndex != -1) {
            alcoholCount[AlcoholIndex]--;
            if (alcoholCount[AlcoholIndex] <= 0) {
                for (int i = AlcoholIndex; i < totalAlcohols - 1; i++) {
                    alcohols[i] = alcohols[i + 1];
                    alcoholCount[i] = alcoholCount[i + 1];
                }
                totalAlcohols--;
            }
        }
    }

    bool hasBaloon(Color color) {
        if (findBaloonIndex(color) != -1) {
            return true;
        } else {
            return false;
        }
    }

    bool hasAlcohol(const char* name) {
        if (findAlcoholIndex(name) != -1) {
            return true;
        } else {
            return false;
        }
    }

    bool hasNargaTaste(Taste taste) const {
        for (int i = 0; i < totalNargas; i++) {
            if (nargas[i].getTaste() == taste) {
                return true;
            }
        }
        return false;
    }

    static Color stringToColor(const std::string& str) {
        if (str == "white") return Color::WHITE;
        if (str == "green") return Color::GREEN;
        return Color::RED;
    }

    static Taste stringToTaste(const std::string& str) {
        if (str == "blueberry") return Taste::BLUEBERRY;
        if (str == "queen") return Taste::QUEEN;
        if (str == "mango") return Taste::MANGO;
        if (str == "watermelon") return Taste::WATERMELON;
        return Taste::STRAWBERRY;
    }

    double calculateBill(const char* fileName) {
        std::ifstream file(fileName);
        if (!file.is_open()) {
            std::cout << "File error\n";
            return 0.0;
        }

        double total = 0.0;
        std::string type;

        while (file >> type) {
            if (type == "BALLOON") {
                std::string colorStr;
                int quantity;
                file >> colorStr >> quantity;

                Color c = stringToColor(colorStr);
                int baloonIndex = findBaloonIndex(c);
                if (baloonIndex != -1) {
                    total += balloons[baloonIndex].getPrice() * quantity;
                }
            }
            else if (type == "ALCOHOL") {
                std::string name;
                int quantity;
                file >> name >> quantity;

                int alcoholIndex = findAlcoholIndex(name.c_str());
                if (alcoholIndex != -1) {
                    total += alcohols[alcoholIndex].getPrice() * quantity;
                }
            }
            else if (type == "NARGA") {
                std::string tasteStr, brand;
                int quantity;
                file >> tasteStr >> brand >> quantity;

                Taste t = stringToTaste(tasteStr);
                int nargaIndex = findNargaIndex(brand.c_str(), t);
                if (nargaIndex != -1) {
                    total += nargas[nargaIndex].getPrice() * quantity;
                }
            }
        }

        file.close();
        return total;
    }
};