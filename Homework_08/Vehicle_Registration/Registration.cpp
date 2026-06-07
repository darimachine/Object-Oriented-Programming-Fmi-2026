#define _CRT_SECURE_NO_WARNINGS

#include "Registration.h"

bool Registration::isLetter(char c) const {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool Registration::isNumber(char c) const {
    return (c >= '0' && c <= '9');
}

bool Registration::isValid(const char* plate) const {
    if (!plate) return false;
    int len = strlen(plate);
    if (len == 8) {
        if (!isLetter(plate[0]) || !isLetter(plate[1])) return false;
        for (int i = 2; i <= 5; i++) if (!isNumber(plate[i])) return false;
        return isLetter(plate[6]) && isLetter(plate[7]);
    }
    if (len == 7) {
        if (!isLetter(plate[0])) return false;
        for (int i = 1; i <= 4; i++) if (!isNumber(plate[i])) return false;
        return isLetter(plate[5]) && isLetter(plate[6]);
    }
    return false;
}

Registration::Registration(const char* plate) {
    if (!isValid(plate)) throw std::invalid_argument("Invalid Registration Format");
    strcpy(this->registrationPlate, plate);
}

const char* Registration::getRegistration() const {
    return registrationPlate;
}

auto Registration::operator<=>(const Registration& other) const {
    return strcmp(this->registrationPlate, other.registrationPlate) <=> 0;
}

bool Registration::operator==(const Registration& other) const {
    return strcmp(this->registrationPlate, other.registrationPlate) == 0;
}

std::ostream& operator<<(std::ostream& os, const Registration& r) {
    os << r.registrationPlate;
    return os;
}