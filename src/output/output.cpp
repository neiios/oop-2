#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

#include "../classes/student.h"
#include "output.h"

using namespace std;

void output(vector<student>& s) {
  if (s.empty()) {
    cout << "Nėra studentų.\n";
    return;
  }

  // sort by last name before output
  std::sort(s.begin(), s.end(), [](const student& temp1, const student& temp2) {
    return temp1.lastName < temp2.lastName;
  });

  printf("\n\n%-15s%-15s%-20s%-20s", "Pavarde", "Vardas", "Galutinis (Vid.)",
         "Galutinis (Med.)");
  printf(
      "\n------------------------------------------------------------------\n");
  for (const auto& stud : s) {
    printf("%-15s%-15s%-20.2lf%-20.2lf\n", stud.lastName.c_str(),
           stud.firstName.c_str(), stud.finalGradeAvg, stud.finalGradeMedian);
  }
}