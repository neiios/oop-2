#ifndef OBJEKTINIO_PROGRAMAVIMO_UZDUOTIS_INPUT_OUTPUT_H
#define OBJEKTINIO_PROGRAMAVIMO_UZDUOTIS_INPUT_OUTPUT_H

#include "new-data-types.h"

void input(std::vector<student> &s);
void inputFromFile(std::vector<student> &s);
void output(std::vector<student> &s);
void generateStudents(std::vector<student> &s, const int &gradeCount, const int &studentCount);
void outputToFile(const std::vector<student> &s);

#endif //OBJEKTINIO_PROGRAMAVIMO_UZDUOTIS_INPUT_OUTPUT_H
