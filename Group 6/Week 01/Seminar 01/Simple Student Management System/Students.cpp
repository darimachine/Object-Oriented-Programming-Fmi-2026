#pragma warning(disable: 4996) // disables warnings for strcpy, strcat, strlen and so on
#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;

namespace Constants {
    const int MAX_NAME_LENGTH = 21;
    const int DEFAULT_AGE = 18;
    const int MAX_GRADES_COUNT = 5;
    const int DEFAULT_YEAR = 1;
}

enum class Major {
    UNKNOWN, SI, KN, INF, IS, M, AD
};

using namespace Constants;

struct Student {
    char name[MAX_NAME_LENGTH]{0};
    unsigned age = DEFAULT_AGE;
    double grades[MAX_GRADES_COUNT];
    unsigned gradesCount = 0;
    unsigned year = DEFAULT_YEAR;
    Major major = Major::UNKNOWN;
};

namespace Utils {
    Major parseNumberToMajor(int number) {
        switch (number) {
        case 1:
            return Major::SI;
        case 2:
            return Major::KN;
        case 3:
            return Major::INF;
        case 4:
            return Major::IS;
        case 5:
            return Major::M;
        case 6:
            return Major::AD;
        default:
            return Major::UNKNOWN;
        }
    }

    // major can also be passed as a copy here, since in reality it's just an int
    const char* parseMajorToString(const Major& major) {
        switch (major) {
        case Major::SI:
            return "Software Enginering";
        case Major::KN:
            return "Computer Science";
        case Major::INF:
            return "Informatics";
        case Major::IS:
            return "Information Systems";
        case Major::M:
            return "Mathematics";
        case Major::AD:
            return "Data Analytics";
        case Major::UNKNOWN:
            return "Unknown";
        }
    }

    // since std::swap for the sorting requires operator= we need to implement our own swapStudents
    void swapStudents(Student& s1, Student& s2) {
        using std::swap;

        char tempName[MAX_NAME_LENGTH];
        strcpy(tempName, s1.name);
        strcpy(s1.name, s2.name);
        strcpy(s2.name, tempName);

        // Swap the remaining fields
        swap(s1.age, s2.age);
        swap(s1.gradesCount, s2.gradesCount);
        for (int i = 0; i < MAX_GRADES_COUNT; ++i) {
            swap(s1.grades[i], s2.grades[i]);
        }
        swap(s1.year, s2.year);
        swap(s1.major, s2.major);
    }
}

using namespace Utils;

void readStudent(Student& student) {
    cin >> student.name >> student.age;
    cin >> student.gradesCount;
    for (int i = 0; i < student.gradesCount; i++) {
        cin >> student.grades[i];
    }
    int majorNum;
    cin >> student.year >> majorNum;
    student.major = parseNumberToMajor(majorNum);
}

void printStudent(const Student& student) {
    cout << "Name: " << student.name
        << ", Age: " << student.age
        << ", Grades: ";

    for (int i = 0; i < student.gradesCount; i++) {
        cout << student.grades[i] << ", ";
    }

    cout << "Year: " << student.year
        << ", Major: " << parseMajorToString(student.major)
        << endl;
}

void addGradeToStudent(Student& student, double grade) {
    if (student.gradesCount == MAX_GRADES_COUNT) {
        cout << "Student already has max amount of grades!";
        return;
    }
    student.grades[student.gradesCount++] = grade;
}

double calculateAverageGrade(const Student& student) {
    double sum = 0.0;
    for (int i = 0; i < student.gradesCount; i++) {
        sum += student.grades[i];
    }
    return sum / student.gradesCount;
}

void sortStudentsByCriteria(Student* students, size_t count,
                            bool (*comparatorFn) (const Student&, const Student&)) {
    for (size_t i = 0; i < count - 1; i++) {
        size_t minIndex = i;

        for (size_t j = i; j < count; j++) {
            if (comparatorFn(students[j], students[minIndex])) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            swapStudents(students[i], students[minIndex]);
        }
    }
}

void printStudents(const Student* students, size_t count) {
    for (size_t i = 0; i < count; i++) {
        printStudent(students[i]);
    }
}

// this function acts like a filter
void printStudentsByCriteria(const Student* students, size_t count,
                             bool (*criteriaFn) (const Student&)) {
    for (size_t i = 0; i < count; i++) {
        if (criteriaFn(students[i])) {
            printStudent(students[i]);
        }
    }
}

namespace SortingComparators {
    bool compareByName(const Student& s1, const Student& s2) {
        return strcmp(s1.name, s2.name) >= 0 ? false : true;
    }

    bool compareByAverageGrade(const Student& s1, const Student& s2) {
        return calculateAverageGrade(s1) > calculateAverageGrade(s2);
    }

    // ...
}

int main() {
    using namespace SortingComparators;

    size_t N;
    cin >> N;
    Student* students = new Student[N];
    for (size_t i = 0; i < N; i++) {
        readStudent(students[i]);
    }

    cout << "Sorted by average grade: " << endl;
    sortStudentsByCriteria(students, N, compareByAverageGrade);
    printStudents(students, N);

    cout << "Sorted by name: " << endl;
    sortStudentsByCriteria(students, N, compareByName);
    printStudents(students, N);

    cout << "Students from SI: " << endl;
    printStudentsByCriteria(students, N, [](const Student& s1) { return s1.major == Major::SI; });
}
