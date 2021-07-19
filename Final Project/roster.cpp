#pragma once

#include <sstream>
#include <string>
#include <iostream>

#include "roster.h"
#include "student.h"
#include "degree.h"


Roster::Roster() { classRosterArray = new Student * [5]; };

Roster::~Roster() { delete[] classRosterArray; };


void Roster::printDegreeString(int dp) {
	switch (dp) {
	case 0:
		std::cout << "SECURITY";
		break;
	case 1:
		std::cout << "NETWORK";
		break;
	case 2:
		std::cout << "SOFTWARE";
		break;
	default:
		std::cout << "INVALID";
		break;
	}
}


void Roster::add(int index, std::string a, std::string b, std::string c, std::string d, std::string e, int f, int g, int h, DegreeProgram z) {
	const int indexConst = index;
	Student* xstudent = new Student();

	xstudent->setID(a);
	xstudent->setFirstName(b);
	xstudent->setLastName(c);
	xstudent->setEmailAddress(d);
	xstudent->setAge(e);
	xstudent->setDays(f, g, h);
	xstudent->setDegreeProgram(z);

	classRosterArray[indexConst] = xstudent;
}

void Roster::remove(std::string stID) {
	bool indexFound = false;
	int indexNum = 0;

	std::cout << "Searching for student by ID: " << stID;

	for (int i = 0; i < 5; i++) {
		if (this->classRosterArray[i]->getID() == stID) {
			indexNum = i;
			indexFound = true;
			std::cout << ".";
			break;
		}
		else {
			indexFound = false;
			std::cout << ".";
			continue;
		}
	}
	std::cout << std::endl;

	if (indexFound) {
		std::cout << "Student found.  Removing student from roster.";
		const int indexConst = indexNum;
		Student* xstudent = new Student();


		xstudent->setID("NUL");
		std::cout << ".";
		xstudent->setFirstName("");
		std::cout << ".";
		xstudent->setLastName("");
		std::cout << ".";
		xstudent->setEmailAddress("");
		std::cout << ".";
		xstudent->setAge("");
		std::cout << ".";
		xstudent->setDays(0, 0, 0);
		std::cout << ".";
		xstudent->setDegreeProgram(INVALID);
		std::cout << ".";

		classRosterArray[indexConst] = xstudent;

		std::cout << "DONE";
	}

	else {
		std::cout << "Student " << stID << " not found.";
	}
	std::cout << std::endl;
}

void Roster::parseArray(int rosterIndex) {

	std::string studentDataString = studentData[rosterIndex];
	int stringLength = studentDataString.length();

	std::string studentID = "";
	std::string firstName = "";
	std::string lastName = "";
	std::string email = "";
	std::string age = "";
	std::string stringdays0 = ""; 
	std::string stringdays1 = ""; 
	std::string stringdays2 = ""; 
	int days0 = 0; 
	int days1 = 0; 
	int days2 = 0; 
	std::string degreeProgramString = "";
	DegreeProgram studentDegree; 

	int i = 0;

	int commasSkipped = 0;

	for (i = 0; i < stringLength; i++) {
		char s = studentDataString.at(i);
		if (s != ',') {
			switch (commasSkipped) {
			case 0:
				studentID.push_back(s);
				break;
			case 1:
				firstName.push_back(s);
				break;
			case 2:
				lastName.push_back(s);
				break;
			case 3:
				email.push_back(s);
				break;
			case 4:
				age.push_back(s);
				break;
			case 5:
				stringdays0.push_back(s);
				break;
			case 6:
				stringdays1.push_back(s);
				break;
			case 7:
				stringdays2.push_back(s);
				break;
			case 8:
				degreeProgramString.push_back(s);
				break;
			default:
				break;
			}
		}

		else {
			commasSkipped = commasSkipped + 1;
		}
	}

	std::stringstream daysConvert0(stringdays0);
	std::stringstream daysConvert1(stringdays1);
	std::stringstream daysConvert2(stringdays2);
	daysConvert0 >> days0;
	daysConvert1 >> days1;
	daysConvert2 >> days2;


	if (degreeProgramString == "SECURITY") {
		studentDegree = SECURITY;
	}
	else if (degreeProgramString == "NETWORK") {
		studentDegree = NETWORK;
	}
	else if (degreeProgramString == "SOFTWARE") {
		studentDegree = SOFTWARE;
	}
	else {
		studentDegree = INVALID;
	}

	add(rosterIndex, studentID, firstName, lastName, email, age, days0, days1, days2, studentDegree);
}

