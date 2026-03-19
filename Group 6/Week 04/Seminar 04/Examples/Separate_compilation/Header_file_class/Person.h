#pragma once
#include <iostream>

class Person {
public:
    Person();
    Person(const char* name, int age);
    ~Person();

    const char* getName() const;
    int getAge() const;

    void setName(const char* name);
    void setAge(int age);

private:
    char* name = nullptr;
    int age = 0;
};

// print functions such as this one, are better outside the class,
// in order to comply with the Single Responsibility principle from
// the SOLID principles
// (it is not a Person's responsibility to print themselves on the console)
void print(const Person& person, std::ostream& os = std::cout);
