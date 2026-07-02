#pragma once
class Alchohol
{
private:
    char name[129];
    double price;

public:
    Alchohol();
    Alchohol(const char* name, double price);
    const char* getName()  const;
    double getPrice() const;
    void setName(const char* name);
    void setPrice(double price);
};

