#ifndef OBJEKTINIO_PROGRAMAVIMO_UZDUOTIS_INPUT_OUTPUT_H
#define OBJEKTINIO_PROGRAMAVIMO_UZDUOTIS_INPUT_OUTPUT_H

#include "new-data-types.h"

void input(std::vector<student> &s);
template <typename T>
void inputFromFile(T &s, const bool &removeFirstLine, const std::string &filename);
void output(std::vector<student> &s);
void generateStudents(const int &gradeCount, const int &studentCount);
void divideFile(const int &gradeCount, const int &studentCount);
void divideFileList(const int &gradeCount, const int &studentCount);
void divideFileDeque(const int &gradeCount, const int &studentCount);

#endif //OBJEKTINIO_PROGRAMAVIMO_UZDUOTIS_INPUT_OUTPUT_H
