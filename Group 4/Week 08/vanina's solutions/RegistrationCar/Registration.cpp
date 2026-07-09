//
// Created by Vanina Laleva on 17.04.26.
//

#include "Registration.h"

#include <cstring>
#include <stdexcept>

Registration::Registration(const char *carPlate) {
    if (!isValidRegistration(carPlate)) {
        throw std::invalid_argument("Invalid car plateform");
    }

    int index = 0;
    while (isLetter(*carPlate)) {
        firstLetter[index] = *carPlate;
        carPlate++;
        index++;
    }
    firstLetter[index] = '\0';

    index = 0;
    while (isDigit(*carPlate)) {
        numbers[index] = *carPlate;
        carPlate++;
        index++;
    }
    numbers[index] = '\0';

    index = 0;
    while (isLetter(*carPlate)) {
        lastLetter[index] = *carPlate;
        carPlate++;
        index++;
    }
    lastLetter[index] = '\0';

    size = strlen(firstLetter) + strlen(numbers) + strlen(lastLetter);
}

const size_t Registration::getSize() const {
    return size;
}

bool Registration::isValidRegistration(const char *string) {
    int index = 0;
    if (!isLetter(string[index++])) {
        return false;
    }
    if (!isLetter(string[index]) && !isDigit(string[index])) {
        return false;
    }
    if (isLetter(string[index])) {
        index++;
    }

    for (int i = index; i < MAX_NUMBER_SIZE; i++) {
        if (!isDigit(string[i + index])) {
            return false;
        }
    }
    index += MAX_NUMBER_SIZE;

    if (!isLetter(string[index]) || !isLetter(string[index + 1])) {
        return false;
    }
    return true;
}

char *Registration::getCarPlate() const {
    char *carPlate = new char[size + 1];
    strcpy(carPlate, firstLetter);
    strcat(carPlate, numbers);
    strcat(carPlate, lastLetter);

    return carPlate;
}

char *Registration::getFirstLetter() const {
    char *firstLetterNew = new char[size + 1];
    strcpy(firstLetterNew, firstLetter);
    return firstLetterNew;
}

bool isLetter(char symbol) {
    return (symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z');
}

bool isDigit(char symbol) {
    return symbol >= '0' && symbol <= '9';
}

std::ostream &operator<<(std::ostream &os, const Registration &reg) {
    os << reg.getCarPlate();
    return os;
}

bool operator==(const Registration &lhs, const Registration &rhs) {
    char *plate1 = lhs.getCarPlate();
    char *plate2 = rhs.getCarPlate();
    bool result = (strcmp(plate1, plate2) == 0);
    delete[] plate1;
    delete[] plate2;
    return result;
    // return strcmp(lhs.getCarPlate(), rhs.getCarPlate()) == 0;
}

std::strong_ordering operator<=>(const Registration &lhs, const Registration &rhs) {
    // return lhs.getCarPlate() <=> rhs.getCarPlate();
    if (strcmp(lhs.getCarPlate(), rhs.getCarPlate()) < 0) {
        return std::strong_ordering::less;
    }
    if (strcmp(lhs.getCarPlate(), rhs.getCarPlate()) > 0) {
        return std::strong_ordering::greater;
    }
    return std::strong_ordering::equal;
}
