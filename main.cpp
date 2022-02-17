#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

struct studentas
{
    std::string firstName, lastName;
    int *grades;
    int gradeCount = 0, examGrade = 0;
    double finalGradeAvg = 0;
};

void input(std::vector<studentas> &s)
{
    std::string continueInput;
    for (int i = 0;; i++)
    {
        s.push_back(studentas());
        std::cout << "Įveskite studento vardą: ";
        std::cin >> s[i].firstName;
        std::cout << "Įveskite studento pavardę: ";
        std::cin >> s[i].lastName;
        std::cout << "Įveskite kiek pažymių turi studentas: ";
        // TODO: Check this input (it should be an integer)
        std::cin >> s[i].gradeCount;

        s[i].grades = new int[s[i].gradeCount];
        for (size_t j = 0; j < s[i].gradeCount; j++)
        {
            std::cout << "Įveskite pažymį Nr." << j + 1 << ": ";
            // TODO: Check this input (it should be an integer from 0 to 10)
            std::cin >> s[i].grades[j];
            s[i].finalGradeAvg += s[i].grades[j];
        }

        std::cout << "Įveskite studento egzamino pažymį: ";
        std::cin >> s[i].examGrade;
        s[i].finalGradeAvg = s[i].gradeCount != 0 ? (s[i].finalGradeAvg / s[i].gradeCount) * 0.4 + s[i].examGrade * 0.6 : s[i].examGrade * 0.6;

        delete[] s[i].grades;

        while (true)
        {
            std::cout << "Ar norite įvesti dar vieno studento pažymius? (Įveskite TAIP, visos kitos eilutės bus interpretuotos kaip NE): ";
            if (std::cin >> continueInput && continueInput == "TAIP")
            {
                break;
            }
            else
            {
                return;
            }
        }
    }
}

void output(std::vector<studentas> s)
{
    std::cout << std::left << std::setw(15) << "Pavardė" << std::setw(15) << "Vardas" << std::setw(15) << "Galutinis (Vid.)\n";
    std::cout << "----------------------------------------------------------\n";
    for (auto stud : s)
    {
        std::cout << std::left << std::setw(15) << stud.firstName << std::setw(15) << stud.lastName << std::setw(15) << std::fixed << std::setprecision(2) << stud.finalGradeAvg << "\n";
    }
}

int main()
{
    std::vector<studentas> s;
    input(s);
    output(s);
    return 0;
}
