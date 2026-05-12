#include "ReptileSection.h"
#include "Exhibit.h"
#include "Animal.h"
#include <iostream>

ReptileSection::ReptileSection(const std::string& name) : Section(name, 5)
{
    addExhibit(std::make_shared<Exhibit>("Reptiles exhibit 1", 5, AnimalType::Reptyle));
}

bool ReptileSection::addExhibit(std::shared_ptr<Exhibit> exhibit)
{
    if (exhibit) {
        if (exhibit->getType() == AnimalType::Reptyle) {
            return Section::addExhibit(exhibit);
        }
        else {
            std::cout << "Error! The animal is not of the appropriate type and cannot be added to the exhibit." << std::endl;
        }
    }

    std::cout << "Error! An error occurred while adding a exhibit." << std::endl;
    return false;
}
