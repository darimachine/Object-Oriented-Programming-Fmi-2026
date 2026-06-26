#include "Section.h"

Section::Section(std::string name, int minExp) : name(name), minExperience(minExp) {}

void Section::addExhibit(const Exhibit& e) 
{
    exhibits.push_back(e);
}

bool Section::assignGuard(std::shared_ptr<ZooKeeper> guard) {
    if (guard && guard->getExperience() >= minExperience) {
        activeGuard = guard;
        return true;
    }
    return false;
}

bool Section::hasActiveGuard() const
{ 
    return !activeGuard.expired();
}
const std::string& Section::getName() const
{ 
    return name;
}
const std::vector<Exhibit>& Section::getExhibits() const 
{ 
    return exhibits; 
}

BirdSection::BirdSection() : Section("Bird Section", 0) {}
MammalSection::MammalSection() : Section("Mammal Section", 3) {}
ReptileSection::ReptileSection() : Section("Reptile Section", 5) {}