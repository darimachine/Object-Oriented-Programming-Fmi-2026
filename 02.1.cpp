
#include "02.1.h"

bool Registration::isValid(const char* str) const {
    if (!str) return false;
    int len = (int)strlen(str);
    if (len < 7 || len > 8) return false;

    int i = 0;
    if (str[i] < 'A' || str[i] > 'Z') {
        return false;
    }
    i++;
    if (len == 8) {
        if (str[i] < 'A' || str[i] > 'Z') {
            return false;
        }
        i++;
    }
    for (int j = 0; j < 4; j++, i++) {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }
    }
    for (int j = 0; j < 2; j++, i++) {
        if (str[i] < 'A' || str[i] > 'Z') {
            return false;
        }
    }
    return true;
}

Registration::Registration(const char* str) {
    if (!isValid(str)) {
        strcpy(value, "ERROR");
        return;
    }
    strcpy(value, str);
}

const char* Registration::toString() const {
    return value;
}

std::ostream& operator<<(std::ostream& os, const Registration& r) {
    return os << r.value;
}

bool Registration::operator==(const Registration& other) const {
    return strcmp(value, other.value) == 0;
}

bool Registration::operator!=(const Registration& other) const {
    return !(*this == other);
}

std::strong_ordering Registration::operator<=>(const Registration& other) const {
    return strcmp(value, other.value) <=> 0;
}