#pragma once
#include "Animal.h"

class Sheep : public Animal {
public:
    explicit Sheep(const std::string& name);
    void makeSound() const override;
    std::unique_ptr<Animal> clone() const override;
};
