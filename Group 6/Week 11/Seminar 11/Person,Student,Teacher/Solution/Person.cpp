#include "Person.h"
int Person::getAge() const {
	return age;
}

void Person::setAge(int age)
{
	if (age <= 0 || age >= 120) return;
	this->age = age;
}
Person::Person(const string& name, const string& email, int age): name(name),email(email),age(age)
{
}

void Person::print() const
{
	cout << "Име: " << name << "\n"
		<< "Имейл: " << email << "\n"
		<< "Възраст: " << age << "\n";
}
bool Person::operator==(const Person& other) const
{
	return email==other.email;
}
std::strong_ordering Person::operator<=>(const Person& other) const
{
	return age<=>other.age;
}
const string& Person::getName()  const { return name; }
const string& Person::getEmail() const { return email; }