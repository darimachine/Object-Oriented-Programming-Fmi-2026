// #include <iostream>
//
// // TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
// int main() {
//     // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the <b>lang</b> variable name to see how CLion can help you rename it.
//     auto lang = "C++";
//     std::cout << "Hello and welcome to " << lang << "!\n";
//
//     for (int i = 1; i <= 5; i++) {
//         // TIP Press <shortcut actionId="Debug"/> to start debugging your code. We have set one <icon src="AllIcons.Debugger.Db_set_breakpoint"/> breakpoint for you, but you can always add more by pressing <shortcut actionId="ToggleLineBreakpoint"/>.
//         std::cout << "i = " << i << std::endl;
//     }
//
//     return 0;
//     // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
// }

#include "Company.h"
#include<print>

int main() {
    Employee employee[MAX_EMPLOYEES] = {
        {1, "Ivan", "junior", 341.6},
        {2, "Georgi", "director", 325.5},
        {3, "Gergana", "PR", 435.7}
    };
    Department firstDepartment("first department", employee, 3);
    const Employee newEmployee1(4, "Filip", "HR", 256.45);

    switch (firstDepartment.addEmployee(newEmployee1)) {
        case ErrorCode::OK:
            std::print("successfully added employee to department\n");
            break;
        case ErrorCode::Duplicate:
            std::print("duplicated employee to department\n");
            break;
        case ErrorCode::InvalidInput:
            std::print("too meny people in the department\n");
            break;
        default:
            std::print("unknown error\n");
            break;
    }
    Company company;

    // firstDepartment.print();

    switch (company.addDepartment("first department")) {
        case ErrorCode::OK:
            std::print("successfully added employee department\n");
            break;
        case ErrorCode::Duplicate:
            std::print("duplicated employee department\n");
            break;
        default: std::print("unknown error\n");
            break;
    }

    switch (company.removeDepartment("first department")) {
        case ErrorCode::OK:
            std::print("successfully removed employee department\n");
            break;
        case ErrorCode::NotFound:
            std::print("not found employee department\n");
            break;
        default:
            std::print("unknown error\n");
            break;
    }

    return 0;
}
