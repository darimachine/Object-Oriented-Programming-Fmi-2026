#include "Vehicle.h"
#include <cstring>


void Vehicle::copyFrom(const Vehicle &other) {
    size_t size=strlen(other.description);
    description= new char[size + 1];
    for (int i=0;i<size;i++) {
        description[i] = other.description[i];
    }
    description[size] = '\0';
    year = other.year;
    power = other.power;
}

void Vehicle::free() {
    delete[] description;
    year = 0;
    power = 0;
}

Vehicle::Vehicle(const Registration& reg, const char* description_, unsigned long year_, int power_)
    : registration_(reg), year(year_), power(power_) {
    size_t descriptionSize = strlen(description_);
    description = new char[descriptionSize + 1];

    for (size_t i = 0; i < descriptionSize; i++) {
        description[i] = description_[i];
    }

    description[descriptionSize] = '\0';
}

Vehicle::~Vehicle() {
    delete[] description;
    description = nullptr;
    year =0;
    power =0;
}

Vehicle::Vehicle(const Vehicle& other):registration_(other.registration_) {
    copyFrom(other);
}

Vehicle & Vehicle::operator=(const Vehicle &other){
    if (this == &other) {return *this;}
    free();
    copyFrom(other);
    registration_=other.registration_;
    return *this;
}

bool Vehicle::operator<(const Vehicle &other) const {
    if (year==other.year) {
        return power<other.power;
    }
    return year < other.year;
}

bool Vehicle::operator>(const Vehicle &other) const {
    return other < *this;
}

const Registration& Vehicle::getRegistration() const {
    return registration_;
}


std::ostream & operator<<(std::ostream &os, const Vehicle &car) {
    os << car.registration_<<" ";
    os << car.description<<" ";
    os << car.year<<" ";
    os << car.power<<" ";

    return os;
}
// #include "Vehicle.h"
// #include <cstring>
//
// void Vehicle::copyFrom(const Vehicle& other) {
//     registration_ = other.registration_;
//
//     size_t size = strlen(other.description);
//     description = new char[size + 1];
//     for (size_t i = 0; i < size; i++) {
//         description[i] = other.description[i];
//     }
//     description[size] = '\0';
//
//     year = other.year;
//     power = other.power;
// }
//
// void Vehicle::free() {
//     delete[] description;
//     description = nullptr;
//     year = 0;
//     power = 0;
// }
//
// Vehicle::Vehicle(const Registration& reg, const char* description_, unsigned long year_, int power_)
//     : registration_(reg), year(year_), power(power_) {
//     size_t descriptionSize = strlen(description_);
//     description = new char[descriptionSize + 1];
//
//     for (size_t i = 0; i < descriptionSize; i++) {
//         description[i] = description_[i];
//     }
//
//     description[descriptionSize] = '\0';
// }
//
// Vehicle::~Vehicle() {
//     free();
// }
//
// Vehicle::Vehicle(const Vehicle& other)
//     : registration_(other.registration_), year(other.year), power(other.power) {
//     size_t size = strlen(other.description);
//     description = new char[size + 1];
//     for (size_t i = 0; i < size; i++) {
//         description[i] = other.description[i];
//     }
//     description[size] = '\0';
// }
//
// Vehicle& Vehicle::operator=(const Vehicle& other) {
//     if (this != &other) {
//         free();
//         copyFrom(other);
//     }
//     return *this;
// }
//
// bool Vehicle::operator<(const Vehicle& other) const {
//     if (year == other.year) {
//         return power < other.power;
//     }
//     return year < other.year;
// }
//
// bool Vehicle::operator>(const Vehicle& other) const {
//     return other < *this;
// }
//
// const Registration& Vehicle::getRegistration() const {
//     return registration_;
// }
//
// std::ostream& operator<<(std::ostream& os, const Vehicle& car) {
//     os << car.registration_ << " ";
//     os << car.description << " ";
//     os << car.year << " ";
//     os << car.power << " ";
//     return os;
//