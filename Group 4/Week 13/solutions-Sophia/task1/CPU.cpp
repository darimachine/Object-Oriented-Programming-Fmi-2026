#include "CPU.h"
#include "Component.h"
#include <stdexcept>
#include <iostream>

CPU::CPU(const std::string& name, const unsigned short cores, const unsigned short clock_speed) : Component(name), clock_speed(clock_speed)
{
    if (cores < 0 || cores > 8) {
        throw std::invalid_argument("invalid core number!");
    }
    this->cores = cores;
}

double CPU::price() const
{
    return cores * CORES_PRICE;
}

void CPU::output(std::ostream& os) const
{
    os << "label: " << label << ", cores:" << cores << ", clock_speed: " << clock_speed << ", price: " << price();;
}   

std::unique_ptr<Component> CPU::clone() const
{
    return std::make_unique<CPU>(*this);
}