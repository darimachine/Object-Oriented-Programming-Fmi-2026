#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

enum class Color
{
    WHITE,
    GREEN,
    RED
};

enum class Flavor
{
    BLUEBERRY,
    QUEEN,
    MANGO,
    MINT,
    APPLE
};

Color stringToColor(const char* str) {
    if (strcmp(str, "white") == 0) return Color::WHITE;
    if (strcmp(str, "green") == 0) return Color::GREEN;
    if (strcmp(str, "red") == 0) return Color::RED;
    return Color::WHITE;
}

Flavor stringToFlavor(const char* str) {
    if (strcmp(str, "Blueberry") == 0 || strcmp(str, "blueberry") == 0) return Flavor::BLUEBERRY;
    if (strcmp(str, "Queen") == 0 || strcmp(str, "queen") == 0) return Flavor::QUEEN;
    if (strcmp(str, "Mango") == 0 || strcmp(str, "mango") == 0) return Flavor::MANGO;
    if (strcmp(str, "Mint") == 0 || strcmp(str, "mint") == 0) return Flavor::MINT;
    if (strcmp(str, "Apple") == 0 || strcmp(str, "apple") == 0) return Flavor::APPLE;
    return Flavor::BLUEBERRY; 

class Baloon {
private:
    double price;
    Color color;

public:
    Baloon() : price(0.0), color(Color::WHITE) {}

    Baloon(double price, Color color) : price(price), color(color) {}

    double getPrice() const {
        return this->price;
    }

    void setPrice(double price) {
        if (price >= 0) {
            this->price = price;
        }
    }

    Color getColor() const {
        return this->color;
    }

    void setColor(Color color) {
        if (color == Color::WHITE || color == Color::GREEN || color == Color::RED) {
            this->color = color;
        }
    }
}; 


class Narga {
private:
    double price;
    char brand[1024];
    Flavor flavor;

public:
    Narga() : price(0.0), flavor(Flavor::BLUEBERRY) {
        brand[0] = '\0';
    }

    Narga(double price, const char* brand, Flavor flavor) : price(price), flavor(flavor) {
        setBrand(brand);
    }

    double getPrice() const {
        return this->price;
    }

    void setPrice(double p) {
        if (price >= 0) {
            this->price = p;
        }
    }

    const char* getBrand() const {
        return this->brand;
    }

    void setBrand(const char* brand) {
        if (brand) {
            strncpy(this->brand, brand, 1023);
            this->brand[1023] = '\0';
        }
    }

    Flavor getFlavor() const {
        return this->flavor;
    }

    void setFlavor(Flavor flavor) {
        if (flavor == Flavor::BLUEBERRY || flavor == Flavor::QUEEN || flavor == Flavor::MANGO || flavor == Flavor::MINT || flavor == Flavor::APPLE) {
            this->flavor = flavor;
        }
    }

    void read() {
        cout << "Enter brand: ";
        cin.ignore();
        cin.getline(brand, 1024);

        char flavorStr[64];
        cout << "Enter flavor (Blueberry, Queen, Mango, Mint, Apple): ";
        cin >> flavorStr;
        flavor = stringToFlavor(flavorStr);

        cout << "Enter price: ";
        cin >> price;
    }

    void print() const {
        int flavorInt = static_cast<int>(flavor);
        cout << "Narga: " << brand << ", Flavor code: " << flavorInt << ", Price: " << price << " lv.\n";
    }
};


class Alchohol {
private:
    char name[128];
    double price;

public:
    Alchohol() : price(0.0) {
        name[0] = '\0';
    }

    Alchohol(const char* name, double price) : price(price) {
        setName(name);
    }

    const char* getName() const {
        return name;
    }

    void setName(const char* name) {
        if (name) {
            strncpy(this->name, name, 127);
            this->name[127] = '\0';
        }
    }

    double getPrice() const {
        return this->price;
    }

    void setPrice(double price) {
        this->price = price;
    }
};


struct BaloonEntry {
    Baloon b;
    int count;
};

struct NargaEntry {
    Narga n;
    int count;
};

struct AlcEntry {
    Alchohol a;
    int count;
};


class NightClub {
private:
    BaloonEntry balloons[1024];
    int bCount = 0;

    AlcEntry alcohols[512];
    int aCount = 0;

    NargaEntry nargas[256];
    int nCount = 0;

public:
    void addBaloonsFromFile(const char* filename) {
        ifstream file(filename);
        if (!file.is_open()) 
        {
            return;
        }

        char colorStr[64], priceStr[64];
        while (file.getline(colorStr, 64, '-')) {
            file.getline(priceStr, 64);
            Color c = stringToColor(colorStr);
            double p = atof(priceStr);

            bool found = false;
            for (int i = 0; i < bCount; ++i) {
                if (balloons[i].b.getColor() == c) {
                    balloons[i].count++;
                    found = true; break;
                }
            }
            if (!found && bCount < 1024) {
                balloons[bCount].b = Baloon(p, c);
                balloons[bCount].count = 1;
                bCount++;
            }
        }
    }

    void addNargasFromFile(const char* filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            return;
        }

        char brand[1024], flavorStr[64], priceStr[64];
        while (file.getline(brand, 1024, '-')) {
            file.getline(flavorStr, 64, '-');
            file.getline(priceStr, 64);

            Flavor f = stringToFlavor(flavorStr);
            double p = atof(priceStr);

            bool found = false;
            for (int i = 0; i < nCount; ++i) {
                if (strcmp(nargas[i].n.getBrand(), brand) == 0 && nargas[i].n.getFlavor() == f) {
                    nargas[i].count++;
                    found = true; break;
                }
            }
            if (!found && nCount < 256) {
                nargas[nCount].n = Narga(p, brand, f);
                nargas[nCount].count = 1;
                nCount++;
            }
        }
    }

    void addAlchoholFromFile(const char* filename) {
        ifstream file(filename);
        if (!file.is_open()) return;

        char name[128], priceStr[64];
        while (file.getline(name, 128, '-')) {
            file.getline(priceStr, 64);
            double p = atof(priceStr);

            bool found = false;
            for (int i = 0; i < aCount; ++i) {
                if (strcmp(alcohols[i].a.getName(), name) == 0) {
                    alcohols[i].count++;
                    found = true; break;
                }
            }
            if (!found && aCount < 512) {
                alcohols[aCount].a = Alchohol(name, p);
                alcohols[aCount].count = 1;
                aCount++;
            }
        }
    }

    void removeBaloon(Color c) {
        for (int i = 0; i < bCount; ++i) {
            if (balloons[i].b.getColor() == c) {
                balloons[i].count--;
                if (balloons[i].count <= 0) {
                    for (int j = i; j < bCount - 1; ++j) balloons[j] = balloons[j + 1];
                    bCount--;
                }
                break;
            }
        }
    }

    void removeNarga(const char* brand, Flavor f) {
        for (int i = 0; i < nCount; ++i) {
            if (strcmp(nargas[i].n.getBrand(), brand) == 0 && nargas[i].n.getFlavor() == f) {
                nargas[i].count--;
                if (nargas[i].count <= 0) {
                    for (int j = i; j < nCount - 1; ++j) nargas[j] = nargas[j + 1];
                    nCount--;
                }
                break;
            }
        }
    }

    void removeAlchohol(const char* name) {
        for (int i = 0; i < aCount; ++i) {
            if (strcmp(alcohols[i].a.getName(), name) == 0) {
                alcohols[i].count--;
                if (alcohols[i].count <= 0) {
                    for (int j = i; j < aCount - 1; ++j) alcohols[j] = alcohols[j + 1];
                    aCount--;
                }
                break;
            }
        }
    }

    bool hasBaloon(Color c) const {
        for (int i = 0; i < bCount; ++i) {
            if (balloons[i].b.getColor() == c && balloons[i].count > 0) return true;
        }
        return false;
    }

    bool hasAlchohol(const char* name) const {
        for (int i = 0; i < aCount; ++i) {
            if (strcmp(alcohols[i].a.getName(), name) == 0 && alcohols[i].count > 0) return true;
        }
        return false;
    }

    bool hasNarga(Flavor f) const {
        for (int i = 0; i < nCount; ++i) {
            if (nargas[i].n.getFlavor() == f && nargas[i].count > 0) return true;
        }
        return false;
    }

    double getAlcPrice(const char* name) {
        for (int i = 0; i < aCount; ++i)
            if (strcmp(alcohols[i].a.getName(), name) == 0) return alcohols[i].a.getPrice();
        return 0.0;
    }
    double getBaloonPrice(Color c) {
        for (int i = 0; i < bCount; ++i)
            if (balloons[i].b.getColor() == c) return balloons[i].b.getPrice();
        return 0.0;
    }
    double getNargaPrice(const char* brand, Flavor f) {
        for (int i = 0; i < nCount; ++i)
            if (strcmp(nargas[i].n.getBrand(), brand) == 0 && nargas[i].n.getFlavor() == f) return nargas[i].n.getPrice();
        return 0.0;
    }

    double calculateBill(const char* clientFile) {
        ifstream file(clientFile);
        if (!file.is_open()) return 0.0;

        char line[512];
        int mode = 0;
        double total = 0.0;

        while (file.getline(line, 512)) {
            if (strcmp(line, "Alchohols:") == 0) { mode = 1; continue; }
            if (strcmp(line, "Baloons:") == 0) { mode = 2; continue; }
            if (strncmp(line, "Narga", 5) == 0) { mode = 3; continue; }

            if (mode == 1) {
                char* dash = strchr(line, '-');
                if (dash) {
                    *dash = '\0';
                    char* name = line;
                    int count = atoi(dash + 1);
                    total += getAlcPrice(name) * count;
                }
            }
            else if (mode == 2) {
                char* dash = strchr(line, '-');
                if (dash) {
                    *dash = '\0';
                    Color c = stringToColor(line);
                    int count = atoi(dash + 1);
                    total += getBaloonPrice(c) * count;
                }
            }
            else if (mode == 3) {
                char* dash1 = strchr(line, '-');
                if (dash1) {
                    *dash1 = '\0';
                    char* brand = line;
                    char* dash2 = strchr(dash1 + 1, '-');
                    if (dash2) {
                        *dash2 = '\0';
                        Flavor f = stringToFlavor(dash1 + 1);
                        int count = atoi(dash2 + 1);
                        total += getNargaPrice(brand, f) * count;
                    }
                }
            }
        }
        return total;
    }
};


struct Client {
    char* name;
    char* billFile;

    Client(const char* n = "", const char* f = "") {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        billFile = new char[strlen(f) + 1];
        strcpy(billFile, f);
    }

    Client(const Client& other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        billFile = new char[strlen(other.billFile) + 1];
        strcpy(billFile, other.billFile);
    }

    Client& operator=(const Client& other) {
        if (this != &other) {
            delete[] name;
            delete[] billFile;

            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
            billFile = new char[strlen(other.billFile) + 1];
            strcpy(billFile, other.billFile);
        }
        return *this;
    }

    ~Client() {
        delete[] name;
        delete[] billFile;
    }
}; 

void calculateDailyProfit(NightClub& club, Client* clients, int numClients) {
    ofstream out("money.dat", ios::binary);
    if (!out.is_open()) return;

    for (int i = 0; i < numClients; ++i) {
        double amountDue = club.calculateBill(clients[i].billFile);

        int nameLen = strlen(clients[i].name);
        out.write((const char*)&nameLen, sizeof(nameLen));
        out.write(clients[i].name, nameLen);
        out.write((const char*)&amountDue, sizeof(amountDue));

        cout << "Client: " << clients[i].name << " should pay " << amountDue << " lv.\n";
    }
    out.close();
}
