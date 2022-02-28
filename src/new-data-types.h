#ifndef OBJEKTINIO_PROGRAMAVIMO_UZDUOTIS_NEW_DATA_TYPES_H
#define OBJEKTINIO_PROGRAMAVIMO_UZDUOTIS_NEW_DATA_TYPES_H

#include <string>
#include <vector>

using namespace std;

struct student {
    string firstName, lastName;
    vector<int> grades;
    int examGrade = 0;
    double finalGradeAvg = 0, finalGradeMedian = 0;
};

#endif //OBJEKTINIO_PROGRAMAVIMO_UZDUOTIS_NEW_DATA_TYPES_H
