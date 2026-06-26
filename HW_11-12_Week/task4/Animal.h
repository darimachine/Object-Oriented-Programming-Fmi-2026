#pragma once
#include <string>
class Animal
{
    std::string name;
    std::string species;
    int age;
public:
    Animal(const std::string& name, const std::string& species, int age);
    const std::string& getName() const;
    const std::string& getSpecies() const;
    int getAge() const;
    void print() const;
};

