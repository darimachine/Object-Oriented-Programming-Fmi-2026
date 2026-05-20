#ifndef TEAMMANAGER_PERSON_H
#define TEAMMANAGER_PERSON_H

#include <memory>
#include<string>

class Person {
    std::string name;
    std::string middleName;
    std::string surname;
    std::string EGN;

public:
    Person(const std::string& name, const std::string&middleName,
        const std::string& surname, const std::string& EGN);
    explicit Person(const std::string& name, const std::string& surname, const std::string& EGN);

    const std::string& getName() const;
    const std::string& getMiddleName() const;
    const std::string& getSurname() const;
    const std::string& getEGN() const;

    virtual std::unique_ptr<Person> clone() const;
    virtual ~Person() = default;
};

bool operator==(const Person& lhs, const Person& rhs);
auto operator<=>(const Person& lhs, const Person& rhs);


#endif //TEAMMANAGER_PERSON_H