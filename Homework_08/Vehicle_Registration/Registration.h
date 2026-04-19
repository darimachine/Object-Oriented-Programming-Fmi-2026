#pragma once
#include <iostream>
#include <compare>
#include <cstring>
#include <stdexcept>

static constexpr int MAX_REGISTRATION_LENGTH = 9;

class Registration {
    char registrationPlate[MAX_REGISTRATION_LENGTH];

    bool isValid(const char* plate) const;
    bool isLetter(char c) const;
    bool isNumber(char c) const;

public:
    Registration(const char* plate);
    const char* getRegistration() const;

    auto operator<=>(const Registration& other) const;
    bool operator==(const Registration& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Registration& r);
};