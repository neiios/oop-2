#include <algorithm>
#include <chrono>
#include <iostream>

#include "helper-functions.h"
#include "input-output.h"

using namespace std;

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

bool sortByLastName(const student &temp1, const student &temp2) {
    return temp1.lastName < temp2.lastName;
}

void testSpeed(const int &gradeCount){
    for(int i = 1000; i <= 10000000; i *= 10){
        int studentCount = i;
        auto start = std::chrono::high_resolution_clock::now();
        generateStudents(gradeCount, studentCount);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        cout << i << " Studentų sukūrimas užtruko: " << diff.count() << " s\n";

        auto startDiv = std::chrono::high_resolution_clock::now();
        divideFile(gradeCount, studentCount);
        auto endDiv = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diffDiv = endDiv - startDiv;
        cout << i << " Studentų dalijimas į skirtingus failus užtruko: " << diffDiv.count() << " s\n";
        cout << i << " Pilnas laikas: " << diffDiv.count() +  diff.count() << " s\n\n";
    }
}
