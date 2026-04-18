#include "Registration.h"

#include <cstring>
#include <print>

bool Registration::isLetter(const char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool Registration::isNumber(const char c) {
    return (c >= '0' && c <= '9');
}

bool Registration::isValid(const char *str) {
    if (!str) {
        return false;
    }

    const char* p = str;
    int len = 0;
    while (*p && isLetter(*p)) {
        p++;
        len++;
    }

    if (len < 1 || len > 2) {
        return false;
    }

    len = 0;
    while (*p && isNumber(*p)) {
        p++;
        len++;
    }

    if (len != 4) {
        return false;
    }

    len = 0;
    while (*p && isLetter(*p)) {
        p++;
        len++;
    }

    if (len != 2) {
        return false;
    }

    return *p == '\0';


}

Registration::Registration(const char *str) {
    if (!isValid(str)) {
        std::print("Invalid registration number!");
    }
    strcpy(plate, str);
    plate[8] = '\0';
}

const char *Registration::getPlate() const {
    return plate;
}

std::strong_ordering Registration::operator<=>(const Registration &other) const {
    return strcmp(plate, other.plate) <=> 0;
}

bool Registration::operator==(const Registration &other) const {
    return strcmp(plate, other.plate) == 0;
}


std::ostream & operator<<(std::ostream &os, const Registration &reg) {
    return os << reg.plate;
}
