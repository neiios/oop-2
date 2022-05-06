#include "student.h"
#include <algorithm>

using namespace std;

void Student::calculateGradesAverage() {
  if (grades.empty()) {
    gradesAverage = examGrade * 0.6;
  }

  int sum = 0;
  for (const auto& grade : grades)
    sum += grade;
  gradesAverage = sum / (double)grades.size() * 0.4 + examGrade * 0.6;
}

void Student::calculateGradesMedian() {
  if (grades.empty()) {
    gradesMedian = examGrade * 0.6;
  }

  std::sort(grades.begin(), grades.end());
  if (grades.size() % 2 == 0) {
    int size = grades.size();
    double median = (grades[size / 2 - 1] + grades[size / 2]) / 2.0;
    gradesMedian = median * 0.4 + examGrade * 0.6;
  } else {
    int size = grades.size();
    gradesMedian = grades[size / 2] * 0.4 + examGrade * 0.6;
  }
}

void Student::calculateGradesMean() {
  gradesMean = (gradesAverage + gradesMedian) / 2;
}

Student::~Student() {
  grades.clear();
}

// copy constructor
Student::Student(const Student& temp)
    : Human(temp),
      grades(temp.grades),
      examGrade(temp.examGrade),
      gradesAverage(temp.gradesAverage),
      gradesMedian(temp.gradesMedian),
      gradesMean(temp.gradesMean) {}
// copy assigment operator
Student& Student::operator=(Student const& temp) {
  firstName = temp.firstName;
  lastName = temp.lastName;
  grades = temp.grades;
  examGrade = temp.examGrade;
  gradesAverage = temp.gradesAverage;
  gradesMedian = temp.gradesMedian;
  gradesMean = temp.gradesMean;
  return *this;
}

ostream& operator<<(ostream& os, const Student& stud) {
  os << "Studentas: " << stud.firstName << " " << stud.lastName
     << ", egzamino pažymis: " << stud.examGrade << "\n";
  return os;
}
