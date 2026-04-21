#include "Employee.h"

size_t Employee::EMPLOYEE_COUNT = 0;

auto Employee::operator==(const Employee& other) const -> bool
{
	return ((*this) <=> other) == std::partial_ordering::equivalent;
}

auto Employee::operator++() -> Employee&
{
	m_salary *= 1.1;
	return *this;
}

auto Employee::operator++(int) -> Employee
{
	auto temp = Employee{ *this };
	++*this;
	return temp;
}

Employee::Employee(const char* name, const char* position, double salary) :
	m_id(++EMPLOYEE_COUNT), m_salary(salary)
{
	auto nameLength = strnlen_s(name, ULONG_MAX); //dbg
	(nameLength) ? strcpy_s(m_name, 128, name) : strcpy_s(m_name, 1, "");
	auto positionLength = strnlen_s(position, ULONG_MAX); //dbg
	(positionLength) ? strcpy_s(m_position, 128, position) : strcpy_s(m_position, 1, "");

	if (salary < 0.0)
		salary = 0.0;
}

Employee::Employee() : Employee("", "", 0.0)
{
}

auto Employee::operator<=>(const Employee& other) const -> std::partial_ordering
{
	return (this->m_salary == other.m_salary) ? (this->m_id <=> other.m_id) : (this->m_salary <=> other.m_salary);
}

auto Employee::getSalary() const -> double
{
	return m_salary;
}

auto Employee::getId() const -> size_t
{
	return m_id;
}

auto Employee::updateSalary(double amount) -> ErrorCode
{
	if (amount < 0.0)
		return ErrorCode::InvalidInput;

	m_salary = amount;
	return ErrorCode::OK;
}

auto Employee::getLastEmployeeId() -> size_t
{
	return EMPLOYEE_COUNT;
}

auto operator<<(std::ostream& os, const Employee& employee) -> std::ostream&
{
	os << "Employee: " << employee.m_id << ", " << employee.m_name << ", " << employee.m_position << ", " << employee.m_salary;
	return os;
}