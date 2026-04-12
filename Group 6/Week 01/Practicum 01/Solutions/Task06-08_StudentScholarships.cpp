#include <iostream>
#include <assert.h>

enum class Year {
    First,
    Second,
    Third,
    Fourth,
    Unknown
};

struct Student {
    unsigned fn = 0;
    Year year = Year::Unknown;
    double averageGrade = 0.0;
};

Year getYearFromNumber(unsigned number) {
    switch (number) {
        case 1: return Year::First;
        case 2: return Year::Second;
        case 3: return Year::Third;
        case 4: return Year::Fourth;
        default: return Year::Unknown;
    }
}

const char* getYearString(const Year& year) {
    switch (year) {
        case Year::First: return "First";
        case Year::Second: return "Second";
        case Year::Third: return "Third";
        case Year::Fourth: return "Fourth";
        case Year::Unknown: return "Unknown";
    }
}

bool isValidFn(unsigned fn) {
    return fn > 9999 && fn < 100000;
}

Student initStudent(unsigned fn, unsigned year, double averageGrade) {
    assert(isValidFn(fn));
    return { fn, getYearFromNumber(year), averageGrade };
}

void readStudent(Student& student) {
    unsigned fn, year;
    double avg;
    std::cin >> fn >> year >> avg;
    student = initStudent(fn, year, avg);
}

void printStudent(const Student& student) {
    std::cout << "Fn: " << student.fn 
	    << ", Year: " << getYearString(student.year)
	    << ", Average grade: " << student.averageGrade 
	    << std::endl;
}

const int MAX_STUDENTS_CAPACITY = 10;

struct Group {
    unsigned studentsAmount = 0;
    Student students[MAX_STUDENTS_CAPACITY];
    double averageGrade = 0.0;
};

void readGroup(Group& group) {
    std::cin >> group.studentsAmount;
    double sumOfAvgGrades = 0.0;

    for (unsigned i = 0; i < group.studentsAmount; i++) {
        readStudent(group.students[i]);
        sumOfAvgGrades += group.students[i].averageGrade;
    }

    group.averageGrade = sumOfAvgGrades / group.studentsAmount;
}

unsigned getAmountOfStudentsWithScholarship(const Group& group, double requiredGrade) {
    unsigned result = 0;
    for (unsigned i = 0; i < group.studentsAmount; i++) {
        if (group.students[i].averageGrade >= requiredGrade) {
            result++;
        }
    }

    return result;
}

void sortStudentsInGroup(Group& group, bool(*comparatorFn)(const Student& lhs, const Student& rhs)) {
    for (unsigned i = 0; i < group.studentsAmount; i++) {
        unsigned minIndex = i;
        for (unsigned j = i + 1; j < group.studentsAmount; j++) {
            if (comparatorFn(group.students[j], group.students[minIndex])) {
                minIndex = j;
            }
        }

        if (i != minIndex) {
            std::swap(group.students[i], group.students[minIndex]);
        }
    }
}

void printStudentsWithScholarshipSortedByGrade(Group& group, double requiredGrade) {
    sortStudentsInGroup(group, [](const Student& lhs, const Student& rhs) { return lhs.averageGrade > rhs.averageGrade; });
    for (unsigned i = 0; i < group.studentsAmount; i++) {
        if (group.students[i].averageGrade >= requiredGrade) {
            printStudent(group.students[i]);
        }
    }
}

int main() {
    // ...
}
