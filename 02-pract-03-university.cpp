#include <iostream>
#include <print>

namespace Constants {
    constexpr int MaxNameLength = 100;
    constexpr int MaxAddressLength = 200;
	constexpr int TeachersCount = 10;
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
    int id = 10000;
    int nonPassedStudents = 0;
    Degree degree = Degree::Bachelor;

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

struct University {
private:
	double averageNonPassedStudents = 0;
    int teachersCount = 0;
	Teacher teachers[Constants::TeachersCount];

public:
    double getAverageNonPassedStudents() const {
        return averageNonPassedStudents;
    }

    void calculateAverageNonPassedStudents() {
        if (teachersCount == 0) return;
        double sum = 0;

        for (int i = 0; i < teachersCount; i++) {
            sum += teachers[i].getNonPassedStudents();
		}

		averageNonPassedStudents = sum / Constants::TeachersCount;
    }

    const Teacher* getTeachers() const {
        return teachers;
    }

    int getTeachersCount() const {
        return teachersCount;
	}

    void addTeacher(Teacher teacher) {
        if (teachersCount >= Constants::TeachersCount) {
            std::println("Cannot add more teachers. Maximum capacity reached.");
            return;
        }

		teachers[teachersCount++] = teacher;
	}

	int checkQuota(int quota) const {
        int count = 0;

        for (int i = 0; i < teachersCount; i++) {
            if (teachers[i].getNonPassedStudents() >= quota) {
                count++;
            }
        }

        return count;
    }

    void sortTeachersByNonPassedStudents() {
        for (int i = 0; i < teachersCount - 1; i++) {
            for (int j = 0; j < teachersCount - i - 1; j++) {
                if (teachers[j].getNonPassedStudents() > teachers[j + 1].getNonPassedStudents()) {
                    std::swap(teachers[j], teachers[j + 1]);
                }
            }
        }
	}
};

University* createUniversity() {
    University* university = new University;

    for (int i = 0; i < Constants::TeachersCount; i++) {
		int nonPassedStudents = 0;
        int degree;
		std::cin >> nonPassedStudents >> degree;

		Teacher teacher;
		teacher.setAll(10000 + i, nonPassedStudents, IntToDegree(degree));

        university->addTeacher(teacher);
    }

	university->calculateAverageNonPassedStudents();

    return university;
}

int main()
{
	University* university = createUniversity();

	university->sortTeachersByNonPassedStudents();

	std::println("Average non-passed students: {}", university->getAverageNonPassedStudents());
	std::println("Number of teachers with more than 5 non-passed students: {}", university->checkQuota(5));

    delete university;
}