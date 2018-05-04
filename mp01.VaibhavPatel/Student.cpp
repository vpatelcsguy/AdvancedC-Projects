/*    File: Student.cpp
*    Name: Vaibhav Patel
* Revised: 9/10/2016
*  Course: CS240 - Introduction to Computing III
*
*    Desc: Student.cpp file implements the Student.hpp interface.
*/

#include <iomanip>
#include <iostream>
#include <sstream>
#include "Student.hpp"
using namespace std;



Student::Student(const Name& name, const string& major, const Address& campusAddress){
	setName(name);
	setMajor(major);
	setCampusAddress(campusAddress);
	coursesTakenCount = 0;
}

Name Student::getName() const { return name; }
Address Student::getCampusAddress() const { return campusAddress; }
Address Student::getHomeAddress() const { return homeAddress;  }
string Student::getMajor() const { return major; }

/* Assume index is valid (0 <= index <= coursesTakenCount - 1) */
Course Student::getCourse(const int index) const { return courseTaken[index]; }
int Student::getCoursesTakenCount() const { return coursesTakenCount; }


void Student::setName(const Name& name) { this->name = name; }
void Student::setCampusAddress(const Address& campusAddress) { this->campusAddress = campusAddress; }
void Student::setHomeAddress(const Address& homeAddress) { this->homeAddress = homeAddress; }
void Student::setMajor(const string& major) { this->major = major; }

string Student::toString() const {
	ostringstream oss;
	double gpa = getCumulativeGpa();
	oss << "Name: " << name.last << ", " << name.first << endl

		<< "Campus address:" << endl
		<< "\t" << getCampusAddress().address1 << endl
		<< "\t" << getCampusAddress().address2 << endl
		<< "\t" << getCampusAddress().city << ", "
		        << getCampusAddress().state << " "
		        << getCampusAddress().zipcode << endl

		<< "Home address:" << endl
		<< "\t" << getHomeAddress().address1 << endl
		<< "\t" << getHomeAddress().city << ", "
		        << getHomeAddress().state << " "
		        << getHomeAddress().zipcode << endl

		<< "Major: " << getMajor() << endl

	    << "Course taken:" << endl;
		for (int index = 0; index <= coursesTakenCount - 1; index++) {
			oss << "\t" << "[" << index + 1 << "] "
			    << getCourse(index).number << "-"
				<< getCourse(index).title << ", "
				<< getCourse(index).credits << ": "
				<< getCourse(index).grade  << endl;
		}
		oss << "Cummulatice GPA: " << setprecision(3) << getCumulativeGpa();
		return oss.str();
}

/* Adds the course to the end of the array. */
void Student::addCourse(const Course& course) { 
	courseTaken[coursesTakenCount] = course;
	coursesTakenCount++;
}

/* Returns the gpa of all the courses taken. */
double Student::getCumulativeGpa() const {
	double qualityPoints = 0.0;
	double totalCreditHours = 0.0;
	double creditHours;
	double weight;
	double gradeWeight[6] = { 4.0, 3.0, 2.0, 1.0, 0.0, 0.0 };

	for (int index = 0; index <= coursesTakenCount - 1; index ++) {

		weight = gradeWeight[getCourse(index).grade[0] - 'A'];
		creditHours = getCourse(index).credits;

		qualityPoints += weight * creditHours;
		totalCreditHours += creditHours;
	}
	double gpa = (totalCreditHours == 0) ? 0.0 : qualityPoints / totalCreditHours;
	return gpa;
}