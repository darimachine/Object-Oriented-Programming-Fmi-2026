#pragma once
#include <vector>
#include <stdexcept>
#include "Animal.h"

class AnimalFarm {

private:
    std::vector<std::unique_ptr<Animal>> animals;

    void free();
    void copyFrom(const AnimalFarm& other);

public:
    AnimalFarm() = default;

    AnimalFarm(const AnimalFarm& other);
    AnimalFarm& operator=(const AnimalFarm& other);

    AnimalFarm(AnimalFarm&& other) noexcept = default;
    AnimalFarm& operator=(AnimalFarm&& other) noexcept = default;

    void addAnimal(const Animal& animal);
    void addAnimal(const std::unique_ptr<Animal>& animal);

    void wakeUpAnimals() const;


};
