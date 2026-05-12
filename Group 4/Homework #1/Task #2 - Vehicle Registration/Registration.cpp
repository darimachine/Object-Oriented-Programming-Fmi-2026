//
// Created by Boris Bozhilov on 4/18/2026.
//

#include "Registration.h"
#include "Utility.h"

#include <cstring>
#include <iostream>

// utility functions


bool Registration::checkRegistrationValidity(const char* registration) {

    if (registration == nullptr) return false;

    const unsigned int registrationLength = strlen(registration);

    // size checks
    if (registrationLength > MAX_LENGTH_OF_REGISTRATION) return false;
    if (registrationLength < MIN_LENGTH_OF_REGISTRATION) return false;

    // first part check
    if (!Utility::isLetter(registration[0])) return false;
    if (registrationLength == MAX_LENGTH_OF_REGISTRATION && !Utility::isLetter(registration[1])) return false;
    if (registrationLength == MIN_LENGTH_OF_REGISTRATION && !Utility::isDigit(registration[1])) return false;

    // second part check
    if (!Utility::isDigit(registration[2])) return false;
    if (!Utility::isDigit(registration[3])) return false;
    if (!Utility::isDigit(registration[4])) return false;
    if (registrationLength == MAX_LENGTH_OF_REGISTRATION && !Utility::isDigit(registration[5])) return false;
    if (registrationLength == MIN_LENGTH_OF_REGISTRATION && !Utility::isLetter(registration[5])) return false;

    // third part check
    if (!Utility::isLetter(registration[6])) return false;
    if (registrationLength == MAX_LENGTH_OF_REGISTRATION && !Utility::isLetter(registration[7])) return false;

    return true;
}

bool Registration::isValid() const {

    if (registration == nullptr) return false;
    return checkRegistrationValidity(registration);
}

// rule of 5
Registration::Registration(const char *registration) {

    if (!checkRegistrationValidity(registration)) return;

    Utility::copyStringData(registration, this->registration);
}

Registration::Registration(const Registration &other) {

    if (!other.isValid()) return;

    Utility::copyStringData(other.registration, this->registration);
}

Registration &Registration::operator=(const Registration &other) {

    if (this == &other) return *this;
    if (!other.isValid()) return *this;

    Utility::copyStringData(other.registration, this->registration);

    return *this;
}

Registration::Registration(Registration &&other) noexcept {

    if (!other.isValid()) return;

    Utility::moveStringData(other.registration, this->registration);
}

Registration &Registration::operator=(Registration &&other) noexcept {

    if (this == &other) return *this;
    if (!other.isValid()) return *this;

    Utility::moveStringData(other.registration, this->registration);

    return *this;
}

Registration::~Registration() {

    delete[] registration;
    registration = nullptr;
}

// methods
char *Registration::getRegistrationAsString() const {

    return registration;
}

// operators
bool Registration::operator==(const Registration &other) const {

    return strcmp(registration, other.registration) == 0;
}

std::strong_ordering Registration::operator<=>(const Registration &other) const {

    const int stringCompare = strcmp(registration, other.registration);

    if (stringCompare < 0) return std::strong_ordering::less;
    if (stringCompare > 0) return std::strong_ordering::greater;
    return std::strong_ordering::equal;
}

std::ostream &operator<<(std::ostream &output, const Registration &registration) {

    output << registration.registration;

    return output;
}
