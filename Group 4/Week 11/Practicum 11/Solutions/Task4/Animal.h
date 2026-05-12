#pragma once
#include <string>
class Animal
{
	std::string name;
	std::string type;
	int age;

public:
	Animal(std::string name, std::string type, int age);

	const std::string& getName() const;
	const std::string& getType() const;
	int getAge() const;
	
	void setName(std::string name);
	void setType(std::string type);
	void setAge(int age);
};

