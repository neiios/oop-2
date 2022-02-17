#include <iostream>
#include <string>
#include <iomanip>

struct studentas
{
    std::string firstName, lastName;
    int *grades;
    int gradeCount, examGrade;
    double finalGradeAvg = 0;
};

void input(studentas &s)
{
    std::cout << "Įveskite studento vardą: ";
    std::cin >> s.firstName;
    std::cout << "Įveskite studento pavardę: ";
    std::cin >> s.lastName;
    std::cout << "Įveskite kiek pažymių turi studentas: ";
    std::cin >> s.gradeCount;

    s.grades = new int[s.gradeCount];
    for (size_t i = 0; i < s.gradeCount; i++)
    {
        std::cout << "Įveskite pažymį Nr." << i + 1 << ": ";
        std::cin >> s.grades[i];
        s.finalGradeAvg += s.grades[i];
    }

    std::cout << "Įveskite studento egzamino pažymį: ";
    std::cin >> s.examGrade;
    s.finalGradeAvg = (s.finalGradeAvg / s.gradeCount) * 0.4 + s.examGrade * 0.6;
}

void output(studentas s)
{
    std::cout << std::left << std::setw(15) << "Pavardė" << std::setw(15) << "Vardas" << std::setw(15) << "Galutinis (Vid.)\n";
    std::cout << "----------------------------------------------------------\n";
    std::cout << std::left << std::setw(15) << s.firstName << std::setw(15) << s.lastName << std::setw(15) << std::fixed << std::setprecision(2) << s.finalGradeAvg << "\n";
}

int main()
{
    studentas s;
    input(s);
    output(s);
    return 0;
}
