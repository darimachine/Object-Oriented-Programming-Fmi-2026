//
// Created by Boris Bozhilov on 4/18/2026.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_FMI_2026_REGISTRATION_H
#define OBJECT_ORIENTED_PROGRAMMING_FMI_2026_REGISTRATION_H
#include <compare>
#include <iosfwd>


class Registration {

private:

    char* registration = nullptr;

    // utility functions
    static bool checkRegistrationValidity(const char* registration);

public:

    // NOTE these constant are used to the VehicleList class make the code more universal if registration way is changed
    static constexpr unsigned int MAX_LENGTH_LOCATION_CODE = 2;
    static constexpr unsigned int LENGTH_DIGITS_PART = 4;
    static constexpr unsigned int LENGTH_CHARACTERS_PART = 2;

    // the length of the registration when 2 characters are used for the city
    static constexpr unsigned int MAX_LENGTH_OF_REGISTRATION = MAX_LENGTH_LOCATION_CODE +
                                                                LENGTH_DIGITS_PART +
                                                                LENGTH_CHARACTERS_PART;


    // the length of the registration when 1 character is used for the city
    static constexpr unsigned int MIN_LENGTH_OF_REGISTRATION = MAX_LENGTH_LOCATION_CODE - 1 +
                                                                LENGTH_DIGITS_PART +
                                                                LENGTH_CHARACTERS_PART;

    // utility functions
    bool isValid() const;

    // rule of 5
    Registration() = delete;

    explicit Registration(const char* registration);

    Registration(const Registration& other);
    Registration& operator=(const Registration& other);

    Registration(Registration&& other) noexcept;
    Registration& operator=(Registration&& other) noexcept;

    ~Registration();

    // methods
    char* getRegistrationAsString() const;

    // operators
    bool operator==(const Registration& other) const;
    std::strong_ordering operator<=>(const Registration& other) const;
    friend std::ostream& operator<<(std::ostream& output, const Registration& registration);
};



#endif //OBJECT_ORIENTED_PROGRAMMING_FMI_2026_REGISTRATION_H
