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

void generateNewFiles() {
  for (int i = 1000; i <= 10000000; i *= 10) {
    generateStudents(10, i);
  }
}
