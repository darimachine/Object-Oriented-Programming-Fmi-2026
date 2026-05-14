#pragma once
enum class Taste 
{ 
    BLUEBERRY,
    QUEEN,
    MANGO,
    PEACH,
    STRAWBERRY,
    COUNT
};
class Narga
{
private:
    double price;
    char   brand[1025];
    Taste taste;
public:
    Narga();
    Narga(double price, const char* brand, Taste taste);
    double getPrice() const;
    const char* getBrand() const;
    Taste  getTaste() const;
    void setPrice(double price);
    void setBrand(const char* brand);
    void setTaste(Taste taste);
    void readFromInput();
    void print() const;
    static Taste tasteFromString(const char* string);
    static const char* tasteToString(Taste taste);
};

