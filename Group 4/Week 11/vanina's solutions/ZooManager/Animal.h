#ifndef ZOOMANAGER_ANIMAL_H
#define ZOOMANAGER_ANIMAL_H

#include <string>
#include <iostream>

class Animal {
    std::string name;
    std::string type;
    unsigned age;

public:
    Animal(const std::string& name, const std::string& type, unsigned age);

    const std::string& getType() const;
    const std::string& getName() const;

    void print() const;
};


#endif //ZOOMANAGER_ANIMAL_H