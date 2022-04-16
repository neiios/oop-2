#ifndef OBJEKTINIO_PROGRAMAVIMO_UZDUOTIS_INPUT_H
#define OBJEKTINIO_PROGRAMAVIMO_UZDUOTIS_INPUT_H

#include "../classes/student.h"

#include <string>
#include <vector>

void input(std::vector<student>& s);

template <typename T>
void inputFromFile(T& s,
                   const bool& removeFirstLine,
                   const std::string& filename);

void generateStudents(const int& gradeCount, const int& studentCount);

#endif  // OBJEKTINIO_PROGRAMAVIMO_UZDUOTIS_INPUT_H
