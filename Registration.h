#pragma once
#include <string>
#include <iostream>
class Registration
{
private:
    std::string number;

    static bool isValid(const char* str);

public:
    explicit Registration(const char* str);

    const std::string& getNumber() const;
    std::string getTownCode() const;
    const char* c_str() const;

    bool operator==(const Registration& other) const;
    bool operator!=(const Registration& other) const;
    bool operator<(const Registration& other) const;
    bool operator>(const Registration& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Registration& reg);

};

