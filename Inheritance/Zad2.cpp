#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <stdexcept>

class Student {
public:
    std::string name;
    unsigned facultyNumber{};
    int course{};

    void print() const {
        std::cout << "#" << facultyNumber << " " << name << ", курс " << course << "\n";
    }

};

class StudentDB {
protected:
    std::vector<Student> students;

public:
    void add(const Student& s) {
        if (find(s.facultyNumber) != nullptr) {
            throw std::invalid_argument("Вече съществува фн");
        }
        students.push_back(s);
    }

    void remove(unsigned fn) {
        auto it = std::find_if(students.begin(), students.end(),[fn](const Student& s){ return s.facultyNumber == fn; });
        if (it == students.end()) {
            throw std::out_of_range("Студентът не е намерен.");
        }
        students.erase(it);
    }

    const Student* find(unsigned fn) const {
        for (const auto& s : students) {
            if (s.facultyNumber == fn) {
                return &s;
            }
        }
        return nullptr;
    }

    void display() const {
        std::cout << "База данни (" << students.size() << " студента):\n";
        for (const auto& s : students) s.print();
    }

};

class SortedStudentDB : public StudentDB {
public:
    void sortBy(std::function<bool(const Student&, const Student&)> cmp) {
        std::sort(students.begin(), students.end(), cmp);
    }

    void display() const {
        std::cout << "Сортирана база данни (" << students.size() << " студента):\n";
        for (const auto& s : students) s.print();
    }
};

class FilteredStudentDB : public StudentDB {
public:
    void filter(std::function<bool(const Student&)> f) {
        erase_if(students, [&f](const Student& student){
            return !f(student);
        });
    }

    void limit(std::size_t n) {
        if (n < students.size()) students.resize(n);
    }

    void display() const {
        std::cout << "Филтрирана база данни (" << students.size() << " студента):\n";
        for (const auto& s : students) s.print();
    }

};
