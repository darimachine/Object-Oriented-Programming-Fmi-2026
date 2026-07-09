#include <iostream>
#include "Employee.h"

unsigned int Employee::idCounter_ = 0;

void Employee::freeEmployee() {
    id_=0;
    salary_=0;
    name_[0]='\0';
    position_[0]='\0';
}

void Employee::copyEmployee(const Employee &employee) {
    strncpy(name_, employee.name_,MAX_SIZE_NAME);
    name_[MAX_SIZE_NAME] = '\0';
    strncpy(position_, employee.position_, MAX_SIZE_NAME);
    position_[MAX_SIZE_NAME] = '\0';
    salary_ = employee.salary_;
    id_ = employee.id_;
}

Employee::Employee(): id_(++idCounter_), salary_(0) {
    name_[0]='\0';
    position_[0]='\0';
};

Employee::Employee(const char* name, const char* position, double salary): id_(++idCounter_), salary_(salary) {
    strncpy(name_, name,MAX_SIZE_NAME);
    name_[MAX_SIZE_NAME] = '\0';
    strncpy(position_, position,MAX_SIZE_NAME);
    position_[MAX_SIZE_NAME] = '\0';
}

const char * Employee::getName() const {return name_;}

const char * Employee::getPosition() const {return position_;}

unsigned Employee::getId() const {return id_;}

 unsigned Employee::returnLastId() {
    return idCounter_;
}

Employee & Employee::operator=(const Employee &employee) {
    if (this==&employee) {return *this;}
    freeEmployee();
    copyEmployee(employee);
    return *this;
}

bool Employee::operator<(const Employee &employee) const {
    if (salary_==employee.salary_) {
        return id_<employee.id_;
    }
     return salary_<employee.salary_;
}

bool Employee::operator>(const Employee &employee) const {
    return employee < *this;
}

Employee & Employee::operator++() {
    salary_+=(salary_/10);
    return *this;
}

Employee Employee::operator++(int dump) {
    Employee tmp = *this;
    salary_+=salary_/10;
    return tmp;
}

std::ostream & operator<<(std::ostream& os, const Employee& employee) {
    os << employee.getName()<<"- "<<employee.getPosition()<<"- "<<employee.getSalary()<<"(Id:"<<employee.getId()<<")\n";
    return os;
}


double Employee::getSalary() const {return salary_;}

ErrorCode Employee::updateSalary(double parcent) {

    if (parcent<=0) return ErrorCode::InvalidInput;
    salary_ += salary_*(parcent/100);
    return ErrorCode::OK;
}