#include <iostream>
#include  <print>
#include  <cstring>
#include  <fstream>
const double MIN_PRICE{5};
const int MAX_SIZE_BRAND{1024};
const int MAX_SIZE_NAME = 128;
const double minPrice =3.20;
enum class Color
{
    WHITE,
    GREEN,
    RED
};

const double MIN_PRICE_B = 0.01;
class Ballon
{
    private:
        double price =MIN_PRICE_B;
        Color color = Color::WHITE;

    public:
    Ballon() = default;

    Ballon(const double inpPrice, Color inpColor)
    {
        setPrice(inpPrice);
        setColor(inpColor);
    }

    void setPrice(const double inpPrice)
    {
        if (inpPrice < MIN_PRICE_B)
        {
            std::println("Invalid price for a balloon");
            return;
        }

        price = inpPrice;
    }

    void setColor(Color inpColor)
    {
        color = inpColor;
    }
    double getPrice() const
    {
        return price;
    }

    Color getColor() const
    {
        return color;
    }

    const char *getColorAsString() const
    {
        switch (color)
        {
            case Color::WHITE:
                return "White";
            case Color::GREEN:
                return "Green";
            case Color::RED:
                return "Red";

            default:
                return "Unknown";
        }
    }
};

enum  class Flavour
{
    Blueberry,
    Queen,
    Mango,
    Cactus,
    Watermelon
};

class Narga
{
private:
    double price =MIN_PRICE;
    char brand[MAX_SIZE_BRAND] ={};
    Flavour flavour = Flavour::Blueberry;

public:
    Narga() = default;

    Narga(double inpPrice, const char*inpBrand, const char* wantedFlavour)
    {
        setPrice(inpPrice);
        setBrand(inpBrand);
        setFlavour(wantedFlavour);
    }

    void setPrice(double inpPrice)
    {
        if (inpPrice < MIN_PRICE)
        {
            std::println("Invalid price for shisha");
            return;
        }
        price = inpPrice;
    }

    double getPrice() const
    {
        return this->price;
    }

    void setBrand(const char *inpBrand)
    {
        if (!inpBrand)
        {
            std::println("No brand is entered!");
            return;
        }

        int inpBrandLen = strlen(inpBrand);
        if (inpBrandLen >= MAX_SIZE_BRAND)
        {
            std::println("You entered more than 1024 characters!");
            return;
        }
        strcpy(brand, inpBrand);
        brand[inpBrandLen] = '\0';
    }
    const char* getBrand() const
    {
        return this->brand;
    }

    void setFlavour(const char *inpFlavour)
    {
        if (!inpFlavour)
        {
            std::println("No flavour is entered");
            return;
        }

        if (strcmp("Blueberry", inpFlavour) == 0)
            flavour =Flavour::Blueberry;
        else if (strcmp("Queen", inpFlavour) == 0)
            flavour =Flavour::Queen;
        else if (strcmp("Mango", inpFlavour) == 0)
            flavour = Flavour::Mango;
        else if (strcmp("Cactus", inpFlavour) == 0)
            flavour = Flavour::Cactus;
        else if (strcmp("Watermelon", inpFlavour) == 0)
            flavour = Flavour::Watermelon;
        else
        {
            std::println("No match with the available flavours");
        }
    }

    void print() const
    {
        std::println("The shisha's brand is: {}", getBrand());
        std::println("The shisha's price is: {}", price);
        std::print("With a flavour: ");
        switch(flavour)
        {
            case Flavour::Blueberry:
                std::println("Bluebbery");
                break;
            case Flavour::Queen:
                std::println("Queen");
                break;
            case Flavour::Mango:
                std::println("Mango");
                break;
            case Flavour::Cactus:
                std::println("Cactus");
                break;
            case Flavour::Watermelon:
                std::println("Watermelon");
                break;
            default:
                std::println("none");
        }
    }
    Flavour getFlavour() const
    {
        return this->flavour;
    }

