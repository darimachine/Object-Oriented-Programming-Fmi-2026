#include "Registration.h"
#include <iostream>

bool Registration::isValid(const char* str)
{
    if (!str)
    {
        return false;
    }

    size_t len = std::strlen(str);

    if (len != 7 && len != 8)
    {
        return false;
    }

    int length = (len == 7) ? 1 : 2;

    for (int i = 0; i < length; ++i)
    {
        if (!std::isalpha(static_cast<unsigned char>(str[i])))
        {
            return false;
        }
    }

    for (int i = length; i < length + 4; ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
        {
            return false;
        }
    }

    for (int i = length + 4; i < length + 6; ++i)
    {
        if (!std::isalpha(static_cast<unsigned char>(str[i])))
        {
            return false;
        }
    }

    return true;
}

Registration::Registration(const char* str)
{
    if (!isValid(str))
    {
        std::cout<<"Invalid registration number.";
    }

    number = str;
}

const std::string& Registration::getNumber() const
{
    return number;
}


std::string Registration::getTownCode() const
{
    if (number.size() == 7)
    {
        return number.substr(0, 1);
    }

    return number.substr(0, 2);
}

const char* Registration::c_str() const
{
    return number.c_str();
}

bool Registration::operator==(const Registration& other) const
{
    return number == other.number;
}

bool Registration::operator!=(const Registration& other) const
{
    return !(*this == other);
}

bool Registration::operator<(const Registration& other) const
{
    return number < other.number;
}

bool Registration::operator>(const Registration& other) const
{
    return number > other.number;
}

std::ostream& operator<<(std::ostream& os, const Registration& reg)
{
    os << reg.number;
    return os;
}
