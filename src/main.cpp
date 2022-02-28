#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include "new-data-types.h"
#include "input-output.h"

using std::cout;
using std::cin;
using std::string;
using std::vector;

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
