#define _CRT_SECURE_NO_WARNINGS
#include "Employee.h"
#include "ErrorCode.h"



unsigned Employee::id = 0;
Employee::Employee() {
	currentId = id++;
	salary = 0;
}
Employee::Employee(const char* name,const char* possition, double salary) {
	if (strlen(name) <= 128 && strlen(possition) <= 128) {
		strcpy(this->name, name);
		strcpy(this->possition, possition);
		this->salary = salary;
	}
}
double Employee::getSalary() const {
	return salary;
}
ErrorCode Employee::updateSalary(double amount) {
	if (amount >= 0) {
		salary = amount;
		return ErrorCode::OK;
	}
	return ErrorCode::InvalidInput;
}
ErrorCode Employee::updateSalary(int percentage) {
	salary *= (double)(1 + (double)percentage / 100);
	return ErrorCode::OK;
}
unsigned Employee::getLastId() {
	return id - 1;
}
unsigned Employee::getId() const {
	return currentId;
}
std::ostream& operator<<(std::ostream& os, Employee& obj) {
	os << obj.currentId << " " << obj.name << " " << obj.possition << " " << obj.salary << std::endl;
	return os;
}
std::strong_ordering Employee::operator<=>(const Employee& other) const {
	if (salary > other.salary) return std::strong_ordering::greater;
	if (salary < other.salary) return std::strong_ordering::less;

	if (currentId > other.currentId) return std::strong_ordering::greater;
	if (currentId < other.currentId) return std::strong_ordering::less;

	return std::strong_ordering::equal;
}
Employee& Employee::operator++() {
	salary *= 1.1;
	return *this;
}
Employee Employee::operator++(int) {
	Employee temp = *this;
	salary *= 1.1;
	return temp;
}

