#ifndef OBJEKTINIO_PROGRAMAVIMO_UZDUOTIS_HELPER_FUNCTIONS_H
#define OBJEKTINIO_PROGRAMAVIMO_UZDUOTIS_HELPER_FUNCTIONS_H

#include <deque>
#include <list>
#include <vector>
#include "new-data-types.h"

double findAverage(const student& s);
double findMedian(student s);
void sortContainer(std::vector<student>& s);
void sortContainer(std::list<student>& s);
void sortContainer(std::deque<student>& s);

#endif  // OBJEKTINIO_PROGRAMAVIMO_UZDUOTIS_HELPER_FUNCTIONS_H
