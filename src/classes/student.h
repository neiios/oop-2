#pragma once

#include <iostream>
#include <string>
#include <vector>

// struct Student {
//   std::string firstName, lastName;
//   std::vector<int> grades;
//   int examGrade = 0;
//   double gradesAverage = 0, gradesMedian = 0, gradesMean = 0;
// };

class Human {
 protected:
  std::string firstName, lastName;

 public:
  // pure virtual getters
  virtual std::string getFirstName() const = 0;
  virtual std::string getLastName() const = 0;
  // pure virtual setters
  virtual void setFirstName(const std::string& firstName_) = 0;
  virtual void setLastName(const std::string& lastName_) = 0;
};

class Student : public Human {
 private:
  std::vector<int> grades;
  int examGrade;
  double gradesAverage, gradesMedian, gradesMean;

 public:
  // constructor
  Student()
      : Human(),
        examGrade(0),
        gradesAverage(0),
        gradesMedian(0),
        gradesMean(0) {}
  // copy constructor
  Student(const Student& temp);
  // copy assigment operator
  Student& operator=(Student const& temp);
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
  // overload << operator
  friend std::ostream& operator<<(std::ostream& os, const Student& s);
  // destructor
  ~Student();
};
