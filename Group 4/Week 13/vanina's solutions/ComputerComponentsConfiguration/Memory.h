#ifndef COMPUTERCOMPONENTSCONFIGURATION_MEMORY_H
#define COMPUTERCOMPONENTSCONFIGURATION_MEMORY_H

#include"Component.h"

class Memory : public Component {
    unsigned short capacity;

    static constexpr double MEMORY_PRICE = 49.99;

public:
    Memory(const std::string& label, unsigned short capacity);

    double price() const override;
    void output(std::ostream& os) const override;

    std::unique_ptr<Component> clone() const override;
};


#endif //COMPUTERCOMPONENTSCONFIGURATION_MEMORY_H