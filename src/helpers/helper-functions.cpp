#include "helper-functions.h"
#include "../classes/timer.h"
#include "../input/input.h"

#include <algorithm>
#include <random>

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

void randomizeGrades(student& s,
                     const int& gradeCount,
                     std::mt19937& engine,
                     std::uniform_int_distribution<int>& dist) {
  for (size_t j = 0; j < gradeCount; j++) {
    int temp = dist(engine);
    s.grades.push_back(temp);
  }
  s.examGrade = dist(engine);
}

void generateStudents(const int& gradeCount, const int& studentCount) {
  std::random_device random_device;
  std::mt19937 engine(random_device());
  std::uniform_int_distribution<int> dist(0, 10);

  FILE* file;
  file =
      fopen(("kursiokai" + std::to_string(studentCount) + ".txt").c_str(), "w");

  string buffer;
  for (int i = 1; i <= studentCount; ++i) {
    student stud;
    stud.firstName = "Vardas" + std::to_string(i);
    stud.lastName = "Pavarde" + std::to_string(i);
    randomizeGrades(stud, gradeCount, engine, dist);
    buffer.append(stud.firstName + " " + stud.lastName + " ");
    for (const auto& grade : stud.grades) {
      buffer.append(std::to_string(grade) + " ");
    }
    buffer.append(std::to_string(stud.examGrade) + "\n");
  }

  fprintf(file, "%s", buffer.c_str());
  fclose(file);
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
