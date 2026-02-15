#include <iostream>
using std::cout;
using std::endl;
using std::cin;
enum class Education{
    Bachelor,
    Magister,
    Doctor,
    Unknown

};
struct Teacher {
    int ID;
    Education education;
    int rejStudents;
};
Education convertToEducation(const char* education) {
    if (strcmp(education, "Bachelor") == 0) {
        return Education::Bachelor;
    }
    if (strcmp(education, "Magister") == 0) {
        return Education::Magister;
    }
    if (strcmp(education, "Doctor") == 0) {
        return Education::Doctor;
    }
    return Education::Unknown;
}
bool isValidID(int ID) {
    return ID > 10000 && ID < 99999;
}
Teacher initialize(int ID, const char* edu, int rejStudent) {
    Education education = convertToEducation(edu);
    if (!isValidID(ID) || education == Education::Unknown) {
        cout << "Invalid ID or Education" << endl;
        Teacher teacher = { 0,education,0 };
        return teacher;
    }
    return { ID,education,rejStudent };
}

constexpr int TEACHER_COUNT = 3;

struct University {
    Teacher teachers[TEACHER_COUNT];
    double avgFailedStudents = 0;
};

void initializeUni(University& uni) {
    Teacher t1 = { 12345,Education::Bachelor,10 };
    Teacher t2 = { 54321, Education::Magister,5 };
    Teacher t3 = { 15678,Education::Doctor,15 };
    for (int i = 0; i < TEACHER_COUNT; i++) {
        int id,failedStudents;
        char education[100];
        cin >> id >> education >> failedStudents;
        uni.teachers[i] = initialize(id, education, failedStudents);
        uni.avgFailedStudents += failedStudents;
    }
    uni.avgFailedStudents /= TEACHER_COUNT;
}

int teacherMinRequiriment(const University& uni, int minFailedStudents) {
    size_t teacherCount = 0;
    for (int i = 0; i < TEACHER_COUNT; i++) {
        if (uni.teachers[i].rejStudents > minFailedStudents) {
            teacherCount++;
        }
    }
    return teacherCount;
}
void sortTeachers(University& uni, bool (*pred) (const Teacher& t1, const Teacher& t2)) {
    for (int i = 0; i < TEACHER_COUNT - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < TEACHER_COUNT; j++) {
            if (pred(uni.teachers[j],uni.teachers[minIndex])) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            std::swap(uni.teachers[i], uni.teachers[minIndex]);
        }
    }
}
const char* eduToString(const Education& education) {
    switch (education) {
        case Education::Bachelor: {
            return "Bachelor";
        }
        case Education::Magister: {
            return "Magister";
        }
        case Education::Doctor: {
            return "Doctor";
        }
        default: {
            return "Unknown";
        }
    }
}
void printTeacher(const Teacher& teacher) {

    cout << teacher.ID << " " << eduToString(teacher.education) << " " << teacher.rejStudents<<endl;
}
int main()
{
    University uni;
    initializeUni(uni);
    sortTeachers(uni, [](const Teacher& t1, const Teacher& t2) {
        return t1.rejStudents < t2.rejStudents; });
    for (int i = 0; i < TEACHER_COUNT; i++) {
        printTeacher(uni.teachers[i]);
    }
}