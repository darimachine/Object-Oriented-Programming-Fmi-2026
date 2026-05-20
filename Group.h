#pragma once
#include"Person.h"
#include<vector>
#include<memory>

class Group
{
private:
	std::vector<std::unique_ptr<Person>> people;

public:
	Group() = default;
	Group(const Group& other);

	const Person& operator[](const std::string& EGN)const;
	Person& operator[](const std::string& EGN);

	Group& operator+=(const Person& other);
	Group operator+(const Person& other);
	Group& operator-=(const Person& other);
	Group operator-(const Person& other);

	size_t operator()()const;
	bool operator()(const Person& person)const;
};



