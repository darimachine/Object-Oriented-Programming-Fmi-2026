#include "01.h"


unsigned Employee::nextId = 0;

Employee::Employee() : id(++nextId), salary(0.0) {
    strcpy(this->name, "Unknown");
    strcpy(this->position, "None");
}

Employee::Employee(const char* name, const char* position, double salary) : id(++nextId) {
    strncpy(this->name, name, 127);
    this->name[127] = '\0';
    strncpy(this->position, position, 127);
    this->position[127] = '\0';
    this->salary = (salary >= 0) ? salary : 0;
}

double Employee::getSalary() const {
    return salary;
}

ErrorCode Employee::updateSalary(double amount) {
    if (amount < 0) {
        return ErrorCode::InvalidInput;
    }
    salary = amount;
    return ErrorCode::OK;
}

unsigned Employee::getId() const {
    return id;
}

unsigned Employee::getLastInitializedId() {
    return nextId;
}

void Employee::setSalary(double salary) {
    this->salary = salary;
}

std::ostream& operator<<(std::ostream& os, const Employee& e) {
    os << "Name: " << e.name << std::endl;
    os << "Position: " << e.position << std::endl;
    os << "Salary: " << e.salary << std::endl;
    os << "ID: " << e.id << std::endl;
    return os;
}

std::strong_ordering Employee::operator<=>(const Employee& other) const {
    if (salary < other.salary) {
        return std::strong_ordering::less;
    }
    if (salary > other.salary) {
        return std::strong_ordering::greater;
    }
    return id <=> other.id;
}

bool Employee::operator==(const Employee& other) {
    if (this->salary == other.salary) {
        if (this->id == other.id) {
            return true;
        }
    }
    return false;
}

Employee& Employee::operator++() {
    this->salary *= 1.10;
    return *this;
}

Employee Employee::operator++(int) {
    Employee temp = *this;
    this->salary *= 1.10;
    return temp;
}

void Department::copyFrom(const Department& other) {
    if (other.name) {
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
    }
    else {
        this->name = nullptr;
    }

    this->capacity = other.capacity;
    this->countOfEmployees = other.countOfEmployees;

    if (other.employees) {
        this->employees = new Employee[this->capacity];
        for (unsigned i = 0; i < countOfEmployees; i++) {
            this->employees[i] = other.employees[i];
        }
    }
    else {
        this->employees = nullptr;
    }
}

void Department::free() {
    delete[] name;
    delete[] employees;
    name = nullptr;
    employees = nullptr;
    countOfEmployees = 0;
    capacity = 0;
}

Department::Department() : countOfEmployees(0), capacity(0) {
    name = nullptr;
    employees = nullptr;
}

Department::Department(const char* name, int capacity) : countOfEmployees(0) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->capacity = capacity;
    employees = new Employee[capacity];
}

Department::Department(const Department& other) {
    copyFrom(other);
}

Department::~Department() {
    free();
}

Department::Department(Department&& other) noexcept {
    name = other.name;
    employees = other.employees;
    countOfEmployees = other.countOfEmployees;
    capacity = other.capacity;
    other.name = nullptr;
    other.employees = nullptr;
    other.countOfEmployees = 0;
    other.capacity = 0;
}

