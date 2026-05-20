#include "Section.h"

Section::Section(const std::string &name, unsigned minYear): name(name), minYears(minYear) {
    keeper = nullptr;
}

Section::Section(const std::string &name, unsigned minYears,
                 const ZooKeeper &keeper) : name(name), minYears(minYears) {
    if (keeper.getExperienceYears() >= minYears) {
        this->keeper = std::make_shared<ZooKeeper>(keeper);
    }
    else {
        throw std::invalid_argument("Invalid experience years");
    }
}

const std::string & Section::getName() const {
    return name;
}

void Section::addExhibit(Exhibit &&exhibit) {
    exhibits.push_back(std::move(exhibit));
}

bool Section::hasActiveGuard() const {
    return keeper != nullptr;
}

void Section::assignGuard(const std::shared_ptr<ZooKeeper> &zooKeeper) {
    if (!hasActiveGuard()) {
        if (zooKeeper->getExperienceYears() >= minYears) {
            std::cout << "ok experience years\n";
            keeper = zooKeeper;
        }
        else {
            throw std::invalid_argument("Less experience years");
        }
    }
}

Animal*  Section::search(const std::string& nameAnimal) const {
    for (const auto& exhibit:exhibits) {
        if (exhibit.search(nameAnimal) != nullptr) {
            return exhibit.search(nameAnimal);
        }
    }
    return nullptr;
}

void Section::printExhibits() const {
    for (const auto& exhibit : exhibits) {
        exhibit.printAnimals();
    }
}
