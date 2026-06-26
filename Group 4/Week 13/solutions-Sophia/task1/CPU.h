#pragma once
#include "Component.h"
class CPU : public Component
{
private:
    unsigned short cores;
    unsigned short clock_speed;
    static constexpr double CORES_PRICE = 19.99;
public:
    CPU(const std::string& name, const unsigned short cores, const unsigned short clock_speed);
    double price() const override;
    void output(std::ostream&) const override;
    std::unique_ptr<Component> clone() const override;
};