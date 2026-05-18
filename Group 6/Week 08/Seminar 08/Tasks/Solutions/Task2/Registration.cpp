#include "Registration.h"

bool Registration::validateNumber(const char* regNumber) const
{
    if (!regNumber) return false;

    size_t len = strlen(regNumber);

    if (len != 7 && len != 8) return false;

    if (len == 8) 
    {
        if (!isupper(regNumber[0]) || !isupper(regNumber[1])) return false;
        if (!isdigit(regNumber[2]) || !isdigit(regNumber[3]) ||
            !isdigit(regNumber[4]) || !isdigit(regNumber[5])) return false;
        if (!isupper(regNumber[6]) || !isupper(regNumber[7])) return false;
    }
    else
    {
        if (!isupper(regNumber[0])) return false;
        if (!isdigit(regNumber[1]) || !isdigit(regNumber[2]) ||
            !isdigit(regNumber[3]) || !isdigit(regNumber[4])) return false;
        if (!isupper(regNumber[5]) || !isupper(regNumber[6])) return false;
    }

    return true;
}

void Registration::free()
{
    delete[] this->regNumber;
    this->regNumber = nullptr;
}

void Registration::copyFrom(const Registration& other) {
    if (other.regNumber) {
        this->regNumber = new char[strlen(other.regNumber) + 1];
        strcpy(this->regNumber, other.regNumber);
    }
    else {
        this->regNumber = nullptr;
    }
}

void Registration::moveFrom(Registration&& other) noexcept
{
    this->regNumber = other.regNumber;
    other.regNumber = nullptr;
}

Registration::Registration(const char* regNumber) : regNumber(nullptr)
{
    if (validateNumber(regNumber))
    {
        this->regNumber = new char[strlen(regNumber) + 1];
        strcpy(this->regNumber, regNumber);
    }
    else
    {
        this->regNumber = new char[9];
        strcpy(this->regNumber, "XX0000XX");
    }
}

Registration::Registration(const Registration& other)
{
    copyFrom(other);
}

Registration& Registration::operator=(const Registration& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Registration::Registration(Registration&& other) noexcept
{
    moveFrom(std::move(other));
}

Registration& Registration::operator=(Registration&& other) noexcept
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

Registration::~Registration()
{
    free();
}

const char* Registration::c_str() const
{
    return this->regNumber;
}

std::ostream& operator<<(std::ostream& os, const Registration& reg)
{
    os << reg.regNumber;
    return os;
}

bool operator<(const Registration& reg1, const Registration& reg2)
{
    return strcmp(reg1.regNumber, reg2.regNumber) < 0;
}

bool operator==(const Registration& reg1, const Registration& reg2)
{
    return strcmp(reg1.regNumber, reg2.regNumber) == 0;
}

bool operator>(const Registration& reg1, const Registration& reg2)
{
    return reg2 < reg1;
}
