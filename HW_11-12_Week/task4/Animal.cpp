#include "Animal.h"
#include "ZooException.h"
#include <iostream>
#include "Exhibit.h"
#include "ZooKeeper.h"

Animal::Animal(const std::string& name, const std::string& species, int age) : name(name), species(species), age(age)
{
    if (name.empty())
    {
        throw ZooException("Animal name cannot be empty.");
    }
    if (species.empty())
    {
        throw ZooException("Animal species cannot be empty.");
    }
    if (age < 0)
    {
        throw ZooException("Animal age cannot be negative.");
    }
}

const std::string& Animal::getName() const
{ 
    return name; 
}

const std::string& Animal::getSpecies() const
{
    return species;
}

int Animal::getAge() const
{
    return age;
}

void Animal::print() const
{
    std::cout << "Animal: " << name << " (" << species << ", age " << age << ")" << std::endl;
}