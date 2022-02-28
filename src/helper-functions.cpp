#include "helper-functions.h"
#include <algorithm>

void findAverage(student &s) {
    s.finalGradeAvg = 0;
    for (auto grade: s.grades) {
        s.finalGradeAvg += grade;
    }

    if (s.grades.empty()) {
        s.finalGradeAvg = s.examGrade * 0.6;
    } else {
        s.finalGradeAvg = s.finalGradeAvg / (double)s.grades.size() * 0.4 + s.examGrade * 0.6;
    }
}

void findMedian(student &s) {
    if (s.grades.empty()) {
        s.finalGradeMedian = s.examGrade * 0.6;
        return;
    }

    std::sort(s.grades.begin(), s.grades.end());
    if (s.grades.size() % 2 == 0) {
        s.finalGradeMedian =
                ((s.grades[s.grades.size() / 2 - 1] + s.grades[s.grades.size() / 2]) / 2.0) * 0.4 + s.examGrade * 0.6;
    } else {
        s.finalGradeMedian = s.grades[s.grades.size() / 2] * 0.4 + s.examGrade * 0.6;
    }
}

bool sortByLastName(const student &temp1, const student &temp2) {
    return temp1.lastName < temp2.lastName;
}