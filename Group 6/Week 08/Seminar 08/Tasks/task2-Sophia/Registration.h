#pragma once
#include <iostream>
#include <cstring>

class Registration {
private:
    char value[10]; // Максимален валиден номер е 8 символа + \0

    bool isValid(const char* str) const;

public:
    // Класът няма конструктор по подразбиране според условието
    Registration(const char* str);

    const char* toString() const;

    bool operator==(const Registration& other) const;
    bool operator!=(const Registration& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Registration& r);
};