#define _CRT_SECURE_NO_WARNINGS
#include "Department.h"
#include <compare>
#include "ErrorCode.h"


void Department::free() {
	delete[] name;
	delete[] employees;
}
void Department::copyFrom(const Department& other) {
	name = new char[strlen(other.name) + 1];
	employees = new Employee[other.capacity];
	strcpy(name, other.name);
	capacity = other.capacity;
	countOfEmployees = other.countOfEmployees;
	for (int i = 0; i < countOfEmployees; i++) {
		employees[i] = other.employees[i];
	}
}
void Department::moveFrom(Department&& other) {
	name = other.name;
	employees = other.employees;
	capacity = other.capacity;
	countOfEmployees = other.countOfEmployees;
	other.name = nullptr;
	other.employees = nullptr;
	other.capacity = 0;
	other.countOfEmployees = 0;
}

void Department::resize() {
	Employee* employees2 = new Employee[2 * capacity];
	for (int i = 0; i < countOfEmployees; i++) {
		employees2[i] = employees[i];
	}
	capacity *= 2;
	delete[] employees;
	employees = employees2;
}
int Department::getPossition(unsigned id) {
	int counter = 0;
	for (int i = 0; i < countOfEmployees; i++) {
		counter++;
		if (this->employees[i].getId() == id) return counter;
	}
	return-1;
}
double Department::averageSalary() const {
	if (countOfEmployees == 0) return 0;
	double sum = 0;
	for (int i = 0; i < countOfEmployees; i++) {
		sum += employees[i].getSalary();
	}
	return sum / countOfEmployees;
}
const char* Department::getName() const {
	return name;
}


Department::Department() {
	name = nullptr;
	employees = nullptr;
	countOfEmployees = 0;
	capacity = 0;
}
Department::~Department() {
	free();
}
Department::Department(const Department& other) {
	copyFrom(other);
}
Department& Department::operator=(const Department& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
Department::Department(Department&& other) noexcept {
	moveFrom(std::move(other));
}
Department& Department::operator=(Department&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}
Department::Department(const char* name, unsigned capacity) {
	this->name = new char[strlen(name) + 1];
	this->employees = new Employee[capacity];
	strcpy(this->name, name);
	this->capacity = capacity;
	countOfEmployees = 0;
}
ErrorCode Department::addEmployee(const Employee& e) {
	if (countOfEmployees >= capacity) resize();
	employees[countOfEmployees++] = e;
	return ErrorCode::OK;	
}
ErrorCode Department::removeEmployee(unsigned id) {
	int index = getPossition(id);
	if (index == -1) return ErrorCode::NotFound;
	for (int i = index; i < countOfEmployees - 1; i++) {
		std::swap(employees[i], employees[i + 1]);
	}
	countOfEmployees--;
	return ErrorCode::OK;
}
std::strong_ordering Department::operator<=>(const Department& other) const {
	if (countOfEmployees != other.countOfEmployees)
		return countOfEmployees <=> other.countOfEmployees;
	if (averageSalary() > other.averageSalary()) return std::strong_ordering::greater;
	if (averageSalary() < other.averageSalary()) return std::strong_ordering::less;
	return std::strong_ordering::equal;
}
std::ostream& operator<<(std::ostream& os,const Department& d) {
	os << d.name << " " << d.countOfEmployees << " " << d.capacity << std::endl;
	for (int i = 0; i < d.countOfEmployees; i++) {
		os << d.employees[i];
	}
	return os;
}
const Employee& Department::operator[](const unsigned index)const {
	return employees[index];
}
Employee& Department::operator[](unsigned index){
	return employees[index];
}
Department::operator bool() const {
	if (countOfEmployees > 0) return true;
	return false;
}
Department& Department::operator()(const int p) {
	for (int i = 0; i < countOfEmployees; i++) {
		employees[i].updateSalary(p);
	}
	return *this;
}