    void read()
    {
        double price{};
        std::print("Enter the price: ");
        std::cin>>price;

        std::cin.ignore();

        char brand[MAX_SIZE_BRAND] = {}, flavour[MAX_SIZE_BRAND] = {};
        std::print("Input the shisha's brand: ");
        std::cin.getline(brand, 1023);

        std::print("Input the wanted flavour: ");
        std::cin.getline(flavour, 1023);

        setPrice(price);
        setBrand(brand);
        setFlavour(flavour);
    }
};

class Alcohol
{
private:
    char name[MAX_SIZE_NAME]{};
    double price = minPrice;

public:
    Alcohol() = default;

    Alcohol(const char *inpName, double inpPrice)
    {
        setName(inpName);
        setPrice(inpPrice);
    }

    void setPrice(double inpPrice)
    {
        if (inpPrice < minPrice)
        {
            std::println("Invalid price for a alcohol");
            return;
        }
        price = inpPrice;
    }

    double getPrice() const
    {
        return this->price;
    }

    void setName(const char *inpName)
    {
        if (!inpName)
        {
            std::println("No name of the alcohol is entered");
            return;
        }

        const size_t inpNameLen = strlen(inpName);
        if (inpNameLen >= MAX_SIZE_NAME)
        {
            std::println("The inputed name is over than 128 character");
            return;
        }
        strcpy(name, inpName);
        name[inpNameLen] = '\0';
    }
    const char* getName() const
    {
        return this->name;
    }

    void print() const
    {
        std::println("The alcohol name is: {}", getName());
        std::println("The alcohol price is: {} euro", price);
    }
};

class NightClub
{
private:
    struct BalloonStock {
        Ballon item;
        int quantity = 0;
    };
    struct NargaStock {
        Narga item;
        int quantity = 0;
    };
    struct AlcoholStock {
        Alcohol item;
        int quantity = 0;
    };

    BalloonStock balloons[1024];
    int balloonCount = 0;

    AlcoholStock alcohols[512];
    int alcoholCount = 0;

    NargaStock nargas[256];
    int nargaCount = 0;

    Color parseColor(const char* colorStr) const
    {
        if (strcmp(colorStr, "green") == 0 || strcmp(colorStr, "Green") == 0) return Color::GREEN;
        if (strcmp(colorStr, "red") == 0 || strcmp(colorStr, "Red") == 0) return Color::RED;
        return Color::WHITE;
    }

public:
    void addBalloonFromFile(const char* filename)
    {
        std::ifstream in(filename);
        if (!in.is_open()) return;

        char colorStr[64];
        double price;

        in.getline(colorStr, 64, '-');
        in >> price;
        in.close();

        Color c = parseColor(colorStr);

        for (int i = 0; i < balloonCount; i++) {
            if (balloons[i].item.getColor() == c) {
                balloons[i].quantity++;
                return;
            }
        }

        if (balloonCount < 1024) {
            balloons[balloonCount].item = Ballon(price, c);
            balloons[balloonCount].quantity = 1;
            balloonCount++;
        }
    }

    void addAlcoholFromFile(const char* filename)
    {
        std::ifstream in(filename);
        if (!in.is_open()) return;

        char name[MAX_SIZE_NAME];
        double price;

        in.getline(name, MAX_SIZE_NAME, '-');
        in >> price;
        in.close();

        for (int i = 0; i < alcoholCount; i++) {
            if (strcmp(alcohols[i].item.getName(), name) == 0) {
                alcohols[i].quantity++;
                return;
            }
        }

        if (alcoholCount < 512) {
            alcohols[alcoholCount].item = Alcohol(name, price);
            alcohols[alcoholCount].quantity = 1;
            alcoholCount++;
        }
    }

