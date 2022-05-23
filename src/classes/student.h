#pragma once

/**
 * @file student.h
 * Includes two classes, Human and Student
 */

#include <iostream>
#include <string>
#include <vector>
#include "Vector.hpp"

// struct Student {
//   std::string firstName, lastName;
//   std::vector<int> grades;
//   int examGrade = 0;
//   double gradesAverage = 0, gradesMedian = 0, gradesMean = 0;
// };

/** @brief Abstract class Human (cannot be created).
 *
 * Contains two protected variables of type std::string; firstName, lastName.
 * Derived class should implement both getters and setters for these variables.
 */
class Human {
 protected:
  /// First name string.
  std::string firstName;
  /// Last name string.
  std::string lastName;

 public:
  /// Get first name. Not implemented.
  virtual std::string getFirstName() const = 0;
  /// Get last name. Not implemented.
  virtual std::string getLastName() const = 0;
  /// Set first name. Not implemented.
  virtual void setFirstName(const std::string& firstName_) = 0;
  /// Set last name. Not implemented.
  virtual void setLastName(const std::string& lastName_) = 0;
};

/**
 * @brief A Student class that is derived from abstract class Human.
 */
class Student : public Human {
 private:
  Vector<int> grades;
  int examGrade;
  double gradesAverage, gradesMedian, gradesMean;

 public:
  /// @brief Default contructor.
  Student()
      : Human(),
        examGrade(0),
        gradesAverage(0),
        gradesMedian(0),
        gradesMean(0) {}
  ///
  /**
   * Copy constructor.
   * @param temp: Object to copy
   */
  Student(const Student& temp);
  /// @brief Copy assigment operator.
  Student& operator=(Student const& temp);
  // Getters
  std::string getFirstName() const { return firstName; }
  std::string getLastName() const { return lastName; }
  Vector<int> getGrades() const { return grades; }
  int getExamGrade() const { return examGrade; }
  double getGradesAverage() const { return gradesAverage; }
  double getGradesMedian() const { return gradesMedian; }
  double getGradesMean() const { return gradesMean; }
  /**
   * @brief Set student's first name
   * @param firstName_ Student name
   */
  void setFirstName(const std::string& firstName_) { firstName = firstName_; }
  /**
   * @brief Set student's last name
   * @param lastName_ Student last name
   */
  void setLastName(const std::string& lastName_) { lastName = lastName_; }
  /**
   * @brief Add one grade to the grades vector
   * @param grade: The grade to add
   */
  void addGrade(const int& grade) { grades.push_back(grade); }
  /**
   * @brief Exam grade setter. Accepts integer as an argument.
   * @param examGrade_ The student's exam grade
   */
  void setExamGrade(const int& examGrade_) { examGrade = examGrade_; }
  /**
   * @brief Second exam grade setter. Sets exam grade to the last element of the
   * grades vector and then does pop_back(). Does not accept any arguments.
   */
  void setExamGrade() {
    examGrade = grades.back();
    grades.pop_back();
  }
  /**
   * @brief Calculates average.
   * Formula: gradeSum / gradeCount * 0.4 + examGrade * 0.6
   */
  void calculateGradesAverage();
  /**
   * @brief Calculates median.
   * Formula: gradeInTheMiddle * 0.4 + examGrade * 0.6
   */
  void calculateGradesMedian();
  /**
   * @brief Calculates mean. Formula: (average + median) / 2
   */
  void calculateGradesMean();
  /**
   * @brief Reimplementation of << operator. Outputs student's first and last
   * name, exam grade.
   * @param os
   * @param s
   * @return
   */
  friend std::ostream& operator<<(std::ostream& os, const Student& s);
  /**
   * @brief Class destructor. Clears the grades vector before destruction.
   */
  ~Student();
};
