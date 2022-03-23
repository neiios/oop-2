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
#include "input-output.h"
#include "timer.h"

using namespace std;

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

void randomizeGrades(student &s, const int &gradeCount, std::mt19937 &engine, std::uniform_int_distribution<int> &dist) {
    for (size_t j = 0; j < gradeCount; j++) {
        int temp = dist(engine);
        s.grades.push_back(temp);
    }
    s.examGrade = dist(engine);
}

void inputGradesEndless(student &s) {
    for (;;) {
        int temp = 0;
        cout << "Įveskite nauja pažymį (įveskite \"-1\", kai norite baigti įvedimą): ";
        while (!(cin >> temp) || temp < -1 || temp > 10) {
            cout << "Klaidingas pažymys, bandikyte įvesti dar kartą: ";
            cin.clear(); // Clear error flags
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if (temp == -1)
            break;
        s.grades.push_back(temp);
    }
}

void input(vector<student> &s) {
    std::random_device random_device;
    std::mt19937 engine(random_device());
    std::uniform_int_distribution<int> dist(0,10);
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
            cin.clear(); // Clear error flags
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

void inputFromFile(vector<student> &s, const bool &removeFirstLine, const string &filename){
    std::ifstream fin;

    try {
        fin.open(filename);
        if(!fin.is_open()){
            throw std::runtime_error("Failas neegzistuoja!");
        }
    } catch (const std::exception &e) {
        fin.close();
        std::terminate();
    }

    // skip first line
    string line;
    if(removeFirstLine)
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

        tempStudent.finalGradeAvg = findAverage(tempStudent);
        tempStudent.finalGradeMedian = findMedian(tempStudent);
        tempStudent.finalGradeMean = (tempStudent.finalGradeAvg + tempStudent.finalGradeMedian) / 2;
        s.push_back(tempStudent);
    }
    fin.close();
}

void generateStudents(const int &gradeCount, const int &studentCount){
    std::random_device random_device;
    std::mt19937 engine(random_device());
    std::uniform_int_distribution<int> dist(0,10);

    FILE *file;
    file = fopen(("kursiokai" + std::to_string(studentCount) + ".txt").c_str(), "w");

    string buffer;
    for (int i = 1; i <= studentCount; ++i) {
        student stud;
        stud.firstName = "Vardas" + std::to_string(i);
        stud.lastName = "Pavarde" + std::to_string(i);
        randomizeGrades(stud, gradeCount, engine, dist);
        buffer.append(stud.firstName + " " + stud.lastName + " ");
        for(const auto &grade:stud.grades){
            buffer.append(std::to_string(grade) + " ");
        }
        buffer.append(std::to_string(stud.examGrade) + "\n");
    }

    fprintf(file, "%s", buffer.c_str());
    fclose(file);
}

void divideFile(const int &gradeCount, const int &studentCount){
    vector<student> s;
    string filename = "kursiokai" + std::to_string(studentCount) + ".txt";

    Timer t;
    double partTime, totalTime = 0;

    inputFromFile(s, false, filename);
    ///////////////////////
    partTime = t.elapsed();
    totalTime += partTime;
    cout << studentCount << " Failo nuskaitymo laikas: " << partTime << " s\n";
    t.reset();

    std::sort(s.begin(), s.end(), [](const student &temp1, const student &temp2){
        return temp1.finalGradeMean < temp2.finalGradeMean;
    });
    ///////////////////////
    partTime = t.elapsed();
    totalTime += partTime;
    cout << studentCount << " Rūšiavimo laikas: " << partTime << " s\n";
    t.reset();

    auto it = std::find_if(s.begin(), s.end(), [](const student &temp){
        return temp.finalGradeMean > 5;
    });
    vector<student> galv(it, s.end());
    s.erase(it, s.end());
    s.shrink_to_fit();
    ///////////////////////
    partTime = t.elapsed();
    totalTime += partTime;
    cout << studentCount << " Vektorių padalijimo laikas: " << partTime << " s\n";
    t.reset();

    ofstream fout("vargsiukai" + std::to_string(studentCount) + ".txt");
    for(const auto& student:s){
        fout << student.firstName << " " << student.lastName << " ";
        for(const auto& grade:student.grades){
            fout << grade << " ";
        }
        fout << student.examGrade << "\n";
    }
    fout.close();

    fout.open("galvociai" + std::to_string(studentCount) + ".txt");
    for(const auto& student:galv){
        fout << student.firstName << " " << student.lastName << " ";
        for(const auto& grade:student.grades){
            fout << grade << " ";
        }
        fout << student.examGrade << "\n";
    }
    fout.close();
    ///////////////////////
    partTime = t.elapsed();
    totalTime += partTime;
    cout << studentCount << " Įrašymo į failus laikas: " << partTime << " s\n";
    cout << studentCount << " Pilnas laikas: " << totalTime << " s\n";
    cout << "-----------------------------------\n";
}

void output(vector<student> &s) {
    if(s.empty()){
        cout << "Nėra studentų.\n";
        return;
    }

    // sort by last name before output
    std::sort(s.begin(), s.end(), [](const student &temp1, const student &temp2){
        return temp1.lastName < temp2.lastName;
    });

    printf("\n\n%-15s%-15s%-20s%-20s", "Pavarde", "Vardas", "Galutinis (Vid.)", "Galutinis (Med.)");
    printf("\n------------------------------------------------------------------\n");
    for (const auto &stud: s) {
        printf("%-15s%-15s%-20.2lf%-20.2lf\n", stud.lastName.c_str(),
               stud.firstName.c_str(), stud.finalGradeAvg, stud.finalGradeMedian);
    }
}
