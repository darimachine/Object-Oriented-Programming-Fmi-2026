#pragma once
#include <iostream>
#include <compare>

enum class ErrorCode {
	OK,
	NotFound,
	Duplicate,
	InvalidInput,
	Full
};

class Employee {
	unsigned id;
	char name[128]{};
	char position[128]{};
	double salary;

public:
	static int nextID;

	int generateID();

	//default constructor
	Employee();

	//constructor with parameters
	Employee(const char* _name, const char* _position, double _salary);

	double getSalary() const;

	ErrorCode updateSalary(double amount);

	static int getLastId();

	//getter
	unsigned getId();

	friend std::ostream& operator<<(std::ostream& os, const Employee& p);

	std::partial_ordering operator<=> (const Employee& other) const;

	bool operator==(const Employee& other) const;

	//prefix ++
	Employee& operator++();
	//postfix ++
	Employee operator++(int dummy);
};

class Department {
	char* name;
	Employee* employees;
	unsigned countOfEmployees;
	unsigned capacity;

	void resize();
	void free();
	void copyFrom(const Department& other);
	void moveFrom(Department&& other);

public:
	//getter
	const char* getName() const;

	//default constructor
	Department();

	//constructor with parameters
	Department(const char* _name, unsigned _capacity);

	// Rule of 5
	Department(const Department& other);
	Department& operator=(const Department& other);
	Department(Department&& other) noexcept;
	Department& operator=(Department&& other) noexcept;
	~Department();

	ErrorCode addEmployee(const Employee& e);
	ErrorCode removeEmployee(unsigned id);
	double avgSal()const;

	//operators
	Employee& operator[](int index);
	const Employee& operator[](int index) const;

	Department& operator()(double percent);

	explicit operator bool() const; // for bool context

	std::partial_ordering operator<=>(const Department& other) const;

	friend std::ostream& operator<<(std::ostream& os, const Department& d);
};


class Company {
	Department departments[10];
	unsigned countOfDepartments;
	Company();

public:

	Company(const Company& other) = delete;
	Company& operator= (const Company& other) = delete;
	Company(const Company&& other) = delete;

	static Company& getInstance();

	ErrorCode addDepartment(const char* name);
	ErrorCode removeDepartment(const char* name);
	ErrorCode addEmployeeToDepartment(const char* departmentName, const Employee& employee);
	ErrorCode removeEmployeeFromDepartment(const char* departmentName, unsigned id);

	friend std::ostream& operator<< (std::ostream& os, const Company& c);
	explicit operator bool() const;// for bool context
	Department* operator[](const char* depName);
	const Department* operator[](const char* depName) const;
};