#ifndef TEAMMANAGER_GROUP_H
#define TEAMMANAGER_GROUP_H

#include<memory>
#include<vector>

#include "Person.h"

class Group {
    std::vector<std::unique_ptr<Person>> people;

public:
    Group() = default;

    Group(const Group& other);
    Group& operator=(const Group& other);

    Group operator+(const Person& person) const;
    Group& operator+=(const Person& person);
    Group operator-(const Person& person) const;
    Group& operator-=(const Person& person);

    const Person& operator[](const std::string& egn) const;
    Person& operator[](const std::string& egn);

    size_t operator()() const;
    bool operator()(const Person& person) const;

    bool isInGroup(const Person& person) const;
    bool isInGroup(const std::string& personEGN) const;
};



#endif //TEAMMANAGER_GROUP_H