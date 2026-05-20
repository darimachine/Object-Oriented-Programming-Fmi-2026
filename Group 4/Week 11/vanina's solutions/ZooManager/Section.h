#ifndef ZOOMANAGER_SECTION_H
#define ZOOMANAGER_SECTION_H

#include <memory>
#include <string>
#include <vector>

#include "Exhibit.h"
#include "ZooKeeper.h"

class Section {

    std::string name;
    unsigned minYears;
    std::vector<Exhibit> exhibits;
    std::shared_ptr<ZooKeeper> keeper;

public:
    static constexpr unsigned MIN_BIRD_YEARS = 0;
    static constexpr unsigned MIN_MAMMAL_YEARS = 3;
    static constexpr unsigned MIN_REPTILE_YEARS = 5;

    Section() = default;
    Section(const std::string& name, unsigned minYear);
    Section(const std::string& name, unsigned minYears, const ZooKeeper& keeper);
    const std::string& getName() const;

    void addExhibit(Exhibit&& exhibit);
    bool hasActiveGuard() const;
    void assignGuard(const std::shared_ptr<ZooKeeper> &zooKeeper);

    Animal* search(const std::string& nameAnimal) const;

    void printExhibits() const;
};


#endif //ZOOMANAGER_SECTION_H