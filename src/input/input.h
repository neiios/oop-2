#pragma once

/**
 * @file input.h
 * @brief File with functions used for input.
 */

#include <string>
#include <vector>
#include "../classes/student.h"

void input(std::vector<Student>& s);

template <typename T>
void inputFromFile(T& s,
                   const bool& removeFirstLine,
                   const std::string& filename);

void generateStudents(const int& gradeCount, const int& studentCount);
