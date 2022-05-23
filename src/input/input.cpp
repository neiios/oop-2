#include "input.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <random>
#include <sstream>
#include <string>
#include "../classes/Vector.hpp"
#include "../helpers/helper-functions.h"

using namespace std;

void inputGrades(Student& s, int gradeCount) {
  for (auto j = 0; j < gradeCount; j++) {
    int temp;
    cout << "Įveskite pažymį Nr." << j + 1 << ": ";
    // input check
    while (!(cin >> temp) || temp < -1 || temp > 10) {
      cout << "Klaidingas pažymys, bandikyte įvesti dar kartą: ";
      cin.clear();  // Clear error flags
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    s.addGrade(temp);
  }
}

void inputGradesEndless(Student& s) {
  for (;;) {
    int temp = 0;
    cout << "Įveskite nauja pažymį (įveskite \"-1\", kai norite baigti "
            "įvedimą): ";
    while (!(cin >> temp) || temp < -1 || temp > 10) {
      cout << "Klaidingas pažymys, bandikyte įvesti dar kartą: ";
      cin.clear();  // Clear error flags
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    if (temp == -1)
      break;
    s.addGrade(temp);
  }
}

void input(vector<Student>& s) {
  std::random_device random_device;
  std::mt19937 engine(random_device());
  std::uniform_int_distribution<int> dist(0, 10);
  while (true) {
    Student sTemp;
    int gradeCount = 0;

    cout << "Įveskite studento vardą: ";
    string firstName;
    cin >> firstName;
    sTemp.setFirstName(firstName);
    cout << "Įveskite studento pavardę: ";
    string lastName;
    cin >> lastName;
    sTemp.setFirstName(lastName);
    sTemp.setLastName(lastName);
    cout << "Ar žinote kiek pažymių turi studentas"
         << " (\"-1\" jeigu nežinote)? ";
    // input check
    while (!(cin >> gradeCount) || gradeCount < -1) {
      cout << "Klaidingas kiekis, bandikyte įvesti dar kartą: ";
      cin.clear();  // Clear error flags
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // input grades
    if (gradeCount > 0) {
      string choice;
      cout << "Sugeneruoti pažymius automatiškai (T arba N)? ";
      if (cin >> choice && (choice == "T" || choice == "t")) {
        randomizeGrades(sTemp, gradeCount, engine, dist);
      } else {
        inputGrades(sTemp, gradeCount);
      }
    }
    if (gradeCount == -1) {
      inputGradesEndless(sTemp);
    }

    cout << "Įveskite studento egzamino pažymį: ";
    int examGrade;
    while (!(cin >> examGrade) || examGrade < -1 || examGrade > 10) {
      cout << "Klaidingas pažymys, bandikyte įvesti dar kartą: ";
      cin.clear();  // Clear error flags
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    sTemp.setExamGrade(examGrade);

    sTemp.calculateGradesAverage();
    sTemp.calculateGradesMedian();
    sTemp.calculateGradesMean();
    s.push_back(sTemp);

    cout << "Ar norite įvesti dar vieno studento pažymius (T arba N)? ";
    string continueInput;
    if (cin >> continueInput && continueInput != "T" && continueInput != "t") {
      return;
    }
  }
}

template <typename T>
void inputFromFile(T& s,
                   const bool& removeFirstLine,
                   const std::string& filename) {
  std::ifstream fin;

  try {
    fin.open(filename);
    if (!fin.is_open()) {
      throw std::runtime_error("Failas neegzistuoja!");
    }
  } catch (const std::exception& e) {
    fin.close();
    std::terminate();
  }

  // skip first line
  string line;
  if (removeFirstLine)
    getline(fin, line);

  while (getline(fin, line)) {
    Student tempStudent;
    std::istringstream subStr(line);

    string firstName, lastName;
    subStr >> firstName >> lastName;
    tempStudent.setFirstName(firstName);
    tempStudent.setLastName(lastName);

    int tempGrade;
    while (subStr >> tempGrade) {
      tempStudent.addGrade(tempGrade);
    }

    tempStudent.setExamGrade();

    tempStudent.calculateGradesAverage();
    tempStudent.calculateGradesMedian();
    tempStudent.calculateGradesMean();
    s.push_back(tempStudent);
  }
  fin.close();
}

template void inputFromFile(vector<Student>& s,
                            const bool& removeFirstLine,
                            const std::string& filename);
template void inputFromFile(list<Student>& s,
                            const bool& removeFirstLine,
                            const std::string& filename);
template void inputFromFile(deque<Student>& s,
                            const bool& removeFirstLine,
                            const std::string& filename);
template void inputFromFile(Vector<Student>& s,
                            const bool& removeFirstLine,
                            const std::string& filename);
