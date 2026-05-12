#include "MammalSection.h"
#include "Exhibit.h"
#include "Animal.h"
#include <iostream>

MammalSection::MammalSection(const std::string& name) : Section(name, 3)
{
    addExhibit(std::make_shared<Exhibit>("Mammals exhibit 1", 1, AnimalType::Mammal));
}

bool MammalSection::addExhibit(std::shared_ptr<Exhibit> exhibit)
{
    if (exhibit) {
        if (exhibit->getType() == AnimalType::Mammal) {
            return Section::addExhibit(exhibit);
        }
        else {
            std::cout << "Error! The animal is not of the appropriate type and cannot be added to the exhibit." << std::endl;
        }
    }

    std::cout << "Error! An error occurred while adding a exhibit." << std::endl;
    return false;
}
