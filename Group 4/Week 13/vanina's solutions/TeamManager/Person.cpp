#include "Person.h"

static bool isValidEGN(const std::string& string) {
    return string.size() == 10;
}

Person::Person(const std::string &name, const std::string &middleName, const std::string &surname,
    const std::string &EGN) : name(name), middleName(middleName), surname(surname) {
    if (!isValidEGN(EGN)) {
        throw std::invalid_argument("EGN is not valid");
    }
    this->EGN = EGN;
}

Person::Person(const std::string &name, const std::string &surname,
    const std::string &EGN) : name(name), surname(surname) {
    if (!isValidEGN(EGN)) {
        throw std::invalid_argument("EGN is not valid");
    }
    this->EGN = EGN;
}

const std::string & Person::getName() const {
    return name;
}

const std::string & Person::getMiddleName() const {
    return middleName;
}

const std::string & Person::getSurname() const {
    return surname;
}

const std::string & Person::getEGN() const {
    return EGN;
}

std::unique_ptr<Person> Person::clone() const {
    return std::make_unique<Person>(*this);
}

bool operator==(const Person& lhs, const Person& rhs) {
    return (lhs.getName() == rhs.getName() && lhs.getMiddleName() == rhs.getMiddleName() &&
        lhs.getSurname() == rhs.getSurname() && lhs.getEGN() == rhs.getEGN());
}

auto operator<=>(const Person& lhs, const Person& rhs) {
    if (lhs.getName() != rhs.getName()) {
        return lhs.getName() <=> rhs.getName();
    }
    if (lhs.getMiddleName() != rhs.getMiddleName()) {
        return lhs.getMiddleName() <=> rhs.getMiddleName();
    }
    if (lhs.getSurname() != rhs.getSurname()) {
        return lhs.getSurname() <=> rhs.getSurname();
    }
    if (lhs.getEGN() != rhs.getEGN()) {
        return lhs.getEGN() <=> rhs.getEGN();
    }
    return std::strong_ordering::equal;
}
