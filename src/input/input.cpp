#include "input.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <random>
#include <sstream>
#include <string>

#include "../helpers/helper-functions.h"

using namespace std;

void inputGrades(student& s, int gradeCount) {
  for (size_t j = 0; j < gradeCount; j++) {
    int temp;
    cout << "Įveskite pažymį Nr." << j + 1 << ": ";
    // input check
    while (!(cin >> temp) || temp < -1 || temp > 10) {
      cout << "Klaidingas pažymys, bandikyte įvesti dar kartą: ";
      cin.clear();  // Clear error flags
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    s.grades.push_back(temp);
  }
}

void inputGradesEndless(student& s) {
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
    s.grades.push_back(temp);
  }
}

void input(vector<student>& s) {
  std::random_device random_device;
  std::mt19937 engine(random_device());
  std::uniform_int_distribution<int> dist(0, 10);
  while (true) {
    student sTemp;
    int gradeCount = 0;

    cout << "Įveskite studento vardą: ";
    cin >> sTemp.firstName;
    cout << "Įveskite studento pavardę: ";
    cin >> sTemp.lastName;
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
    while (!(cin >> sTemp.examGrade) || sTemp.examGrade < -1 ||
           sTemp.examGrade > 10) {
      cout << "Klaidingas pažymys, bandikyte įvesti dar kartą: ";
      cin.clear();  // Clear error flags
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    sTemp.finalGradeAvg = findAverage(sTemp);
    sTemp.finalGradeMedian = findMedian(sTemp);
    sTemp.finalGradeMean = (sTemp.finalGradeAvg + sTemp.finalGradeMedian) / 2;
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
    student tempStudent;
    std::istringstream subStr(line);

    subStr >> tempStudent.firstName >> tempStudent.lastName;

    int tempGrade;
    while (subStr >> tempGrade) {
      tempStudent.grades.push_back(tempGrade);
    }

    tempStudent.examGrade = tempStudent.grades.back();
    tempStudent.grades.pop_back();

    tempStudent.finalGradeAvg = findAverage(tempStudent);
    tempStudent.finalGradeMedian = findMedian(tempStudent);
    tempStudent.finalGradeMean =
        (tempStudent.finalGradeAvg + tempStudent.finalGradeMedian) / 2;
    s.push_back(tempStudent);
  }
  fin.close();
}

template void inputFromFile(vector<student>& s,
                            const bool& removeFirstLine,
                            const std::string& filename);
template void inputFromFile(list<student>& s,
                            const bool& removeFirstLine,
                            const std::string& filename);
template void inputFromFile(deque<student>& s,
                            const bool& removeFirstLine,
                            const std::string& filename);
