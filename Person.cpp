#include "Person.h"
#include<stdexcept>

Person::Person(const std::string& firstName, const std::string& secondName, const std::string& thirdName, const std::string& EGN)
{
    if (firstName.size() > MAX_LEN_STRING || secondName.size() > MAX_LEN_STRING || thirdName.size() > MAX_LEN_STRING ||
        firstName.empty() || thirdName.empty())
    {
        throw std::invalid_argument("Invalid input for the names.");
    }

    if (EGN.size() != EGN_LEN)
    {
        throw std::invalid_argument("The EGN must be 10 digits.");
    }

    if (Utils::hasLetters(EGN))
    {
        throw std::invalid_argument("The EGN must include only digits.");
    }

    this->firstName = firstName;
    this->secondName = secondName;
    this->thirdName = thirdName;
    this->EGN = EGN;
}

Person::Person(const std::string& firstName, const std::string& thirdName, const std::string& EGN):
    Person(firstName,"",thirdName,EGN){}

const std::string& Person::getFirstName() const
{
    return firstName;
}

const std::string& Person::getSecondName() const
{
    return secondName;
}

const std::string& Person::getThirdName() const
{
    return thirdName;
}

const std::string& Person::getEGN() const
{
    return EGN;
}

std::strong_ordering operator<=>(const Person& lhs, const Person& rhs)
{
    return lhs.getEGN() <=> rhs.getEGN();
}

bool operator==(const Person& lhs, const Person& rhs)
{
    return lhs.getEGN() == rhs.getEGN();
}