#include "SortedStudentDB.h"

void SortedStudentDB::sortBy(std::string criterion) {
    for (int i = 0; i < (int)students.size(); i++) {
        for (int j = 0; j < (int)students.size() - i - 1; j++) {
            bool swapNeeded = false;

            if (criterion == "fn") {
                if (students[j].getFn() > students[j + 1].getFn()) {
                    swapNeeded = true;
                }
            }
            else if (criterion == "course") {
                if (students[j].getCourse() > students[j + 1].getCourse()) {
                    swapNeeded = true;
                }
            }

            if (swapNeeded) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}