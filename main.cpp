#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <algorithm>
#include <vector>
#include <ctime>
#include <random>
#include <fstream>

using std::cout;
using std::cin;
using std::string;
using std::vector;

struct student {
    string firstName, lastName;
    vector<int> grades;
    int examGrade = 0;
    double finalGradeAvg = 0, finalGradeMedian = 0;
};

void findAverage(student &s) {
    s.finalGradeAvg = 0;
    for (auto grade: s.grades) {
        s.finalGradeAvg += grade;
    }

    if (s.grades.empty()) {
        s.finalGradeAvg = s.examGrade * 0.6;
    } else {
        s.finalGradeAvg = s.finalGradeAvg / (double)s.grades.size() * 0.4 + s.examGrade * 0.6;
    }
}

void findMedian(student &s) {
    if (s.grades.empty()) {
        s.finalGradeMedian = s.examGrade * 0.6;
        return;
    }

    std::sort(s.grades.begin(), s.grades.end());
    if (s.grades.size() % 2 == 0) {
        s.finalGradeMedian =
                ((s.grades[s.grades.size() / 2 - 1] + s.grades[s.grades.size() / 2]) / 2.0) * 0.4 + s.examGrade * 0.6;
    } else {
        s.finalGradeMedian = s.grades[s.grades.size() / 2] * 0.4 + s.examGrade * 0.6;
    }
}

void inputGrades(student &s, int gradeCount) {
    for (size_t j = 0; j < gradeCount; j++) {
        int temp;
        cout << "Įveskite pažymį Nr." << j + 1 << ": ";
        // input check
        while (!(cin >> temp) || temp < -1 || temp > 10) {
            cout << "Klaidingas pažymys, bandikyte įvesti dar kartą: ";
            cin.clear(); // Clear error flags
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        s.grades.push_back(temp);
    }
}

void randomizeGrades(student &s, int gradeCount) {
    std::random_device random_device;
    std::mt19937 engine(random_device());
    std::uniform_int_distribution<int> dist(0,10);

    for (size_t j = 0; j < gradeCount; j++) {
        int temp = dist(engine);
        cout << temp << " ";
        s.grades.push_back(temp);
    }
    cout << "\n";
}

void inputGradesEndless(student &s) {
    // endless loop
    for (;;) {
        int temp = 0;
        cout << "Įveskite nauja pažymį (įveskite \"-1\", kai norite baigti įvedimą): ";
        // input check
        while (!(cin >> temp) || temp < -1 || temp > 10) {
            cout << "Klaidingas pažymys, bandikyte įvesti dar kartą: ";
            cin.clear(); // Clear error flags
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        // exit the for loop if temp == -1
        if (temp == -1) {
            break;
        }
        s.grades.push_back(temp);
    }
}

void input(vector<student> &s) {
    for (int i = 0;; i++) {
        s.emplace_back();
        int gradeCount = 0;

        cout << "Įveskite studento vardą: ";
        cin >> s[i].firstName;
        cout << "Įveskite studento pavardę: ";
        cin >> s[i].lastName;
        cout << "Ar žinote kiek pažymių turi studentas" << " (\"-1\" jeigu nežinote)? ";
        // input check
        while (!(cin >> gradeCount) || gradeCount < -1) {
            cout << "Klaidingas kiekis, bandikyte įvesti dar kartą: ";
            cin.clear(); // Clear error flags
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        // input grades
        if (gradeCount > 0) {
            string choice;
            cout << "Sugeneruoti pažymius automatiškai (T arba N)? ";
            if (cin >> choice && (choice == "T" || choice == "t")) {
                randomizeGrades(s[i], gradeCount);
            } else {
                inputGrades(s[i], gradeCount);
            }
        }
        if (gradeCount == -1) {
            inputGradesEndless(s[i]);
        }

        cout << "Įveskite studento egzamino pažymį: ";
        while (!(cin >> s[i].examGrade) || s[i].examGrade < -1 ||
               s[i].examGrade > 10) {
            cout << "Klaidingas pažymys, bandikyte įvesti dar kartą: ";
            cin.clear(); // Clear error flags
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        findAverage(s[i]);
        findMedian(s[i]);

        cout << "Ar norite įvesti dar vieno studento pažymius (T arba N)? ";
        string continueInput;
        if (cin >> continueInput && (continueInput != "T" || continueInput != "t")) {
            return;
        }
    }
}

bool sortByLastName(const student &temp1, const student &temp2) {
    return temp1.lastName < temp2.lastName;
}

void inputFromFile(vector<student> &s){
    std::ifstream fin;
    fin.open("kursiokai.txt");
    if(!fin){
        cout << "Error! File does not exist\n";
        return;
    }

    // skip first line
    string line;
    getline(fin, line);

    while(getline(fin, line)){
        student tempStudent;
        std::istringstream subStr(line);

        subStr >> tempStudent.firstName >> tempStudent.lastName;
        cout << tempStudent.firstName << " " << tempStudent.lastName << " ";

        int tempGrade;
        while(subStr >> tempGrade){
            cout << tempGrade << " ";
            tempStudent.grades.push_back(tempGrade);
        }

        tempStudent.examGrade = tempStudent.grades.back();
        tempStudent.grades.pop_back();
        cout << tempStudent.examGrade << "\n";

        findAverage(tempStudent);
        findMedian(tempStudent);

        s.push_back(tempStudent);
    }

    std::sort(s.begin(), s.end(), sortByLastName);
    fin.close();
}

void output(const vector<student> &s) {
    printf("\n\n%-15s%-15s%-20s%-20s", "Pavarde", "Vardas", "Galutinis (Vid.)", "Galutinis (Med.)");
    printf("\n------------------------------------------------------------------\n");
    for (const auto &stud: s) {
        printf("%-15s%-15s%-20.2f%-20.2f\n", stud.lastName.c_str(),
               stud.firstName.c_str(), stud.finalGradeAvg, stud.finalGradeMedian);
    }
}

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");
    vector<student> s;

    string choice;
    cout << "Ar norite įvesti studento duomenis iš failo (T arba N)? ";
    if (cin >> choice && (choice == "T" || choice == "t")) {
        inputFromFile(s);
    } else {
        input(s);
    }

    output(s);
    return 0;
}
