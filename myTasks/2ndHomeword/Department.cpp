    #include "Department.h"
    #include  <print>
    #include <iostream>

    Department::Department()
    {
        //std::cout << "Default constructor is called." << '\n';
        name = nullptr;
        countOfEmployees =0;
        capacity = 1;
        employees = new Employee[capacity];
    }


    Department::Department(const char* inpName, unsigned initialCapcity) : countOfEmployees(0)
    {
        if (!inpName)
            return;

        setDepName(inpName);
        capacity = initialCapcity;
        employees = new Employee[initialCapcity];
    }


    void Department::setDepName(const char *DepName)
    {
       name = new char[strlen(DepName) + 1];
        strcpy(name, DepName);
    }

    const char *Department::getDepName() const
    {
        return name;
    }

    void Department::free()
    {
        delete [] employees;
        delete [] name;
        name = nullptr;
        employees = nullptr;
    }

    Department::~Department()
    {
        free();
    }

    void Department::copyFrom(const Department &other)
    {
        if (other.employees != nullptr)
        {
            countOfEmployees = other.countOfEmployees;
            capacity = other.capacity;
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);

            employees = new Employee[countOfEmployees];
            for (int i =0; i < countOfEmployees; i++)
            {
                employees[i] = other.employees[i];
            }
        }
    }

    Department::Department(const Department &other)
    {
        copyFrom(other);
    }

    Department &Department::operator=(const Department &other)
    {
        if (this != &other)
        {
            free();
            copyFrom(other);
        }
        return *this;
    }

    void Department::resizeDeparment(unsigned NewCapcity)
    {
        Employee *updatedDepartment = new Employee[NewCapcity];

        for (int i =0; i < capacity; i++)
        {
            updatedDepartment[i] = employees[i];
        }
        delete [] employees;
        employees = nullptr;
        employees = updatedDepartment;

        std::println("The departmnet is successfully resized");

    }

    ErrorCode Department::addEmployee(const Employee& EmployeeToJoin)
    {
        if(countOfEmployees < capacity)
        {
            const char* employeeJoiningName = EmployeeToJoin.getEmployeeName();
            for (int i = 0; i < countOfEmployees; i++)
            {
                const char* currEmployeeName = employees[i].getEmployeeName();
                if (strcmp(currEmployeeName, employeeJoiningName) == 0)
                {
                    std::cout << "The employee is already in the team" << '\n';
                    return ErrorCode::Duplicate;
                }

            }
            employees[countOfEmployees++] = EmployeeToJoin;
        }
        else
        {

                unsigned NewCapacity = capacity *2;
                resizeDeparment(NewCapacity);
                capacity = NewCapacity;
                employees[countOfEmployees++] = EmployeeToJoin;
        }
        return ErrorCode::OK;

    }

    void Department::swapEmployees( Employee &lhs, Employee &rhs)
    {
        Employee temp = lhs;
        lhs = rhs;
        rhs = temp;
    }

    ErrorCode Department::removeEmployee(unsigned int id)
    {
        if (id > countOfEmployees)
        {
            std::println("The team does not have that many members");
            return ErrorCode::InvalidInput;
        }
        else
        {
            unsigned int idx = id - 1;
            swapEmployees(employees[idx], employees[countOfEmployees - 1]);
            countOfEmployees--;

        }
        return ErrorCode::OK;
    }

    std::ostream& operator<<(std::ostream& os, const Department& currDepartmnet)
    {
        os<<"Department name: "<<currDepartmnet.name<<'\n';
        os<<"Department employees count and capacity: "<<currDepartmnet.countOfEmployees<<' '<<currDepartmnet.capacity<<'\n';
        os<<"Employee's information: "<<'\n';
        for (int i =0; i < currDepartmnet.countOfEmployees; i++)
        {
            os<<currDepartmnet.employees[i]<<'\n';
        }

        return os;
    }

    double Department::averageSalaryDepartmnet() const
    {
        double avgSalary;
        double sumSalaries = 0;

        for (int i = 0; i < countOfEmployees; i++)
        {
            sumSalaries += employees[i].getSalary();
        }
        avgSalary = sumSalaries / countOfEmployees;
        return avgSalary;
    }

    bool operator==(const Department&lhs, const Department&rhs)
    {
        return  lhs.countOfEmployees == rhs.countOfEmployees;
    }
    std::strong_ordering Department::operator<=>(const Department &other)
    {
        if (auto cmp = countOfEmployees <=> other.countOfEmployees; cmp !=0)
        {
            return cmp;
        }
        const double avgSalaryLhsDep = averageSalaryDepartmnet();
        const double avgSalaryRhsDep =other.averageSalaryDepartmnet();

        return  std::strong_order(avgSalaryLhsDep, avgSalaryRhsDep);
    }

    const Employee &Department::operator[](unsigned idx) const
    {
        if (idx >= countOfEmployees)
        {
            throw std::out_of_range("The index is out of range");
        }
        return employees[idx];
    }

    Employee &Department::operator[](unsigned idx)
    {
        if (idx >= countOfEmployees)
        {
            throw std::out_of_range("The index is out of range");
        }

       return employees[idx];
    }

    Department::operator bool() const
    {
        if (countOfEmployees != 0)
        {
            return true;
        }
        return false;
    }

    Department &Department::operator()(double procent)
    {
        for (int i =0; i < countOfEmployees; i++)
        {
            double currSalary = employees[i].getSalary();
            double NewSalary =  currSalary + (currSalary * (procent / 100));
            employees[i].setSalary(NewSalary);
        }
        return *this;
    }

    // int main()
    // {
    //     Employee first("Ivan Ivanov", "Senior Software Engineer", 5000);
    //     Employee second("Mariya Petrova", "Junior Developer", 3200);
    //     Employee third("Georgi Dimitrov", "QA Automation", 4800);
    //     Employee e1("Ivan Ivanov",   "Developer", 3000.0);
    //
    //     Department IT("IT", 3);
    //     IT.addEmployee(first);
    //     IT.addEmployee(second);
    //     IT.addEmployee(third);
    //     std::cout<<IT;
    // }

