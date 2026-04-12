#include <iostream>
#include <cstring>
#pragma warning(disable: 4996)

// Task from theoretical exam in previous years for topic #4

// Implement a class Person with the following properties:
// - name: char[20] - the name of the person, must start with a capital letter and contain only small letters
// - age: int - the age of the person, must be between 5 and 90
// Implement the following methods:
// - default constructor that sets the name to "Unknown" and the age to 5
// - constructor with parameters for name and age
// - getters and setters with appropriate validation for name and age


namespace ValidationFunctions {
    bool isSmallLetter(char ch) {
        return ch >= 'a' && ch <= 'z';
    }

    bool isCapitalLetter(char ch) {
        return ch >= 'A' && ch <= 'Z';
    }

    bool containsOnlySmallLetters(const char* str) {
        size_t length = strlen(str);
        for (size_t i = 0; i < length; i++) {
            if (!isSmallLetter(str[i])) {
                return false;
            }
        }
        return true;
    }
}

constexpr int MAX_NAME_LENGTH = 20;
constexpr int MIN_NAME_LENGTH = 2;
constexpr int MIN_AGE = 5;
constexpr int MAX_AGE = 90;

class Person {
private:
    char name[MAX_NAME_LENGTH] = "Unknown";
    int age = MIN_AGE;
    
    bool isValidName(const char* name) const {
        if (name == nullptr) {
            return false;
        }

        size_t nameLength = strlen(name);
        if (nameLength <= MIN_NAME_LENGTH || nameLength >= MAX_NAME_LENGTH) {
            return false;
        }

        if (!ValidationFunctions::isCapitalLetter(name[0])) {
            return false;
        }

        return ValidationFunctions::containsOnlySmallLetters(name + 1);
    }

    bool isValidAge(int age) {
        return age >= MIN_AGE && age <= MAX_AGE;
    }

public:
    Person() = default;

    Person(const char* name, int age) {
        setName(name);
        setAge(age);
    }

    const char* getName() const {
        return name;
    }

    void setName(const char* name) {
        if (!isValidName(name)) {
            strcpy(this->name, "Unknown");
            return;
        }
        strcpy(this->name, name);
    }

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        if (!isValidAge(age)) {
            this->age = MIN_AGE;
            return;
        }
        this->age = age;
    }

    // no need to write a custom copy constructor, destructor, 
    // or assignment operator= because there is no dynamic memory allocation,
    // more on that topic next week :)
};
