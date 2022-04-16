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
    divideFile<vector<student>>(i);
    cout << "List:\n";
    divideFile<list<student>>(i);
    cout << "Deque:\n";
    divideFile<deque<student>>(i);
    cout << "\n\n";
  }
}

void generateNewFiles() {
  for (int i = 1000; i <= 10000000; i *= 10) {
    generateStudents(10, i);
  }
}
