#include "BirdSection.h"
#include "Exhibit.h"
#include "Animal.h"
#include "Section.h"
#include <iostream>

BirdSection::BirdSection(const std::string& name) : Section(name, 0)
{
    addExhibit(std::make_shared<Exhibit>("Birds exhibit 1", 3, AnimalType::Bird));
    addExhibit(std::make_shared<Exhibit>("Birds exhibit 2", 8, AnimalType::Bird));
}

bool BirdSection::addExhibit(std::shared_ptr<Exhibit> exhibit)
{
    if (exhibit) {
        if (exhibit->getType() == AnimalType::Bird) {
            return Section::addExhibit(exhibit);
        }
        else {
            std::cout << "Error! The animal is not of the appropriate type and cannot be added to the exhibit." << std::endl;
        }
    }

    std::cout << "Error! An error occurred while adding a exhibit." << std::endl;

    return false;
}
