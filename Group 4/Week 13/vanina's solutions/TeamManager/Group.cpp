#include "Group.h"

#include <__iterator/erase_if_container.h>

bool Group::isInGroup(const Person& person) const {
    for (const auto& p : people) {
        if (person == *p) {
            return true;
        }
    }
    return false;
}

bool Group::isInGroup(const std::string &personEGN) const {
    for (const auto& p : people) {
        if (p->getEGN() == personEGN) {
            return true;
        }
    }
    return false;
}

Group::Group(const Group &other) {
    for (const auto& p : other.people) {
        people.push_back(p->clone());
    }
}

Group & Group::operator=(const Group &other) {
    if (this != &other) {
        people.clear();
        for (const auto& p : other.people) {
            people.push_back(p->clone());
        }
    }
    return *this;
}

Group Group::operator+(const Person &person) const {
    Group result = *this;
    result += person;
    return result;
}

Group & Group::operator+=(const Person &person) {
    if (!isInGroup(person)) {
        // people.push_back(std::make_unique<Person>(person));
        people.push_back(person.clone());
    }
    return *this;
}

Group Group::operator-(const Person &person) const {
    Group result = *this;
    result -= person;
    return result;
}

Group & Group::operator-=(const Person &person) {
    if (!isInGroup(person)) {
        throw std::invalid_argument(person.getName() + " is not in Group");
    }

    for (auto it = people.begin(); it != people.end(); ++it) {
        if (person == **it) {
            people.erase(it);
            break;
        }
    }
    return *this;
}

const Person & Group::operator[](const std::string &egn) const {
    for (const auto& p : people) {
        if (egn == p->getEGN()) {
            return *p;
        }
    }
    throw std::invalid_argument(egn + " is not in Group");
}

Person& Group::operator[](const std::string &egn) {
    for (auto& p : people) {
        if (egn == p->getEGN()) {
            return *p;
        }
    }
    throw std::invalid_argument(egn + " is not in Group");
}

size_t Group::operator()() const {
    return people.size();
}

bool Group::operator()(const Person &person) const {
    return isInGroup(person);
}
