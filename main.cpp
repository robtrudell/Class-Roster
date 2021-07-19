#include <iostream>
#include <string>

#include "roster.h"

using namespace std;

int main() {
    cout << "WGU C867: Scripting and Programming Applications" << endl;
    cout << "Language used: C++" << endl;
    cout << "Written by Robert Trudell" << endl;
    cout << "Student ID: 001103636";
    cout << "\n------------------------------------------------";
    cout << endl << endl << endl;

    Roster* classRoster = new Roster();

    for (int i = 0; i <= 5; i++) { classRoster->parseArray(i); }


    cout << "Printing all students: ";
    cout << endl;
    classRoster->printAll();
    classRoster->printInvalidEmails();

    cout << "Printing average days in course for each student:" << endl;

    for (int i = 0; i < 5; i++) {
        classRoster->printAverageDaysInCourse(classRoster->classRosterArray[i]->getID());
    }

    cout << endl;
    classRoster->printByDegreeProgram(SOFTWARE);

    cout << endl;
    classRoster->remove("A3");

    cout << endl;
    cout << "Printing all students:\n";
    classRoster->printAll();
    classRoster->remove("A3");

    return 0;
}