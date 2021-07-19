#pragma once

#include <string>
#include "student.h"

const std::string studentData[5] = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Robert,Trudell,rtrude1@wgu.edu,27,10,20,30,SOFTWARE"
};

class Roster {
public:
    Roster();

    ~Roster();

    Student** classRosterArray;

    void add(int index, std::string a, std::string b, std::string c, std::string d, std::string e, int f, int g, int h, DegreeProgram z);

    void remove(std::string stID);

    void parseArray(int rosterIndex);

    void printAll();

    void printAverageDaysInCourse(std::string stID);

    void printInvalidEmails();

    void printByDegreeProgram(DegreeProgram degreeprogram);

private:

    void printDegreeString(int dp);
};
