//
// Created by Vanina Laleva on 1.05.26.
//

#include "SortedStudentDB.h"

SortedStudentDB::SortedStudentDB(const StudentDB &other) : StudentDB(other) {
}

bool SortedStudentDB::compareByName(const Student &lhs, const Student &rhs) {
    return lhs.getName() < rhs.getName();
}

void SortedStudentDB::sortBy(bool (*comparator) (const Student&, const Student&)) {
    int size = getSize();
    for (int i = 0; i < size; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (comparator((*this)[j], (*this)[minIndex])) {
                minIndex = j;
            }
        }

        if (i != minIndex) {
            std::swap((*this)[i], (*this)[minIndex]);
        }
    }
}