Department& Department::operator=(const Department& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

Department& Department::operator=(Department&& other) noexcept {
    if (this != &other) {
        free();
        name = other.name;
        employees = other.employees;
        countOfEmployees = other.countOfEmployees;
        capacity = other.capacity;
        other.name = nullptr;
        other.employees = nullptr;
        other.countOfEmployees = 0;
        other.capacity = 0;
    }
    return *this;
}

void Department::resize(unsigned newCapacity) {
    if (newCapacity == 0) newCapacity = 4;
    Employee* temp = new Employee[newCapacity];
    for (unsigned i = 0; i < countOfEmployees; i++) {
        temp[i] = employees[i];
    }
    delete[] employees;
    employees = temp;
    capacity = newCapacity;
}

ErrorCode Department::addEmployee(const Employee& other) {
    if (countOfEmployees == capacity) {
        resize(2 * capacity);
    }
    employees[countOfEmployees++] = other;
    return ErrorCode::OK;
}

void Department::remove(int index) {
    for (int i = index; i < (int)countOfEmployees - 1; i++) {
        employees[i] = std::move(employees[i + 1]);
    }
    countOfEmployees--;
}

ErrorCode Department::removeEmployee(unsigned id) {
    for (int i = 0; i < (int)countOfEmployees; i++) {
        if (employees[i].getId() == id) {
            remove(i);
            return ErrorCode::OK;
        }
    }
    return ErrorCode::NotFound;
}

std::ostream& operator<<(std::ostream& os, const Department& d) {
    os << "Name of department: " << (d.name ? d.name : "None") << std::endl;
    for (int i = 0; i < (int)d.countOfEmployees; i++) {
        os << "Employee " << i + 1 << ": " << std::endl;
        os << d.employees[i];
    }
    os << "Sum of workers: " << d.countOfEmployees << std::endl;
    os << "Capacity: " << d.capacity << std::endl;
    return os;
}

double Department::salary(const Department& d) const {
    if (countOfEmployees == 0) return 0.0;
    double salary = 0.0;
    for (int i = 0; i < (int)d.countOfEmployees; i++) {
        salary += employees[i].getSalary();
    }
    return salary / countOfEmployees;
}

bool Department::operator==(const Department& other) {
    return countOfEmployees == other.countOfEmployees && salary(*this) == salary(other);
}

std::strong_ordering Department::operator<=>(const Department& other) const {
    if (countOfEmployees != other.countOfEmployees) {
        return countOfEmployees <=> other.countOfEmployees;
    }
    if (salary(*this) < salary(other)) {
        return std::strong_ordering::less;
    }
    if (salary(*this) > salary(other)) {
        return std::strong_ordering::greater;
    }
    return std::strong_ordering::equal;
}

Employee& Department::operator[](int index) {
    return employees[index];
}

const Employee& Department::operator[](const int index) const {
    return employees[index];
}

Department::operator bool() const {
    return countOfEmployees > 0;
}

Department& Department::operator()(double precentage) {
    if (precentage < 0) {
        return *this;
    }
    for (int i = 0; i < (int)countOfEmployees; i++) {
        double newSalary = (precentage / 100.0) * employees[i].getSalary() + employees[i].getSalary();
        employees[i].setSalary(newSalary);
    }
    return *this;
}

void Department::setName(const char* name) {
    if (name) {
        delete[] this->name;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
}

char* Department::getName() const {
    return name;
}

Company::Company() {
    countOfDepartments = 0;
}

Company& Company::getInstance() {
    static Company instance;
    return instance;
}

ErrorCode Company::addDepartment(const char* name) {
    if (countOfDepartments >= 10) {
        return ErrorCode::Full;
    }
    if (!name) {
        return ErrorCode::InvalidInput;
    }
    departments[countOfDepartments++].setName(name);
    return ErrorCode::OK;
}

void Company::remove(int index) {
    for (int i = index; i < (int)countOfDepartments - 1; i++) {
        departments[i] = std::move(departments[i + 1]);
    }
    departments[countOfDepartments - 1] = Department();
    countOfDepartments--;
}

ErrorCode Company::removeDepartment(const char* name) {
    if (!name) {
        return ErrorCode::InvalidInput;
    }
    for (int i = 0; i < (int)countOfDepartments; i++) {
        if (strcmp(departments[i].getName(), name) == 0) {
            remove(i);
            return ErrorCode::OK;
        }
    }
    return ErrorCode::NotFound;
}

ErrorCode Company::addEmployeeToDepartment(const char* departmentName, const Employee& employee) {
    if (!departmentName) {
        return ErrorCode::InvalidInput;
    }
    for (int i = 0; i < (int)countOfDepartments; i++) {
        if (strcmp(departments[i].getName(), departmentName) == 0) {
            return departments[i].addEmployee(employee);
        }
    }
    return ErrorCode::NotFound;
}

ErrorCode Company::removeEmployeeFromDepartment(const char* departmentName, unsigned id) {
    if (!departmentName) {
        return ErrorCode::InvalidInput;
    }
    for (int i = 0; i < (int)countOfDepartments; i++) {
        if (strcmp(departments[i].getName(), departmentName) == 0) {
            return departments[i].removeEmployee(id);
        }
    }
    return ErrorCode::NotFound;
}

std::ostream& operator<<(std::ostream& os, const Company& c) {
    for (int i = 0; i < (int)c.countOfDepartments; i++) {
        os << "Department " << i + 1 << ": " << std::endl;
        os << c.departments[i];
    }
    os << "Sum of departments: " << c.countOfDepartments << std::endl;
    return os;
}

Company::operator bool() const {
    if (countOfDepartments == 0) {
        return false;
    }
    for (int i = 0; i < (int)countOfDepartments; i++) {
        if (departments[i]) {
            return true;
        }
    }
    return false;
}

Department* Company::operator[](const char* name) {
    for (int i = 0; i < (int)countOfDepartments; i++) {
        if (strcmp(departments[i].getName(), name) == 0) {
            return &departments[i];
        }
    }
    return nullptr;
}