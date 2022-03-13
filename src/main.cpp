#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include "new-data-types.h"
#include "input-output.h"
#include "helper-functions.h"

using std::cout;
using std::cin;
using std::string;
using std::vector;

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");
    std::vector<student> s;

    cout << "Įvesti studentų duomenis iš failo - 1\n";
    cout << "Įvesti studentų duomenis komandinėje eilutėje - 2\n";
    cout << "Sugeneruoti duomenų failą - 3\n";

    int choice;
    cout << "Jūsų pasirinkimas: ";
    cin >> choice;
    switch (choice) {
        case 1:
            inputFromFile(s);
            output(s);
            break;
        case 2:
            input(s);
            output(s);
            break;
        case 3:
            generateStudents(s);
            outputToFile(s);
            break;
        default:
            cout << "Neteisingas pasirinkimas!\n";
    }

    return 0;
}