//
// Created by Vanina Laleva on 17.04.26.
//

#ifndef REGISTRATIONCAR_REGISTRATION_H
#define REGISTRATIONCAR_REGISTRATION_H

#include <iosfwd>
#include <iostream>


class Registration {
    static constexpr int MAX_LETTER_SIZE = 2;
    static constexpr int MAX_NUMBER_SIZE = 4;

    char firstLetter[MAX_LETTER_SIZE + 1];
    char numbers[MAX_NUMBER_SIZE + 1];
    char lastLetter[MAX_LETTER_SIZE + 1];
    size_t size;

public:
    Registration() = delete;

    Registration(const char *carPlate);

    //
    const size_t getSize() const;

    char *getCarPlate() const;

    char *getFirstLetter() const;


    //
    static bool isValidRegistration(const char *string);
};

bool isLetter(char symbol);

bool isDigit(char symbol);

//
bool operator==(const Registration &lhs, const Registration &rhs);

std::ostream &operator<<(std::ostream &os, const Registration &reg);

std::strong_ordering operator<=>(const Registration &lhs, const Registration &rhs);


#endif //REGISTRATIONCAR_REGISTRATION_H
