#include <iostream>

#include "Person.h"
#include "Group.h"
#include "Team.h"

int main() {
    try {
        Person p1("Ivan", "Petrov", "Ivanov", "1234567890");
        Person p2("Georgi", "", "Dimitrov", "2234567890");
        Person p3("Maria", "Ivanova", "Petrova", "3234567890");
        Person p4("Stoyan", "", "Georgiev", "4234567890");

        Group g;
        g += p1;
        g += p2;
        g += p3;

        std::cout << "Group size: " << g() << std::endl;

        std::cout << "Is p2 in group: " << g(p2) << std::endl;

        try {
            Person& found = g["1234567890"];
            std::cout << "Found person with EGN 1234567890\n";
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }

        g -= p2;
        std::cout << "Group size after removal: " << g() << std::endl;

        std::cout << "----------------------\n";

        Team t;
        t += p1;
        t += p2;
        t += p3;
        t += p4;

        t(p1, p2); // p1 е шеф на p2
        t(p1, p3); // p1 е шеф на p3
        t(p3, p4); // p3 е шеф на p4

        std::cout << "Managers in team: " << t.managerCount() << std::endl;

        t(p2, p4); // p4 вече е под p2

        std::cout << "Managers after change: " << t.managerCount() << std::endl;

        std::cout << "----------------------\n";

        Team t2;
        t2 += p1;
        t2 += p2;
        t2 += p3;

        t2(p2, p1);

        std::cout << "Managers in team 2: " << t2.managerCount() << std::endl;

        if (t > t2) {
            std::cout << "Team 1 has more managers\n";
        } else {
            std::cout << "Team 2 has more or equal managers\n";
        }

    } catch (const std::exception& e) {
        std::cout << "Fatal error: " << e.what() << std::endl;
    }

    return 0;
}