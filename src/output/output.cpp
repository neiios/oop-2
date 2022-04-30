#include "output.h"
#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include "../classes/student.h"

using namespace std;

void output(vector<Student>& s) {
  if (s.empty()) {
    cout << "Nėra studentų.\n";
    return;
  }

  // sort by last name before output
  std::sort(s.begin(), s.end(), [](const Student& temp1, const Student& temp2) {
    return temp1.getLastName() < temp2.getLastName();
  });

  printf("\n\n%-15s%-15s%-20s%-20s", "Pavarde", "Vardas", "Galutinis (Vid.)",
         "Galutinis (Med.)");
  printf(
      "\n------------------------------------------------------------------\n");
  for (const auto& stud : s) {
    printf("%-15s%-15s%-20.2lf%-20.2lf\n", stud.getLastName().c_str(),
           stud.getFirstName().c_str(), stud.getGradesAverage(),
           stud.getGradesMedian());
  }
}
