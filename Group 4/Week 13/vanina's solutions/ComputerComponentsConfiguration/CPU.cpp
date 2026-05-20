#include "CPU.h"

#include <ostream>

CPU::CPU(const std::string &label, unsigned short cores,
         unsigned short clockSpeed) : Component(label), clockSpeed(clockSpeed) {
    if (cores < 1 || cores > 8) {
        throw std::invalid_argument("Invalid cores specified");
    }
    this->cores = cores;
}

double CPU::price() const {
    return cores * CORES_PRICE;
}

void CPU::output(std::ostream &os) const {
    os << label << " with " << cores << " cores and "
    << clockSpeed << " MHz - " << price() << "€" << std::endl;
}

std::unique_ptr<Component> CPU::clone() const {
    return std::make_unique<CPU>(*this);
}
