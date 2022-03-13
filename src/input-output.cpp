#include "input-output.h"
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <algorithm>
#include <vector>
#include <random>
#include <fstream>

#include "new-data-types.h"
#include "helper-functions.h"

using std::cout;
using std::cin;
using std::string;
using std::vector;

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
//        cout << temp << " ";
        s.grades.push_back(temp);
    }
    s.examGrade = dist(engine);
//    cout << "\n";
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
    while(true){
        student sTemp;
        int gradeCount = 0;

        cout << "Įveskite studento vardą: ";
        cin >> sTemp.firstName;
        cout << "Įveskite studento pavardę: ";
        cin >> sTemp.lastName;
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
                randomizeGrades(sTemp, gradeCount);
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
            cin.clear(); // Clear error flags
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        findAverage(sTemp);
        findMedian(sTemp);
        s.push_back(sTemp);

        cout << "Ar norite įvesti dar vieno studento pažymius (T arba N)? ";
        string continueInput;
        if (cin >> continueInput && continueInput != "T" && continueInput != "t") {
            return;
        }
    }
}

void inputFromFile(vector<student> &s){
    std::ifstream fin;

    try {
        fin.open("kursiokai.txt");
        if(!fin.is_open()){
            throw std::runtime_error("Failas neegzistuoja!");
        }
    } catch (const std::exception &e) {
        fin.close();
        std::terminate();
    }

    // skip first line
    string line;
    getline(fin, line);

    while(getline(fin, line)){
        student tempStudent;
        std::istringstream subStr(line);

        subStr >> tempStudent.firstName >> tempStudent.lastName;

        int tempGrade;
        while(subStr >> tempGrade){
            tempStudent.grades.push_back(tempGrade);
        }

        tempStudent.examGrade = tempStudent.grades.back();
        tempStudent.grades.pop_back();

        findAverage(tempStudent);
        findMedian(tempStudent);

        s.push_back(tempStudent);
    }
    fin.close();
}

void generateStudents(vector<student> &s){
    int gradeCount, studentCount;
    cout << "Kiek pažymių turi studentai? ";
    while (!(cin >> gradeCount) || gradeCount < -1) {
        cout << "Klaidingas kiekis, bandikyte įvesti dar kartą: ";
        cin.clear(); // Clear error flags
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    cout << "Kiek yra studentų? ";
    while (!(cin >> studentCount) || studentCount < -1) {
        cout << "Klaidingas kiekis, bandikyte įvesti dar kartą: ";
        cin.clear(); // Clear error flags
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    for (int i = 1; i <= studentCount; ++i) {
        student stud;
        stud.firstName = "Vardas" + std::to_string(i);
        stud.lastName = "Pavarde" + std::to_string(i);
        randomizeGrades(stud, gradeCount);
        s.push_back(stud);
    }
}

void outputToFile(const vector<student> &s){
    if(s.empty()){
        cout << "Nėra studentų.\n";
        return;
    }

    FILE *file;
    file = fopen(("kursiokai" + std::to_string(s.size()) + ".txt").c_str(), "w");

    string buffer;
    for (const auto &stud: s) {
        buffer.append(stud.firstName + " " + stud.lastName + " ");
        for(const auto &grade:stud.grades){
            buffer.append(std::to_string(grade) + " ");
        }
        buffer.append(std::to_string(stud.examGrade) + "\n");
    }

    fprintf(file, "%s\n", buffer.c_str());
    fclose(file);
}

void output(vector<student> &s) {
    if(s.empty()){
        cout << "Nėra studentų.\n";
        return;
    }

    // sort by last name before output
    std::sort(s.begin(), s.end(), sortByLastName);

    printf("\n\n%-15s%-15s%-20s%-20s", "Pavarde", "Vardas", "Galutinis (Vid.)", "Galutinis (Med.)");
    printf("\n------------------------------------------------------------------\n");
    for (const auto &stud: s) {
        printf("%-15s%-15s%-20.2lf%-20.2lf\n", stud.lastName.c_str(),
               stud.firstName.c_str(), stud.finalGradeAvg, stud.finalGradeMedian);
    }
}