    void addNargaFromFile(const char* filename)
    {
        std::ifstream in(filename);
        if (!in.is_open()) return;

        char brand[MAX_SIZE_BRAND];
        char flavourStr[64];
        double price;

        in.getline(brand, MAX_SIZE_BRAND, '-');
        in.getline(flavourStr, 64, '-');
        in >> price;
        in.close();

        Narga tempNarga(price, brand, flavourStr);

        for (int i = 0; i < nargaCount; i++) {
            if (strcmp(nargas[i].item.getBrand(), brand) == 0 &&
                nargas[i].item.getFlavour() == tempNarga.getFlavour()) {
                nargas[i].quantity++;
                return;
            }
        }

        if (nargaCount < 256) {
            nargas[nargaCount].item = tempNarga;
            nargas[nargaCount].quantity = 1;
            nargaCount++;
        }
    }

    void removeBalloon(Color c)
    {
        for (int i = 0; i < balloonCount; i++) {
            if (balloons[i].item.getColor() == c) {
                if (balloons[i].quantity > 0) balloons[i].quantity--;
                return;
            }
        }
    }

    void removeAlcohol(const char* name)
    {
        for (int i = 0; i < alcoholCount; i++) {
            if (strcmp(alcohols[i].item.getName(), name) == 0) {
                if (alcohols[i].quantity > 0) alcohols[i].quantity--;
                return;
            }
        }
    }

    void removeNarga(const char* brand, const char* flavourStr)
    {
        Narga temp;
        temp.setFlavour(flavourStr);
        Flavour f = temp.getFlavour();

        for (int i = 0; i < nargaCount; i++) {
            if (strcmp(nargas[i].item.getBrand(), brand) == 0 && nargas[i].item.getFlavour() == f) {
                if (nargas[i].quantity > 0) nargas[i].quantity--;
                return;
            }
        }
    }

    bool hasBalloon(Color c) const
    {
        for (int i = 0; i < balloonCount; i++) {
            if (balloons[i].item.getColor() == c && balloons[i].quantity > 0) return true;
        }
        return false;
    }

    bool hasAlcohol(const char* name) const
    {
        for (int i = 0; i < alcoholCount; i++) {
            if (strcmp(alcohols[i].item.getName(), name) == 0 && alcohols[i].quantity > 0) return true;
        }
        return false;
    }

    bool hasNarga(const char* flavourStr) const
    {
        Narga temp;
        temp.setFlavour(flavourStr);
        Flavour f = temp.getFlavour();

        for (int i = 0; i < nargaCount; i++) {
            if (nargas[i].item.getFlavour() == f && nargas[i].quantity > 0) return true;
        }
        return false;
    }
};
int main()
{
    std::ofstream bOut("balloon.txt");
        bOut << "green-10.50";
        bOut.close();

        std::ofstream aOut("alcohol.txt");
        aOut << "black_label-60.00";
        aOut.close();

        std::ofstream nOut("narga.txt");
        nOut << "OS-Queen-30.00";
        nOut.close();

        NightClub myClub;

        myClub.addBalloonFromFile("balloon.txt");
        myClub.addAlcoholFromFile("alcohol.txt");
        myClub.addNargaFromFile("narga.txt");


        if (myClub.hasBalloon(Color::GREEN)) {
            std::println("We have green balloons!");
        } else {
            std::println("We don't have green balloons!");
        }

        if (myClub.hasAlcohol("black_label")) {
            std::println("We have Black Label!");
        }

        if (myClub.hasNarga("Queen")) {
            std::println("We have a shisha with Queen flavour!");
        }

        myClub.addBalloonFromFile("balloon.txt");

        myClub.removeBalloon(Color::GREEN);
        if (myClub.hasBalloon(Color::GREEN)) {
            std::println("After removing one, we still HAVE green balloons (because we loaded 2).");
        }

        myClub.removeBalloon(Color::GREEN);
        if (!myClub.hasBalloon(Color::GREEN)) {
            std::println("After the second removal, we NO LONGER have green balloons!");
        }

        myClub.removeAlcohol("black_label");
        if (!myClub.hasAlcohol("black_label")) {
            std::println("Black Label was consumed and removed successfully!");
        }

        return 0;
    }

