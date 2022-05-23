#pragma once

/**
 * @file helper-functions.h
 * @brief Different functions used all over the program for various purposes.
 */

#include <algorithm>
#include <deque>
#include <list>
#include <random>
#include <vector>
#include "../classes/student.h"
#include "../classes/Vector.hpp"

void randomizeGrades(Student& s,
                     const int& gradeCount,
                     std::mt19937& engine,
                     std::uniform_int_distribution<int>& dist);

void generateStudents(const int& gradeCount, const int& studentCount);

void sortContainer(std::vector<Student>& s);
void sortContainer(std::list<Student>& s);
void sortContainer(std::deque<Student>& s);
void sortContainer(Vector<Student>& s);