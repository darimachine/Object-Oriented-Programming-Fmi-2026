#pragma once
#include "Animal.h"

class Cow : public Animal {
public:
    explicit Cow(const std::string& name);
    void makeSound() const override;
    std::unique_ptr<Animal> clone() const override;
};
