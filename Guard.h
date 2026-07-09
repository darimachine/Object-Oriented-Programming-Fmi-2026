#pragma once
#include<string>
#include<fstream>

class Guard
{
private:
	static unsigned nextId;
	std::string name;
	unsigned employeeId;
	unsigned experience;

public:
	Guard() = default;
	Guard(const std::string& name,unsigned experience);

	unsigned getEmployeeId()const;
	const std::string& getName()const;

	friend std::ostream& operator<<(std::ostream& os, const Guard& g);
};

