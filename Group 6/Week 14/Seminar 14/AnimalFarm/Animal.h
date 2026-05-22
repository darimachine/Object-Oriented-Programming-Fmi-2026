#pragma once
#include <iostream>
#include <string>
#include <memory>

class Animal {
public:
    explicit Animal(const std::string& name);

    const std::string& getName() const;

    virtual void makeSound() const = 0;
    virtual std::unique_ptr<Animal> clone() const = 0;

    virtual ~Animal() = default;

protected:
    std::string name;
};
