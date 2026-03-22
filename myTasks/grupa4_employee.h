// #pragma once
//
// constexpr  int MAX_LEN_NAME = 127;
// constexpr  int MIN_SALARY =1000;
// constexpr  int MAX_EMPLOYEES = 15;
// enum class ErrorCode
// {
//     OK,
//     NotFound,
//     Duplicate,
//     InvalidInput,
//     FullTeam,
//     FullDeparmentCont
// };
// class grupa4_employee
// {
//     private:
//         static unsigned int Lastid;
//         unsigned int ID;
//         char name[MAX_LEN_NAME];
//         char position[MAX_LEN_NAME];
//         double salary;
//
//     public:
//         grupa4_employee();
//         grupa4_employee(const char*inpName, const char*inpPosition, double inpSalary);
//
//         void setName(const char *inpName);
//         void setPosition(const char *inpPosition);
//         void setSalary(double inpSalary);
//
//         double getSalary() const;
//         ErrorCode updateSalary(double amount);
//         static unsigned int getLastID();
//         const char* getPosition() const;
//
//         void printInfoEmployee() const;
//         const char *getEmployeeName() const;
//         const char* printExitCode(ErrorCode currErrorCode) const;
//
// };
//
// class  Department
// {
//     private:
//      char name[MAX_LEN_NAME];
//      grupa4_employee Employees[MAX_EMPLOYEES];
//     unsigned int countOfEmployees;
//
//     public:
//      Department();
//      Department(const char* inpName);
//      void setDepName(const char*);
//      const char* getDepName() const;
//     ErrorCode addEmployee(const grupa4_employee& currEmployee);
//     ErrorCode removeEmployee(unsigned int);
//     static unsigned getMaxEmployees();
// };
//
// constexpr  int MAX_DEPARTMENTS = 10;
// class  Company
// {
//     private:
//         Department departments[MAX_DEPARTMENTS];
//         unsigned int countOfDepartments = 0;
//         Company();
//
//     public:
//         static Company& getInstance();
//         Company(const Company&) = delete;
//         Company& operator=(const Company&) = delete;
//
//         ErrorCode addDepartment(const char* );
//         ErrorCode removeDepartment(const char* );
//         ErrorCode addEmployeeToDepartment(const char* ,const grupa4_employee& );
//         ErrorCode removeEmployeeFromDeaprtment(const char* ,unsigned int);
//
//
//
// };
