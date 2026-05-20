#pragma once
#include "Component.h"
class Memory : public Component
{
private:
    static constexpr double  priceByCapacity = 49.99;

    unsigned short capacity; //GBs 1-10000
    
public:
    Memory(const std::string& ticket, short capacity);

    std::unique_ptr<Component> clone() const override;

    double price() const override; //returns the price

    void output(std::ostream& os) const override;
};

