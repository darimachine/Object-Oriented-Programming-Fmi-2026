#pragma once
#include<string>

class Weapon
{
private:
	std::string name;
	
public:
	Weapon() = default;
	Weapon(const std::string& name);

	virtual int roll() const = 0;

	const std::string& getName()const;
	virtual ~Weapon() = default;
};

