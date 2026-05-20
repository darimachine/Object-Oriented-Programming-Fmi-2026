#include <iostream>
#include "Team.h"

int main()
{
    Person p1("Ivan", "Ivanov", "Petrov", "1234567890");
    Person p2("Georgi", "Georgiev", "Georgiev", "0987654321");
    Person p3("Maria", "Marieva", "Petrova", "1122334455");
    Person p4("Petar","Petrov", "5544332211");

    Group g;
    g += p1;
    g += p2;
    g += p1;

    std::cout << "Group size: " << g() << '\n'; 
    std::cout << "p1 in group: " << g(p1) << '\n';
    std::cout << "p3 in group: " << g(p3) << '\n';

    g -= p2;
    std::cout << "Group size after remove: " << g() << '\n';

    Team t;
    t += p1;
    t += p2;
    t += p3;
    t += p4;

    std::cout << "Set manager: " << t(p1, p2) << '\n';
    std::cout << "Set manager: " << t(p1, p3) << '\n'; 
    std::cout << "Set manager: " << t(p2, p4) << '\n'; 

    std::cout << "Managers count: " << t.countManagers() << '\n'; 

    Team t2;
    t2 += p1;
    t2 += p2;
    t2(p1, p2);

    std::cout << "t > t2: " << (t > t2) << '\n';
    std::cout << "t < t2: " << (t < t2) << '\n';

    const Person& found = t[p1.getEGN()];
    std::cout << "Found: " << found.getFirstName() << '\n';

    return 0;
}