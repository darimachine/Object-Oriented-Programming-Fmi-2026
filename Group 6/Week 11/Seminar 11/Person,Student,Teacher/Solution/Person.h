#pragma once
#include <iostream>
#include <vector>
#include <compare>
using namespace std;
class Person
{
	string name;
	string email;
	int age;

public:
	Person(const string& name, const string& email, int age);

	const string& getName() const;
	const string& getEmail() const;

	int getAge() const;

	void setAge(int age);
	void print() const;

	std::strong_ordering operator<=>(const Person& other) const;
	bool operator==(const Person& other) const;
};

