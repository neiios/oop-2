#include "helper-functions.h"
#include <algorithm>
#include <execution>

using namespace std;

double findAverage(const student& s) {
  if (s.grades.empty())
    return s.examGrade * 0.6;

  int sum = 0;
  for (const auto& grade : s.grades)
    sum += grade;
  return sum / (double)s.grades.size() * 0.4 + s.examGrade * 0.6;
}

// dont change the argument
double findMedian(student s) {
  if (s.grades.empty())
    return s.examGrade * 0.6;

  std::sort(s.grades.begin(), s.grades.end());
  if (s.grades.size() % 2 == 0) {
    int size = s.grades.size();
    double median = (s.grades[size / 2 - 1] + s.grades[size / 2]) / 2.0;
    return median * 0.4 + s.examGrade * 0.6;
  } else {
    int size = s.grades.size();
    return s.grades[size / 2] * 0.4 + s.examGrade * 0.6;
  }
}

void sortContainer(std::vector<student>& s) {
  std::sort(s.begin(), s.end(), [](const student& temp1, const student& temp2) {
    return temp1.finalGradeMean < temp2.finalGradeMean;
  });
}
void sortContainer(std::list<student>& s) {
  s.sort([](const student& temp1, const student& temp2) {
    return temp1.finalGradeMean < temp2.finalGradeMean;
  });
}
void sortContainer(std::deque<student>& s) {
  std::sort(s.begin(), s.end(), [](const student& temp1, const student& temp2) {
    return temp1.finalGradeMean < temp2.finalGradeMean;
  });
}
