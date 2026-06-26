#include "Zoo.h"

std::shared_ptr<ZooKeeper> Zoo::addKeeper(const ZooKeeper &zk) {
    keepers.push_back(std::make_shared<ZooKeeper>(zk));
    return keepers.back();
}

void Zoo::removeKeeper(unsigned employeeID) {
    for (auto it = keepers.begin(); it != keepers.end(); ++it) {
        if ((*it)->getId() == employeeID) {
            keepers.erase(it);
            return;
        }
    }
    // std::cout << "Employee " << employeeID << " not found\n";
}

void Zoo::printAll() const {
    for (const auto& section:sections) {
        std::cout << "\"" << section->getName() << "\":\n";
        section->printExhibits();
    }
}

Animal* Zoo::search(const std::string &name) const {
    for (const auto& section:sections) {
        if (section->search(name) != nullptr) {
            return section->search(name);
        }
    }
    return nullptr;
}

void Zoo::addSection(std::unique_ptr<Section> section) {
    sections.push_back(std::move(section));
}
