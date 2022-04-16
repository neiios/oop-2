#include <algorithm>
#include <deque>
#include <iostream>
#include <limits>
#include <list>
#include <string>
#include <vector>

#include "classes/student.h"
#include "helpers/divide-file.h"
#include "input/input.h"
#include "output/output.h"
#include "testing/testing.h"

using namespace std;

int main() {
  setlocale(LC_ALL, "en_US.UTF-8");
  std::vector<student> s;

  cout << "Įvesti studentų duomenis iš failo - 1\n";
  cout << "Įvesti studentų duomenis komandinėje eilutėje - 2\n";
  cout << "Sugeneruoti duomenų failą - 3\n";
  cout << "Testuoti programos veikimo greitį - 4\n";
  cout << "Sugeneruoti naujus failus testavimui - 5\n";
  cout << "Ištestuoti skirtingas studentų dalijimo realizacijas - 6\n";

  int choice;
  cout << "Jūsų pasirinkimas: ";
  cin >> choice;
  switch (choice) {
    case 1:
      inputFromFile(s, true, "kursiokai.txt");
      output(s);
      break;
    case 2:
      input(s);
      output(s);
      break;
    case 3:
      int gradeCount, studentCount;
      cout << "Kiek pažymių turi studentai? ";
      while (!(cin >> gradeCount) || gradeCount < -1) {
        cout << "Klaidingas kiekis, bandikyte įvesti dar kartą: ";
        cin.clear();  // Clear error flags
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      cout << "Kiek yra studentų? ";
      while (!(cin >> studentCount) || studentCount < -1) {
        cout << "Klaidingas kiekis, bandikyte įvesti dar kartą: ";
        cin.clear();  // Clear error flags
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      generateStudents(gradeCount, studentCount);
      divideFile<vector<student>>(studentCount);
      break;
    case 4:
      testDivision();
      break;
    case 5:
      generateNewFiles();
      break;
    case 6:
      testDivisionStrategies();
      break;
    default:
      cout << "Neteisingas pasirinkimas!\n";
  }

  return 0;
}
