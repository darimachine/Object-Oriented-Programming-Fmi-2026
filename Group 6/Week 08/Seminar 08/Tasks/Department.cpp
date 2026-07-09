#include "Department.h"
#include "Employee.h"
#include <iostream>

void Department::moveFrom(Department &&other) noexcept{
    name_=other.name_;
    employees_=other.employees_;
    countOfEmployees_=other.countOfEmployees_;
    capacity_=other.capacity_;

    other.name_=nullptr;
    other.employees_=nullptr;
    other.countOfEmployees_=0;
    other.capacity_=0;
}

void Department::resize() {
    unsigned newCapacity;

    if (capacity_ == 0) {
        newCapacity = 1;
    } else {
        newCapacity = capacity_ * 2;
    }

    auto newEmployees = new Employee[newCapacity];

    for (unsigned i=0;i<countOfEmployees_;i++) {
        newEmployees[i]=employees_[i];
    }
    delete[] employees_;
    employees_ = newEmployees;
    capacity_ = newCapacity;
}

void Department::free() {
    delete[] name_;
    delete[] employees_;
    name_=nullptr;
    employees_=nullptr;
    countOfEmployees_=0;
    capacity_=0;
}

Department::Department():name_(nullptr), employees_(nullptr), countOfEmployees_(0), capacity_(0) {};

Department::~Department() {
  free();
}

Department::Department(Department &&other) noexcept {
    moveFrom(std::move(other));
}

Department & Department::operator=(Department &&other) noexcept {
    if (this == &other) {
        return *this;
    }
    free();
    moveFrom(std::move(other));
    return *this;
}

Department::Department(const char* name,unsigned capacity): countOfEmployees_(0),capacity_(capacity) {

    if (capacity_ == 0) {
        capacity_ = 1;
    }

    name_ = new char[strlen(name) + 1];
    strcpy(name_, name);

    employees_ = new Employee[capacity];

}
ErrorCode Department:: addEmployee(const Employee &employee){
    for (int i = 0; i < countOfEmployees_; i++) {
        if (employees_[i].getId() == employee.getId()) {
            return ErrorCode::Duplicate;
        }
    }

    if (countOfEmployees_ >= capacity_) {
        resize();
    }

employees_[countOfEmployees_] = employee;
    countOfEmployees_++;
    return ErrorCode::OK;
}
ErrorCode Department::removeEmployee(unsigned id) {
int personNum=-1;
    if (id<=0) {
        return ErrorCode::InvalidInput;
    }

    for (int i=0; i<countOfEmployees_; i++) {
        if (employees_[i].getId() == id) {
            personNum = i;
        }
    }

    if (personNum == -1) {
        return ErrorCode::NotFound;
    }

    for (int i = personNum; i < countOfEmployees_ - 1; i++){
        employees_[i] = employees_[i+1];
    }

countOfEmployees_--;
    return ErrorCode::OK;
}

unsigned Department::getCapacity() const {
    return capacity_;
}


const char * Department::getName() const {
    return name_;
}

unsigned Department::getEmployeesCount() const {return countOfEmployees_;}


bool Department::isEmpty() const {
    if (countOfEmployees_<=0) {return true;}
    return false;
}

double Department::averageSalary()const {
    if (countOfEmployees_<=0) {return 0;}
double salary=0;
    for (int i = 0; i < countOfEmployees_; i++) {
        salary += employees_[i].getSalary();
    }

    return salary/countOfEmployees_;
}

bool Department::operator<(const Department &depart)const {
    if (countOfEmployees_==depart.countOfEmployees_) {
        return averageSalary()<depart.averageSalary();
    }
    return countOfEmployees_<depart.countOfEmployees_;

}

bool Department::operator>(const Department &depart) const {
    return depart<(*this);
}

Employee & Department::operator[](const int index) {
    return employees_[index];
}

const Employee & Department::operator[](const int index) const {
    return employees_[index];
}

Department::operator bool() const {
    return countOfEmployees_ > 0;
}

Department& Department::operator()(const double percent) {

    for (int i = 0; i < countOfEmployees_; i++) {
        employees_[i].updateSalary(percent);
    }
    return *this;

}

std::ostream & operator<<(std::ostream &os, const Department &department) {
    os << department.getName() << std::endl;
    for (int i = 0; i < department.countOfEmployees_; i++) {
        os << department.employees_[i];
    }
    return os;
}
