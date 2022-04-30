#include "testing.h"
#include <deque>
#include <iostream>
#include <list>
#include <vector>
#include "../classes/student.h"
#include "../helpers/divide-file.h"
#include "../helpers/helper-functions.h"

using namespace std;

void testDivision() {
  for (int i = 1000; i <= 10000000; i *= 10) {
    cout << "Vector:\n";
    divideFile<vector<Student>>(i);
    cout << "List:\n";
    divideFile<list<Student>>(i);
    cout << "Deque:\n";
    divideFile<deque<Student>>(i);
    cout << "\n\n";
  }
}

void testDivisionStrategies() {
  cout << "Realizacija 0:\n";
  for (int i = 1000; i <= 10000000; i *= 10) {
    cout << "Vector:\n";
    divideFile<vector<Student>>(i);
    cout << "List:\n";
    divideFile<list<Student>>(i);
    cout << "Deque:\n";
    divideFile<deque<Student>>(i);
    cout << "\n\n";
  }
  cout << "Realizacija 1:\n";
  for (int i = 1000; i <= 10000000; i *= 10) {
    cout << "Vector:\n";
    divideFileFirstStrategy<vector<Student>>(i);
    cout << "List:\n";
    divideFileFirstStrategy<list<Student>>(i);
    cout << "Deque:\n";
    divideFileFirstStrategy<deque<Student>>(i);
    cout << "\n\n";
  }
  cout << "Realizacija 2:\n";
  for (int i = 1000; i <= 10000000; i *= 10) {
    cout << "Vector:\n";
    if (i <= 100000)
      divideFileSecondStrategy<vector<Student>>(i);
    cout << "List:\n";
    divideFileSecondStrategy<list<Student>>(i);
    cout << "Deque:\n";
    if (i <= 100000)
      divideFileSecondStrategy<deque<Student>>(i);
    cout << "\n\n";
  }
}

void testClass() {
  for (int i = 100000; i <= 10000000; i *= 10) {
    cout << "Vector:\n";
    divideFile<vector<Student>>(i);
  }
}

void generateNewFiles() {
  for (int i = 1000; i <= 10000000; i *= 10) {
    generateStudents(10, i);
  }
}

void testRuleOfThree() {
  Student stud;
  string firstName, lastName;
  double exam;

  // create student object
  cout << "Įveskite studento vardą: ";
  cin >> firstName;
  stud.setFirstName(firstName);
  cout << "Įveskite studento pavardę: ";
  cin >> lastName;
  stud.setLastName(lastName);
  cout << "Įveskite studento egzamino pažymį: ";
  cin >> exam;
  stud.setExamGrade(exam);
  cout << "Originalas\n" << stud << "\n";

  // use copy constructor
  Student studCopy(stud);
  cout << "Panaudotas copy constructor\n" << studCopy << "\n";

  // use copy assignment
  Student studCopy2;
  studCopy2 = stud;
  cout << "Panaudotas copy assignment operator\n" << studCopy2 << "\n";
}
