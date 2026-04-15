#pragma once
#include <compare>
#include <iostream>

class Registration {
private:
    char plate[9]{};

    static bool isLetter(const char c);
    static bool isNumber(const char c);
    static bool isValid(const char* str);

public:
    explicit Registration(const char* str);

    const char* getPlate() const;

    std::strong_ordering operator<=>(const Registration& other) const;
    bool operator==(const Registration& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Registration& reg);
};
