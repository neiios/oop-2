#pragma once

#include <string>
#include <vector>

// struct Student {
//   std::string firstName, lastName;
//   std::vector<int> grades;
//   int examGrade = 0;
//   double gradesAverage = 0, gradesMedian = 0, gradesMean = 0;
// };

class Student {
 private:
  std::string firstName, lastName;
  std::vector<int> grades;
  int examGrade;
  double gradesAverage, gradesMedian, gradesMean;

 public:
  Student() : examGrade(0), gradesAverage(0), gradesMedian(0), gradesMean(0) {}
  // getters
  std::string getFirstName() const { return firstName; }
  std::string getLastName() const { return lastName; }
  std::vector<int> getGrades() const { return grades; }
  int getExamGrade() const { return examGrade; }
  double getGradesAverage() const { return gradesAverage; }
  double getGradesMedian() const { return gradesMedian; }
  double getGradesMean() const { return gradesMean; }
  // setters
  void setFirstName(const std::string& firstName_) { firstName = firstName_; }
  void setLastName(const std::string& lastName_) { lastName = lastName_; }
  void addGrade(const int& grade) { grades.push_back(grade); }
  // use a number for the exam grade if given
  void setExamGrade(const int& examGrade_) { examGrade = examGrade_; }
  // if no arguments are given use the last grade
  void setExamGrade() {
    examGrade = grades.back();
    grades.pop_back();
  }
  void calculateGradesAverage();
  void calculateGradesMedian();
  void calculateGradesMean();
};
