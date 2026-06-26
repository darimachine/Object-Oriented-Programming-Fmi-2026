#ifndef ZOOMANAGER_EXHIBIT_H
#define ZOOMANAGER_EXHIBIT_H

#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include "Animal.h"

class Exhibit {
    std::string location;
    std::string type;
    std::vector<std::unique_ptr<Animal>> animals;
    int animalCount;
    int capacity;

public:
    Exhibit(const std::string& location, const std::string& type, int animalCount, int capacity);
    const std::string& getLocation() const;

    bool addAnimal(const Animal& animal);
    bool addAnimal(const std::string& name, const std::string& type, unsigned age);
    bool isFull() const;
    Animal* search(const std::string& name) const;

    void printAnimals() const;
};


#endif //ZOOMANAGER_EXHIBIT_H