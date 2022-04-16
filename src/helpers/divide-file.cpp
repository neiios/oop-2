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
  partTime = t.elapsed();
  totalTime += partTime;
  cout << studentCount << " Rūšiavimo laikas: " << partTime << " s\n";
  t.reset();

  auto it = std::find_if(s.begin(), s.end(), [](const student& temp) {
    return temp.finalGradeMean >= 5;
  });
  Container galv(it, s.end());
  s.resize(s.size() - galv.size());

  partTime = t.elapsed();
  totalTime += partTime;
  cout << studentCount << " Vektorių padalijimo laikas: " << partTime << " s\n";
  t.reset();

  ofstream fout("vargsiukai" + std::to_string(studentCount) + ".txt");
  for (const auto& student : s) {
    fout << student.firstName << " " << student.lastName << " ";
    for (const auto& grade : student.grades) {
      fout << grade << " ";
    }
    fout << student.examGrade << "\n";
  }
  fout.close();

  fout.open("galvociai" + std::to_string(studentCount) + ".txt");
  for (const auto& student : galv) {
    fout << student.firstName << " " << student.lastName << " ";
    for (const auto& grade : student.grades) {
      fout << grade << " ";
    }
    fout << student.examGrade << "\n";
  }
  fout.close();
  cout << studentCount << " Pilnas laikas: " << totalTime << " s\n";
  cout << "-----------------------------------\n";
  s.clear();
  galv.clear();
}

template void divideFile<vector<student>>(const int& studentCount);
template void divideFile<list<student>>(const int& studentCount);
template void divideFile<deque<student>>(const int& studentCount);