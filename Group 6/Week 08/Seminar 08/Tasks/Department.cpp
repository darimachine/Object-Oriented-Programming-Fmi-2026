#include "Department.h"
#include <print>
#include <cstring>

static constexpr double MAX_DIFF = 0.0000001;

static bool isSalaryEqual(const double x, const double y) {
    return std::abs(x - y) < MAX_DIFF;
}

void Department::free() {
    delete[] name;
    delete[] employees;
    name = nullptr;
    employees = nullptr;
}

void Department::copyFrom(const Department &other) {
    int len = strlen(other.name);
    name = new char[len + 1];
    strcpy(name, other.name);
    capacity = other.capacity;
    countOfEmployees = other.countOfEmployees;
    employees = new Employee[capacity];
    for (int i = 0; i < countOfEmployees; i++) {
        employees[i] = other.employees[i];
    }
}

void Department::resize() {
    int newCap = capacity * 2;
    Employee* newEmp = new Employee[newCap];
    for (int i = 0; i < countOfEmployees; i++) {
        newEmp[i] = employees[i];
    }
    delete[] employees;
    employees = newEmp;
    capacity = newCap;
}

Department::Department() : countOfEmployees(0), capacity(10) {
    name = new char[1];
    name[0] = '\0';
    employees = new Employee[capacity];
}

Department::Department(const char *name, unsigned initialCount) : countOfEmployees(0), capacity(initialCount) {
    if (!name) {
        this->name = new char[1];
        this->name[0] = '\0';
    }
    else {
        int len = strlen(name);
        this->name = new char[len + 1];
        strcpy(this->name, name);
    }
    employees = new Employee[capacity];
}

ErrorCode Department::addEmployee(const Employee &emp) {
    for (int i = 0; i < countOfEmployees; i++) {
        if (employees[i].getId() == emp.getId()) {
            return ErrorCode::Duplicate;
        }
    }

    if (countOfEmployees == capacity) {
        resize();
    }

    employees[countOfEmployees++] = emp;
    return ErrorCode::OK;
}

ErrorCode Department::removeEmployee(unsigned id) {
    for (int i = 0; i < countOfEmployees; i++) {
        if (employees[i].getId() == id) {
            for (int j = i; j + 1 < countOfEmployees; j++) {
                employees[j] = employees[j + 1];
            }
            --countOfEmployees;
            return ErrorCode::OK;
        }
    }
    return ErrorCode::NotFound;
}

Department::Department(const Department &other) {
    copyFrom(other);
}

Department & Department::operator=(const Department &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

Department::~Department() {
    free();
}

unsigned Department::getCount() const {
    return countOfEmployees;
}

unsigned Department::salaryAverage() const {
    if (countOfEmployees == 0) {
        return 0;
    }
    double sum = 0;
    for (int i = 0; i < countOfEmployees; i++) {
        sum += employees[i].getSalary();
    }
    return sum / countOfEmployees;
}

const char * Department::getName() const {
    return name;
}

std::strong_ordering Department::operator<=>(const Department& other) const {
    if (auto cmp = countOfEmployees <=> other.countOfEmployees; cmp != 0) {
        return cmp;
    }
    double x = salaryAverage();
    double y = other.salaryAverage();

    if (isSalaryEqual(x, y)) {
        return std::strong_ordering::equal;
    }
    return x < y ? std::strong_ordering::less : std::strong_ordering::greater;
}

Employee & Department::operator[](unsigned index) {
    if (index >= countOfEmployees) {
        std::print("Index out of bounds");
    }
    return employees[index];
}

const Employee & Department::operator[](unsigned index) const {
    if (index >= countOfEmployees) {
        std::print("Index out of bounds");
    }
    return employees[index];
}

Department::operator bool() const {
    return countOfEmployees > 0;
}

/*bool Department::isDepActive() const {
    return countOfEmployees == 0;
}*/

Department & Department::operator()(double percent) {
    for (int i = 0; i < countOfEmployees; i++) {
        double newSalary = employees[i].getSalary() * (1 + percent / 100);
        employees[i].updateSalary(newSalary);
    }
    return *this;
}

std::ostream & operator<<(std::ostream &os, const Department &dep) {
    os << "Department: " << dep.name << '\n'
       << "Employess: " << dep.countOfEmployees << '\n';
    return os;
}
