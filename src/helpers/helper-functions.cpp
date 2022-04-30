#include "helper-functions.h"
#include <algorithm>
#include "../classes/timer.h"
#include "../input/input.h"

using namespace std;

void randomizeGrades(Student& s,
                     const int& gradeCount,
                     std::mt19937& engine,
                     std::uniform_int_distribution<int>& dist) {
  for (auto j = 0; j < gradeCount; j++) {
    int temp = dist(engine);
    s.addGrade(temp);
  }
  s.setExamGrade(dist(engine));
}

void generateStudents(const int& gradeCount, const int& studentCount) {
  std::random_device random_device;
  std::mt19937 engine(random_device());
  std::uniform_int_distribution<int> dist(0, 10);

  FILE* file;
  file =
      fopen(("kursiokai" + std::to_string(studentCount) + ".txt").c_str(), "w");

  string buffer;
  for (int i = 1; i <= studentCount; ++i) {
    Student stud;
    stud.setFirstName("Vardas" + std::to_string(i));
    stud.setLastName("Pavarde" + std::to_string(i));
    randomizeGrades(stud, gradeCount, engine, dist);
    buffer.append(stud.getFirstName() + " " + stud.getLastName() + " ");
    for (const auto& grade : stud.getGrades()) {
      buffer.append(std::to_string(grade) + " ");
    }
    buffer.append(std::to_string(stud.getExamGrade()) + "\n");
  }

  fprintf(file, "%s", buffer.c_str());
  fclose(file);
}

void sortContainer(std::vector<Student>& s) {
  std::sort(s.begin(), s.end(), [](Student& temp1, Student& temp2) {
    return temp1.getGradesMean() < temp2.getGradesMean();
  });
}
void sortContainer(std::list<Student>& s) {
  s.sort([](Student& temp1, Student& temp2) {
    return temp1.getGradesMean() < temp2.getGradesMean();
  });
}
void sortContainer(std::deque<Student>& s) {
  std::sort(s.begin(), s.end(), [](Student& temp1, Student& temp2) {
    return temp1.getGradesMean() < temp2.getGradesMean();
  });
}
