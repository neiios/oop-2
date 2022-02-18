#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <algorithm>
#include <vector>

struct studentas
{
    std::string firstName, lastName;
    std::vector<int> grades;
    int gradeCount = 0, examGrade = 0;
    double finalGradeAvg = 0, finalGradeMedian = 0;
};

void findAverage(studentas &s)
{
    if (s.gradeCount == 0)
    {
        s.finalGradeAvg = s.examGrade * 0.6;
    }
    else
    {
        s.finalGradeAvg = s.finalGradeAvg / s.gradeCount * 0.4 + s.examGrade * 0.6;
    }
}

void findMedian(studentas &s)
{
    std::sort(s.grades.begin(), s.grades.end());
    if (s.gradeCount == 0)
    {
        s.finalGradeMedian = s.examGrade * 0.6;
    }
    if (s.gradeCount % 2 == 0)
    {
        s.finalGradeMedian = ((s.grades[s.grades.size() / 2 - 1] + s.grades[s.grades.size() / 2]) / 2.0) * 0.4 + s.examGrade * 0.6;
    }
    else
    {
        s.finalGradeMedian = s.grades[s.grades.size() / 2] * 0.4 + s.examGrade * 0.6;
    }
}

void input(std::vector<studentas> &s)
{
    for (int i = 0;; i++)
    {
        s.push_back(studentas());
        std::cout << "Įveskite studento vardą: ";
        std::cin >> s[i].firstName;
        std::cout << "Įveskite studento pavardę: ";
        std::cin >> s[i].lastName;
        std::cout << "Ar žinote kiek pažymių turi studentas (įveskite skaičių arba \"-1\" jeigu norite įvesti iki begalybės)? ";
        // input check
        while (!(std::cin >> s[i].gradeCount) || s[i].gradeCount < -1)
        {
            std::cout << s[i].gradeCount << "\n";
            std::cout << "Klaidingas kiekis, bandikyte įvesti dar kartą: ";
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        if (s[i].gradeCount != -1)
        {
            for (size_t j = 0; j < s[i].gradeCount; j++)
            {
                int temp;
                std::cout << "Įveskite pažymį Nr." << j + 1 << ": ";
                // input check
                while (!(std::cin >> temp) || temp < -1 || temp > 10)
                {
                    std::cout << "Klaidingas pažymys, bandikyte įvesti dar kartą: ";
                    std::cin.clear(); // Clear error flags
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                s[i].grades.push_back(temp);
                s[i].finalGradeAvg += s[i].grades.back();
            }
        }
        else
        {
            // endless loop
            for (;;)
            {
                int temp = 0;
                std::cout << "Įveskite nauja pažymį (įveskite \"-1\", jeigu norite baigti įvedimą): ";
                // input check
                while (!(std::cin >> temp) || temp < -1 || temp > 10)
                {
                    std::cout << "Klaidingas pažymys, bandikyte įvesti dar kartą: ";
                    std::cin.clear(); // Clear error flags
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                // exit the for loop if temp == -1
                if (temp == -1)
                {
                    break;
                }

                s[i].grades.push_back(temp);
                s[i].finalGradeAvg += s[i].grades.back();
            }
            s[i].gradeCount = s[i].grades.size();
        }

        std::cout << "Įveskite studento egzamino pažymį: ";
        while (!(std::cin >> s[i].examGrade) || s[i].examGrade < -1 ||
               s[i].examGrade > 10)
        {
            std::cout << "Klaidingas pažymys, bandikyte įvesti dar kartą: ";
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        findAverage(s[i]);
        findMedian(s[i]);

        std::cout << "Ar norite įvesti dar vieno studento pažymius (įveskite \"taip\", visos kitos eilutės bus interpretuotos kaip NE)? ";
        std::string continueInput;
        if (std::cin >> continueInput && continueInput != "taip")
        {
            return;
        }
    }
}

void output(std::vector<studentas> s)
{
    std::string choice;
    std::cout << "Jei norite išvesti medianą įveskite \"m\" (vidurkis - default): ";
    if (std::cin >> choice && choice == "m")
    {
        std::cout << std::left << std::setw(15) << "\n\nPavarde" << std::setw(15) << "Vardas" << std::setw(15) << "Galutinis (Med.)\n";
        std::cout << std::string(45, '-') << "\n";
        for (auto stud : s)
        {
            std::cout << std::left << std::setw(15) << stud.firstName
                      << std::setw(15) << stud.lastName << std::setw(15)
                      << std::fixed << std::setprecision(2) << stud.finalGradeMedian << "\n";
        }
    }
    else
    {
        std::cout << std::left << std::setw(15) << "\n\nPavarde" << std::setw(15) << "Vardas" << std::setw(15) << "Galutinis (Vid.)\n";
        std::cout << std::string(45, '-') << "\n";
        for (auto stud : s)
        {
            std::cout << std::left << std::setw(15) << stud.lastName
                      << std::setw(15) << stud.firstName << std::setw(15)
                      << std::fixed << std::setprecision(2) << stud.finalGradeAvg << "\n";
        }
    }
}

int main()
{
    std::vector<studentas> s;
    input(s);
    output(s);
    return 0;
}
