#include <iostream>
#include <cstring>
#include <print>

#pragma warning (disable:4996)

namespace Constants {
    constexpr int MaxNameLength = 100;
}

enum class Degree {
    Bachelor = 1,
    Master,
    PhD
};

int DegreeToInt(Degree degree) {
	return static_cast<int>(degree);
}

Degree IntToDegree(int degree) {
    if (degree < DegreeToInt(Degree::Bachelor) || degree > DegreeToInt(Degree::PhD)) {
        return Degree::Bachelor;
    }
    return static_cast<Degree>(degree);
}

struct Teacher {
private:
    int id;
    int nonPassedStudents;
    Degree degree;

public:
    int getId() const {
        return id;
	}

    void setId(int id) {
        if (id < 10000 || id > 99999) return;

        this->id = id;
	}

    int getNonPassedStudents() const {
        return nonPassedStudents;
	}

    void setNonPassedStudents(int nonPassedStudents) {
        if (nonPassedStudents < 0) return;

        this->nonPassedStudents = nonPassedStudents;
    }

    Degree getDegree() const {
        return degree;
    }

    void setDegree(Degree degree) {
        this->degree = degree;
    }

    void setAll(int id, int nonPassedStudents, Degree degree) {
        setId(id);
        setNonPassedStudents(nonPassedStudents);
        setDegree(degree);
	}

    void print() const {
        std::println("ID: {}, Non-passed students: {}, Degree: {}", id, nonPassedStudents, DegreeToInt(degree));
	}
};

Teacher* createTeacher(int id, int nonPassedStudents, int degree) {
    if (id < 10000 || id > 99999) {
		std::println("Invalid ID: {}", id);
        return nullptr;
    }
	if (nonPassedStudents < 0) {
        std::println("Invalid number of non-passed students: {}", nonPassedStudents);
        return nullptr;
	}

	Teacher* teacher = new Teacher;
	teacher->setAll(id, nonPassedStudents, IntToDegree(degree));

    return teacher;
}

int main()
{
	Teacher* teacher1 = createTeacher(12345, 10, 2);
	Teacher* teacher2 = createTeacher(54321, 5, 3);
	Teacher* teacher3 = createTeacher(9999, 15, 1);

	if (teacher1) teacher1->print();
	if (teacher2) teacher2->print();
	if (teacher3) teacher3->print();

	delete teacher1;
	delete teacher2;
	delete teacher3;
}