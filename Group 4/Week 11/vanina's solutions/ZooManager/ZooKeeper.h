#ifndef ZOOMANAGER_GUARD_H
#define ZOOMANAGER_GUARD_H

#include <string>

class ZooKeeper {
    static unsigned idCounter;
    unsigned id;
    std::string name;
    std::string surname;
    unsigned experienceYears;

public:
    ZooKeeper(const std::string& name, const std::string& surname, unsigned experience);

    unsigned getExperienceYears() const;
    unsigned getId() const;
};


#endif //ZOOMANAGER_GUARD_H