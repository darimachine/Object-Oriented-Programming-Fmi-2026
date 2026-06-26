#include "ZooKeeper.h"

unsigned ZooKeeper::idCounter = 0;

ZooKeeper::ZooKeeper(const std::string &name, const std::string &surname,
    unsigned experience) : name(name), surname(surname), experienceYears(experience), id(idCounter++) {
}

unsigned ZooKeeper::getExperienceYears() const {
    return experienceYears;
}

unsigned ZooKeeper::getId() const {
    return id;
}
