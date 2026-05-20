#include "Registration.h"
#include "Utils.h"
#include <cstring>

bool Registration::isValid(const char* plate)
{
    if (!plate) {
        return false;
    }

    size_t len = strlen(plate);

    if (len!=7 && len!=8) {
        return false;
    }

    size_t i = 0;

    if ((!Utils::isUpper(plate[i]))) {
        return false;
    }

    i++;

    if ((Utils::isUpper(plate[i]))) {
        i++;
    }

    for (size_t j = 0; j < 4; j++)
    {
        if ((!Utils::isDigit(plate[i]))) {
            return false;
        }

        i++;
    }

    if (!(Utils::isUpper(plate[i])) || !(Utils::isUpper(plate[i + 1]))) {
        return false;
    }

    i += 2;
    return plate[i] == '\0';

}

Registration::Registration(const char* plate)
{
    
    if (!isValid(plate)) {
        return;                     
    }

    strcpy_s(this->plate, SIZE, plate);

    size_t size = 1;
    if (Utils::isUpper(plate[1])) {
        size = 2;
    }

    strncpy_s(code, size + 1, plate, size);
    code[size] = '\0';
}

const char* Registration::getPlate() const
{
    return plate;
}

const char* Registration::getCode() const
{
    return code;
}

std::ostream& operator<<(std::ostream& os, const Registration& registration)
{
    os << registration.plate;
    return os;
}

bool operator==(const Registration& lhs, const Registration& rhs)
{
    return strcmp(lhs.getPlate(), rhs.getPlate())==0;
}

std::strong_ordering operator<=>(const Registration& lhs, const Registration& rhs)
{

    int cmp = strcmp(lhs.getPlate(), rhs.getPlate());
    if (cmp < 0) {
        return std::strong_ordering::less;
    } 
    if (cmp > 0) {
        return std::strong_ordering::greater;
    } 

    return std::strong_ordering::equal;
}
