#include <algorithm>

#include "helper-functions.h"

using namespace std;

double findAverage(const student &s) {
    if (s.grades.empty())
        return s.examGrade * 0.6;

    int sum = 0;
    for (const auto &grade: s.grades)
        sum += grade;
    return sum / (double)s.grades.size() * 0.4 + s.examGrade * 0.6;
}

// dont change the argument
double findMedian(student s) {
    if (s.grades.empty())
        return s.examGrade * 0.6;

    std::sort(s.grades.begin(), s.grades.end());
    if (s.grades.size() % 2 == 0) {
        return ((s.grades[s.grades.size() / 2 - 1] + s.grades[s.grades.size() / 2]) / 2.0) * 0.4 + s.examGrade * 0.6;
    } else {
        return s.grades[s.grades.size() / 2] * 0.4 + s.examGrade * 0.6;
    }
}
