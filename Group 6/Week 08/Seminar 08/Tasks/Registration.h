#pragma once
#include <iostream>

class Registration {
    char carNum[9];
    bool isValidRegistration(const char* carNum_) const;
    void copyFrom(const Registration& other);

public:
    Registration(const char* carNum_);
    Registration(const Registration& other);
    Registration& operator=(const Registration& other);
    bool operator==(const Registration& other) const;
    bool operator!=(const Registration& other) const;
    bool operator<(const Registration& other) const;
    bool operator>(const Registration& other) const;
    const char* getCarNum() const;
    friend std::ostream& operator<<(std::ostream& os, const Registration& car);
};
std::ostream& operator<<(std::ostream& os, const Registration& car);

