#pragma once
#include "Component.h"

class CPU : public Component
{
private:
    static constexpr double  priceByCore = 19.99;

    unsigned short cores; //1-8
    unsigned short clockSpeed; 

public:
    CPU(const std::string& ticket, unsigned short cores, unsigned short clockSpeed);

    std::unique_ptr<Component> clone() const override;

    double price() const override; //returns the price

    void output(std::ostream& os) const override;
};


