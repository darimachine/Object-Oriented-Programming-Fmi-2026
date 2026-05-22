#pragma once
#include "Animal.h"

class Pig : public Animal {
public:
    explicit Pig(const std::string& name);
    void makeSound() const override;
    std::unique_ptr<Animal> clone() const override;
};
