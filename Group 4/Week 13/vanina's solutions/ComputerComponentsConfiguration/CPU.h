#ifndef COMPUTERCOMPONENTSCONFIGURATION_CPU_H
#define COMPUTERCOMPONENTSCONFIGURATION_CPU_H

#include "Component.h"

class CPU : public Component {
    unsigned short cores;
    unsigned short clockSpeed;

    static constexpr double CORES_PRICE = 19.99;

public:
    CPU(const std::string& label, unsigned short cores, unsigned short clockSpeed);

    double price() const override;
    void output(std::ostream& os) const override;

    std::unique_ptr<Component> clone() const override;
};


#endif //COMPUTERCOMPONENTSCONFIGURATION_CPU_H