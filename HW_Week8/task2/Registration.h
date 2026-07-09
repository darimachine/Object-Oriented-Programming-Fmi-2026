#pragma once
#include <ostream>

class Registration
{
private:
     static const int MAX_REG_NUMBER = 10;
    char reg[MAX_REG_NUMBER];

    static bool validate(const char* str);
    static bool checkLetters(const char* str, int start, int count);
    static bool checkDigits(const char* str, int start, int count);
    

public:
    Registration() = delete;
    explicit Registration(const char* str);

    const char* toString() const;
    bool isValid() const;

    bool operator==(const Registration& other) const;
    bool operator!=(const Registration& other) const;
    bool operator<(const Registration& other) const;
    bool operator>(const Registration& other) const;

    void getCity(char* out) const;

    friend std::ostream& operator<<(std::ostream& os, const Registration& registration);
};

