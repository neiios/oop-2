#ifndef OBJEKTINIO_PROGRAMAVIMO_UZDUOTIS_HELPER_FUNCTIONS_H
#define OBJEKTINIO_PROGRAMAVIMO_UZDUOTIS_HELPER_FUNCTIONS_H

#include <deque>
#include <list>
#include <random>
#include <vector>
#include "../classes/student.h"

double findAverage(const student& s);
double findMedian(student s);

void randomizeGrades(student& s,
                     const int& gradeCount,
                     std::mt19937& engine,
                     std::uniform_int_distribution<int>& dist);

void sortContainer(std::vector<student>& s);
void sortContainer(std::list<student>& s);
void sortContainer(std::deque<student>& s);

void generateStudents(const int& gradeCount, const int& studentCount);

#endif  // OBJEKTINIO_PROGRAMAVIMO_UZDUOTIS_HELPER_FUNCTIONS_H
