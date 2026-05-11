#include "Registration.h"

bool Registration::isValid(const char* str)
{
    if (!str) return false;
    int len = strlen(str);

    if (len < 7 || len > 8) return false;

    int i = 0;
    int lettersCount = 0;
    while (i < len && (str[i] >= 'A' && str[i] <= 'Z')) {
        lettersCount++;
        i++;
    }
    if (lettersCount < 1 || lettersCount > 2) return false;

    int digitsCount = 0;
    while (i < len && (str[i] >= '0' && str[i] <= '9')) {
        digitsCount++;
        i++;
    }
    if (digitsCount != 4) return false;

    int suffixCount = 0;
    while (i < len && (str[i] >= 'A' && str[i] <= 'Z')) {
        suffixCount++;
        i++;
    }

    return (suffixCount == 2 && i == len);
}

Registration::Registration(const char* str)
{
    if (!str || !isValid(str)) {
        return;
    }
    strcpy(plate, str);
}

const char* Registration::getPlate() const
{
    return plate;
}

std::ostream& operator<<(std::ostream& os, const Registration& r)
{
    os << r.plate << " ";
    return os;
}

bool operator==(const Registration& lhs, const Registration& rhs)
{
    if (strcmp(lhs.getPlate(), rhs.getPlate()) == 0) return true;
    return false;
}

bool operator!=(const Registration& lhs, const Registration& rhs)
{
    return !(lhs == rhs);
}

std::strong_ordering operator<=>(const Registration& lhs, const Registration& rhs)
{
    return strcmp(lhs.getPlate(), rhs.getPlate()) <=> 0;
}
