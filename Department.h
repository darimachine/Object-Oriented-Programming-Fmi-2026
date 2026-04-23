#pragma once
#include"Employee.h"

class Department
{
private:
	static constexpr unsigned DEFAULT_CAPACITY = 16;
	char* name = nullptr;
	Employee* employees = nullptr;
	unsigned countOfEmployees = 0;
	unsigned capacity = 16;

	void copyFrom(const Department& other);
	void moveFrom(Department&& other);
	void free();
	void resize(size_t newCap);

public:
	Department();
	Department(const char* name, unsigned capacity);

	Department(const Department& other);
	Department& operator=(const Department& other);
	Department(Department&& other)noexcept;
	Department& operator=(Department&& other)noexcept;
	~Department();
	
	void setName(const char* name);
	const char* getName()const;

	ErrorCode addEmployee(const Employee& employee);
	ErrorCode removeEmployee(unsigned id);

	double getAverageSalary()const;
	unsigned getCount()const;

	Employee& operator[](size_t index);
	const Employee& operator[](size_t index)const;

	explicit operator bool()const;
	Department& operator()(double percent);

	friend std::ostream& operator<<(std::ostream& os, const Department& department);
};

std::strong_ordering operator<=>(const Department& lhs, const Department& rhs);
bool operator==(const Department& lhs, const Department& rhs);
