#include "Person.h"
#include <cstring>

void Person::setName(const char* name) {
    if (!name) {
        setName("N/A");
        return;
    }
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void Person::setAge(int age) {
    if (age < 0) {
        this->age = 0;
        return;
    }
    if (age > 120) {
        this->age = 120;
        return;
    }
    this->age = age;
}

Person::Person() {
    setName("N/A");
}

Person::Person(const char* name, int age) {
    setName(name);
    setAge(age);
}

Person::~Person() {
    delete[] name;
    name = nullptr;
    age = 0;
}

int Person::getAge() const {
    return age;
}

const char* Person::getName() const {
    return name;
}

void print(const Person& person, std::ostream& os) {
    std::println(os, "Name: {}, Age: {}", person.getName(), person.getAge());
}
