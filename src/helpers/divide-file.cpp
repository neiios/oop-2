#include "divide-file.h"
#include "../classes/timer.h"
#include "../input/input.h"
#include "helper-functions.h"

#include <algorithm>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

template <typename Container>
void divideFile(const int& studentCount) {
  Container s;
  string filename = "kursiokai" + std::to_string(studentCount) + ".txt";

  Timer t;
  double partTime, totalTime = 0;

  inputFromFile(s, false, filename);

  partTime = t.elapsed();
  totalTime += partTime;
  cout << studentCount << " Failo nuskaitymo laikas: " << partTime << " s\n";
  t.reset();

  sortContainer(s);
  auto it = std::find_if(s.begin(), s.end(), [](Student& temp) {
    return temp.getGradesMean() >= 5;
  });
  Container galv(it, s.end());
  s.erase(it, s.end());

  partTime = t.elapsed();
  totalTime += partTime;
  cout << studentCount << " Vektorių padalijimo laikas: " << partTime << " s\n";
  t.reset();

  ofstream fout("vargsiukai" + std::to_string(studentCount) + ".txt");
  for (auto& Student : s) {
    fout << Student.getFirstName() << " " << Student.getLastName() << " ";
    for (auto& grade : Student.getGrades()) {
      fout << grade << " ";
    }
    fout << Student.getExamGrade() << "\n";
  }
  fout.close();

  fout.open("galvociai" + std::to_string(studentCount) + ".txt");
  for (const auto& Student : galv) {
    fout << Student.getFirstName() << " " << Student.getLastName() << " ";
    for (const auto& grade : Student.getGrades()) {
      fout << grade << " ";
    }
    fout << Student.getExamGrade() << "\n";
  }
  fout.close();

  cout << studentCount << " Pilnas laikas: " << totalTime << " s\n";
  cout << "-----------------------------------\n";

  s.clear();
  galv.clear();
}

template <typename Container>
void divideFileFirstStrategy(const int& studentCount) {
  Container s;
  string filename = "kursiokai" + std::to_string(studentCount) + ".txt";

  Timer t;
  double partTime, totalTime = 0;

  inputFromFile(s, false, filename);
  partTime = t.elapsed();
  totalTime += partTime;
  cout << studentCount << " Failo nuskaitymo laikas: " << partTime << " s\n";
  t.reset();

  Container galv, varg;
  for (const auto& Student : s) {
    if (Student.getGradesMean() >= 5) {
      galv.push_back(Student);
    } else {
      varg.push_back(Student);
    }
  }

  sortContainer(galv);
  sortContainer(varg);
  partTime = t.elapsed();
  totalTime += partTime;
  cout << studentCount << " Vektorių padalijimo laikas: " << partTime << " s\n";
  t.reset();

  ofstream fout("vargsiukai" + std::to_string(studentCount) + ".txt");
  for (const auto& Student : varg) {
    fout << Student.getFirstName() << " " << Student.getLastName() << " ";
    for (const auto& grade : Student.getGrades()) {
      fout << grade << " ";
    }
    fout << Student.getExamGrade() << "\n";
  }
  fout.close();

  fout.open("galvociai" + std::to_string(studentCount) + ".txt");
  for (const auto& Student : galv) {
    fout << Student.getFirstName() << " " << Student.getLastName() << " ";
    for (const auto& grade : Student.getGrades()) {
      fout << grade << " ";
    }
    fout << Student.getExamGrade() << "\n";
  }
  fout.close();
  cout << studentCount << " Pilnas laikas: " << totalTime << " s\n";
  cout << "-----------------------------------\n";
  s.clear();
  varg.clear();
  galv.clear();
}

template <typename Container>
void divideFileSecondStrategy(const int& studentCount) {
  Container s;
  string filename = "kursiokai" + std::to_string(studentCount) + ".txt";

  Timer t;
  double partTime, totalTime = 0;

  inputFromFile(s, false, filename);
  partTime = t.elapsed();
  totalTime += partTime;
  cout << studentCount << " Failo nuskaitymo laikas: " << partTime << " s\n";
  t.reset();

  Container galv;
  sortContainer(s);
  for (auto it = s.begin(); it != s.end(); ++it) {
    if (it->getGradesMean() >= 5) {
      galv.push_back(*it);
      it = s.erase(it);
      --it;
    }
  }
  partTime = t.elapsed();
  totalTime += partTime;
  cout << studentCount << " Vektorių padalijimo laikas: " << partTime << " s\n";
  t.reset();

  ofstream fout("galvociai" + std::to_string(studentCount) + ".txt");
  for (const auto& Student : galv) {
    fout << Student.getFirstName() << " " << Student.getLastName() << " ";
    for (const auto& grade : Student.getGrades()) {
      fout << grade << " ";
    }
    fout << Student.getExamGrade() << "\n";
  }
  fout.close();

  fout.open("vargsiukai" + std::to_string(studentCount) + ".txt");
  for (const auto& Student : s) {
    fout << Student.getFirstName() << " " << Student.getLastName() << " ";
    for (const auto& grade : Student.getGrades()) {
      fout << grade << " ";
    }
    fout << Student.getExamGrade() << "\n";
  }
  fout.close();
  cout << studentCount << " Pilnas laikas: " << totalTime << " s\n";
  cout << "-----------------------------------\n";
  s.clear();
  galv.clear();
}

template void divideFile<vector<Student>>(const int& studentCount);
template void divideFile<list<Student>>(const int& studentCount);
template void divideFile<deque<Student>>(const int& studentCount);

template void divideFileFirstStrategy<vector<Student>>(const int& studentCount);
template void divideFileFirstStrategy<list<Student>>(const int& studentCount);
template void divideFileFirstStrategy<deque<Student>>(const int& studentCount);

template void divideFileSecondStrategy<vector<Student>>(
    const int& studentCount);
template void divideFileSecondStrategy<list<Student>>(const int& studentCount);
template void divideFileSecondStrategy<deque<Student>>(const int& studentCount);
