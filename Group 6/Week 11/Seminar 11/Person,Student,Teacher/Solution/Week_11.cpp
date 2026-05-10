#include <iostream>
#include "Manager.h"
#include "Developer.h"
#include "Teacher.h"
#include "Student.h"
using namespace std;

int main()
{
    Person p("Иван Иванов", "ivan@uni.bg", 20);
    p.print();

    Student s("Мария Петрова", "maria@uni.bg", 21, "12345", "Информатика");
    s.addExam("ООП", 5.50);
    s.addExam("Математика", 4.75);
    s.addExam("Алгоритми", 6.00);
    s.addExam("Физика", 7.50);   // игнорира се — извън диапазон
    s.print();

    std::cout << "Среден успех: " << s.getAverage() << "\n";
    std::cout << "Положил ООП:  " << s.hasPassed("ООП") << "\n";  // 1
    std::cout << "Положил БД:   " << s.hasPassed("БД") << "\n";  // 0

    Teacher t("Петър Георгиев", "peter@uni.bg", 45, "проф.", "Компютърни системи");
    t.addSubject("ООП");
    t.addSubject("Алгоритми");
    t.addSubject("Операционни системи");
    t.print();

    std::cout << "Води ООП:     " << t.teaches("ООП") << "\n";  // 1
    std::cout << "Води Физика:  " << t.teaches("Физика") << "\n";  // 0

    // Сравнение по възраст:
    std::cout << (s < t) << "\n";   // 1 — 21 < 45

    // Copy — компилаторът генерира правилен copy constructor:
    Student s2 = s;
    s2.addExam("БД", 5.00);
    std::cout << "\nОригинал среден успех: " << s.getAverage() << "\n";
    std::cout << "Копие среден успех:    " << s2.getAverage() << "\n";
}