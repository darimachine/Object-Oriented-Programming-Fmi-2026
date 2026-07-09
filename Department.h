#pragma once
#include "Employee.h"


class Department
{
private:
	static constexpr unsigned DEFAULT_CAP = 15;
	char* name=nullptr;
	Employee* employees=nullptr;
	unsigned countOfEmployees = 0;
	unsigned capacity = DEFAULT_CAP;

	void copyFrom(const Department&);
	void free();
	void moveFrom(Department&&);
	void resize(unsigned);

public:
	Department();
	Department(const char*, unsigned capacity);
	Department(const Department&);
	Department& operator=(const Department&);
	Department(Department&&)noexcept;
	Department& operator=(Department&&)noexcept;
	~Department();

	ErrorCode addEmployee(const Employee&);
	ErrorCode removeEmployee(unsigned);

	friend std::ostream& operator<<(std::ostream&, const Department&);

	const char* getName()const;

	double getAverageSalary()const;
	unsigned getCount() const;

	Employee& operator[](unsigned index);
	const Employee& operator[](unsigned index) const;

	operator bool() const;

	Department& operator()(unsigned);
};

bool operator==(const Department&, const Department&);
std::strong_ordering operator <=>(const Department&, const Department&);

