#pragma once
#include"Utils.h"
#include <string>

class Person
{
private:
	static constexpr size_t MAX_LEN_STRING = 30;
	static constexpr size_t EGN_LEN = 10;
	std::string firstName;
	std::string secondName;
	std::string thirdName;
	std::string EGN;

public:
	Person() = delete;
	Person(const std::string& firstName, const std::string& secondName, const std::string& thirdName, const std::string& EGN);
	Person(const std::string& firstName, const std::string& thirdName, const std::string& EGN);

	const std::string& getFirstName() const;
	const std::string& getSecondName() const;
	const std::string& getThirdName() const;
	const std::string& getEGN() const;
};

std::strong_ordering operator<=>(const Person& lhs, const Person& rhs);
bool operator==(const Person& lhs, const Person& rhs);