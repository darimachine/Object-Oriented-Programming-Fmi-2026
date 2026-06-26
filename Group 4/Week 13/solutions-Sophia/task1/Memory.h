#pragma once
#include <memory>
#include "Component.h"

class Memory : public Component
{
private:
    unsigned short capacity;
    static constexpr double GBS_PRICE = 49.99;
public:
    Memory(const std::string& name, const unsigned short capacity);
    double price() const override;
    void output(std::ostream&) const override;
    std::unique_ptr<Component> clone() const override;
};