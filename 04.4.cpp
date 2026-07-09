#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Balloon {
private:
    char color[20];
    double price;
    int quantity;
public:
    Balloon() { color[0] = '\0'; price = 0; quantity = 0; }
    Balloon(const char* c, double p, int q = 1) { strcpy(color, c); price = p; quantity = q; }

    const char* getColor() const { return color; }
    double getPrice() const { return price; }
};

class Narga {
private:
    char brand[1024];
    char taste[50];
    double price;
public:
    Narga() { brand[0] = '\0'; taste[0] = '\0'; price = 0; }
    Narga(const char* b, const char* t, double p) { strcpy(brand, b); strcpy(taste, t); price = p; }

    const char* getBrand() const { return brand; }
    const char* getTaste() const { return taste; }
    double getPrice() const { return price; }
};

class Alcohol {
private:
    char name[128];
    double price;
public:
    Alcohol() { name[0] = '\0'; price = 0; }
    Alcohol(const char* n, double p) { strcpy(name, n); price = p; }

    const char* getName() const { return name; }
    double getPrice() const { return price; }
};

class NightClub {
private:
    Balloon balloons[1024]; int balloonCount = 0;
    Alcohol alcohols[512]; int alcoholCount = 0;
    Narga nargas[256]; int nargaCount = 0;

    int findBalloon(const char* c) {
        for (int i = 0; i < balloonCount; i++) if (strcmp(balloons[i].getColor(), c) == 0) return i;
        return -1;
    }
    int findAlcohol(const char* n) {
        for (int i = 0; i < alcoholCount; i++) if (strcmp(alcohols[i].getName(), n) == 0) return i;
        return -1;
    }
    int findNarga(const char* b, const char* t) {
        for (int i = 0; i < nargaCount; i++)
            if (strcmp(nargas[i].getBrand(), b) == 0 && strcmp(nargas[i].getTaste(), t) == 0) return i;
        return -1;
    }

public:
    void addBalloon(const char* color, double price) {
        int idx = findBalloon(color);
        if (idx == -1 && balloonCount < 1024) balloons[balloonCount++] = Balloon(color, price);
    }

    void addAlcohol(const char* name, double price) {
        int idx = findAlcohol(name);
        if (idx == -1 && alcoholCount < 512) alcohols[alcoholCount++] = Alcohol(name, price);
    }

    void addNarga(const char* brand, const char* taste, double price) {
        int idx = findNarga(brand, taste);
        if (idx == -1 && nargaCount < 256) nargas[nargaCount++] = Narga(brand, taste, price);
    }

    double calculateBillBalloon(const char* color, int count) {
        int idx = findBalloon(color);
        if (idx != -1) return balloons[idx].getPrice() * count;
        return 0;
    }
    double calculateBillAlcohol(const char* name, int count) {
        int idx = findAlcohol(name);
        if (idx != -1) return alcohols[idx].getPrice() * count;
        return 0;
    }
    double calculateBillNarga(const char* brand, const char* taste, int count) {
        int idx = findNarga(brand, taste);
        if (idx != -1) return nargas[idx].getPrice() * count;
        return 0;
    }
};

int main() {
    NightClub nc;

    nc.addBalloon("green", 25.6);
    nc.addBalloon("red", 30.0);
    nc.addAlcohol("black_label", 60);
    nc.addAlcohol("jameson", 70);
    nc.addNarga("OS", "queen", 30);


    cout << "Ivan's bill" << endl;
    double sum = 0;
    sum += nc.calculateBillBalloon("green", 10);
    sum += nc.calculateBillAlcohol("black_label", 2);
    sum += nc.calculateBillNarga("OS", "queen", 1);

    cout << "Full bill: " << sum << " lv" << endl;

}