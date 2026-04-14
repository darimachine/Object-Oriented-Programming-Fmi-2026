#include "Company.h"
#include "ErrorCode.h"
#define _CRT_SECURE_NO_WARNINGS


Company& Company::getInstance() {
	static Company instance;
	return instance;
}

ErrorCode Company::addDepartment(const char* name) {
	if (countOfDepartments < 10) {
		departments[countOfDepartments++] = Department(name,(unsigned)10);
		return ErrorCode::OK;
	}
	return ErrorCode::Full;
}
int Company::getDepartmentIndex(const char* name) {
	for (int i = 0; i < countOfDepartments; i++) {
		if (strcmp(name, departments[i].getName()) == 0) return i;
	}
	return -1;
}
Company::operator bool() const {
	for (int i = 0; i < countOfDepartments; i++) {
		if (departments[i])return true;
	}
	return false;
}

ErrorCode Company::removeDepartment(const char* name) {
	unsigned index = getDepartmentIndex(name);
	if (index == -1) return ErrorCode::NotFound;
	if (index == countOfDepartments -1) {
		countOfDepartments--;
		return ErrorCode::OK;
	}
	for (int i = index; i < countOfDepartments-1; i++) {
		std::swap(departments[i], departments[i + 1]);
	}
	countOfDepartments--;
	return ErrorCode::OK;
}
ErrorCode Company::addEmployeeToDepartment(const char* departmentName, const Employee& employee) {
	int index = getDepartmentIndex(departmentName);
	if (index == -1) return ErrorCode::NotFound;
	departments[index].addEmployee(employee);
	return ErrorCode::OK;
}
ErrorCode Company::removeEmployeeFromDepartment(const char* departmentName, unsigned id) {
	int index = getDepartmentIndex(departmentName);
	if (index == -1) return ErrorCode::NotFound;
	departments[index].removeEmployee(id);
	return ErrorCode::OK;
}
std::ostream& operator<<(std::ostream& os,const Company& c) {
	for (int i = 0; i < c.countOfDepartments; i++) {
		os << c.departments[i];
	}
	return os;
}
Department* Company::operator[](const char* name) {
	int index = getDepartmentIndex(name);
	if (index == -1) return nullptr;
	return &departments[index];
}
