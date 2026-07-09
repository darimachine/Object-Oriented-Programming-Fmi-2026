// // #include <iostream>
//
// #include "Company.h"
// #include<print>
//
// int main() {
//     Employee employee[MAX_EMPLOYEES] = {
//         {"Ivan", "junior", 341.6},
//         {"Georgi", "director", 325.5},
//         {"Gergana", "PR", 435.7}
//     };
//     Department firstDepartment("first department", employee, 3);
//     const Employee newEmployee1("Filip", "HR", 256.45);
//
//     switch (firstDepartment.addEmployee(newEmployee1)) {
//         case ErrorCode::OK:
//             std::print("successfully added employee to department\n");
//             break;
//         case ErrorCode::Duplicate:
//             std::print("duplicated employee to department\n");
//             break;
//         case ErrorCode::InvalidInput:
//             std::print("too meny people in the department\n");
//             break;
//         default:
//             std::print("unknown error\n");
//             break;
//     }
//     Company& company = Company::getInstance();
//
//     // firstDepartment.print();
//
//     switch (company.addDepartment("first department")) {
//         case ErrorCode::OK:
//             std::print("successfully added employee department\n");
//             break;
//         case ErrorCode::Duplicate:
//             std::print("duplicated employee department\n");
//             break;
//         default: std::print("unknown error\n");
//             break;
//     }
//
//     switch (company.removeDepartment("first department")) {
//         case ErrorCode::OK:
//             std::print("successfully removed employee department\n");
//             break;
//         case ErrorCode::NotFound:
//             std::print("not found employee department\n");
//             break;
//         default:
//             std::print("unknown error\n");
//             break;
//     }
//
//     return 0;
// }

#include<iostream>
#include "Company.h"

int main() {
    Employee e1("Иван Иванов", "Разработчик", 3000.0);
    Employee e2("Мария Петрова", "Дизайнер", 2500.0);
    Employee e3("Петър Георгиев", "Мениджър", 4000.0);

    std::cout << e1 << "\n";

    ++e1; // заплатата нараства с 10%: 3000 → 3300
    std::cout << e1.getSalary() << "\n"; // 3300

    std::cout << (e1 > e2 ? "e1 е по-добре платен" : "e2 е по-добре платен") << "\n"; // e1 e poveche

    Company &company = Company::getInstance();

    company.addDepartment("Engineering");
    company.addDepartment("Design");

    // std::cout << company["Engineering"]->getCountOfEmployees() << "\n";
    // std::cout << company["Design"]->getCountOfEmployees() << "\n";

    company.addEmployeeToDepartment("Engineering", e1);
    company.addEmployeeToDepartment("Engineering", e2);
    company.addEmployeeToDepartment("Design", e3);

    std::cout << "\n";
    std::cout << company << "\n"; //
    std::cout << "\n";

    // operator[] за достъп до отдел
    Department *eng = company["Engineering"];
    if (eng) {
        std::cout << (*eng)[0] << "\n"; // първият служител в Engineering
        (*eng)(15); // увеличава заплатите с 15% - 3795e1; 2875e2
        (*eng)(15)(10); // верижно — 15%, после още 10% - 4364.25e1; 3306.25e2
                                        // 4800.68e1; 3636.88e2
    }
    if (*eng)
        std::cout << "Engineering е активен\n"; // tick

    if (company)
        std::cout << "Фирмата е активна\n"; // tick

    Department *des = company["Design"];
    if (eng && des)
        std::cout << (*eng > *des ? "Engineering е по-голям" : "Design е по-голям") << "\n";

    company.removeEmployeeFromDepartment("Engineering", e2.getId());
    company.removeDepartment("Design");
}