void Roster::printAll() {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->getID() != "NUL") {
			classRosterArray[i]->print(0);
			std::cout << "	";
			std::cout << "First name: ";
			classRosterArray[i]->print(1);
			std::cout << "	";
			std::cout << "Last name:";
			classRosterArray[i]->print(2);
			std::cout << "	";
			std::cout << "Age: ";
			classRosterArray[i]->print(4);
			std::cout << "	";
			std::cout << "Days In Course: {";
			classRosterArray[i]->print(5);
			std::cout << ",";
			classRosterArray[i]->print(6);
			std::cout << ",";
			classRosterArray[i]->print(7);
			std::cout << "}";
			std::cout << "Degree program: ";

			printDegreeString(classRosterArray[i]->getDegreeProgram());
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}

void Roster::printAverageDaysInCourse(std::string stID) {
	int average;
	int daysA;
	int daysB;
	int daysC;


	bool indexFound = false;
	int indexNum = 0;

	for (int i = 0; i <= 5; i++) {
		if (this->classRosterArray[i]->getID() == stID) {
			indexNum = i;
			indexFound = true;
			break;
		}
		else {
			indexFound = false;
			continue;
		}
	}

	if (indexFound) {
		daysA = this->classRosterArray[indexNum]->getDays(0);
		daysB = this->classRosterArray[indexNum]->getDays(1);
		daysC = this->classRosterArray[indexNum]->getDays(2);

		average = ((daysA + daysB + daysC) / 3);

		std::cout << "Average of days in course for student " << stID << ": " << average;
		std::cout << std::endl;

	}

	else {
		std::cout << "Student " << stID << " was not found.";
		std::cout << std::endl;
	}
}

void Roster::printInvalidEmails() {
	std::cout << "Printing invalid emails: " << std::endl;


	for (int i = 0; i < 5; i++) {
		std::string emailStr = classRosterArray[i]->getEmailAddress();
		if ((emailStr.find('@') != std::string::npos) && emailStr.find('.') != std::string::npos) {
			if (emailStr.find(' ') != std::string::npos) {
				std::cout << emailStr;
				std::cout << std::endl;
			}
		}
		else {
			std::cout << emailStr;
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeprogram) {

	std::cout << "Printing students by degree program ";
	printDegreeString(degreeprogram);
	std::cout << ":" << std::endl;
	for (int i = 0; i < 5; i++) {

		if (classRosterArray[i]->getDegreeProgram() == degreeprogram) {
			if (classRosterArray[i]->getID() != "NUL") {
				classRosterArray[i]->print(0);
				std::cout << "	";
				std::cout << "First name: ";
				classRosterArray[i]->print(1);
				std::cout << "	";
				std::cout << "Last name:";
				classRosterArray[i]->print(2);
				std::cout << "	";
				std::cout << "Age: ";
				classRosterArray[i]->print(4);
				std::cout << "	";
				std::cout << "Days In Course: {";
				classRosterArray[i]->print(5);
				std::cout << ",";
				classRosterArray[i]->print(6);
				std::cout << ",";
				classRosterArray[i]->print(7);
				std::cout << "}";
				std::cout << "Degree program: ";

				printDegreeString(classRosterArray[i]->getDegreeProgram());
				std::cout << std::endl;
			}
		}
	}
}