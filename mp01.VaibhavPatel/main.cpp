/*    File: main.cpp  
 *    Name: Vaibhav Patel  
 * Revised: 9/10/2016  
 *  Course: CS240 - Introduction to Computing III  
 *   
 *    Desc: main.cpp file implement functions to open a students.txt file, read, and output to screen.  
 */

#include "Student.hpp"
#include <iostream>
#include <fstream>

using namespace std;


// TODO:Implement these functions

/* Returns true if file was opened successfully, false otherwise. */
bool didConnectToInputFile(ifstream& fin, const string& filename);

/* Reads and returns the single student record read from the file stream. */
Student readStudentRecord(ifstream& fin);

/* Displays the student record to the screen. */
void displayStudentRecord(const Student& o);




int main() {
   // TODO: implement main().
   /* Read from the file the student record. Save the record in the variable studentRecord.
    * Display the student record to the screen.
    */

	ifstream fin;

	if (!didConnectToInputFile(fin, "students.txt")) {
		cerr << "Error: File was not opened." << endl;
		exit(1);
	}

	Student studentRecord = readStudentRecord(fin);
	fin.close();

	displayStudentRecord(studentRecord);
	cin.get();

	return 0;
}// end main()

bool didConnectToInputFile(ifstream& fin, const string& filename) {
	fin.open(filename);

	return fin.is_open();
}

Student readStudentRecord(ifstream& fin) {
	Name name;
	Address campusAddress;
	Address homeAddress;
	string major;
	string credit;
	Course courseTaken[100];
	int courseTakenCount = 0;

	getline(fin, name.first, ',');
	getline(fin, name.last, ',');

	getline(fin, campusAddress.address1, ',');
	getline(fin, campusAddress.address2, ',');
	getline(fin, campusAddress.city, ',');
	getline(fin, campusAddress.state, ',');
	getline(fin, campusAddress.zipcode, ',');
	
	getline(fin, homeAddress.address1, ',');
	getline(fin, homeAddress.address2, ',');
	getline(fin, homeAddress.city, ',');
	getline(fin, homeAddress.state, ',');
	getline(fin, homeAddress.zipcode, ',');
	
	getline(fin, major, '\n');
	
	Student studentRecord = Student(name, major, campusAddress);
	studentRecord.setHomeAddress(homeAddress);
	
	getline(fin, courseTaken[courseTakenCount].number, ',');
		while (!fin.eof()) {
			getline(fin, courseTaken[courseTakenCount].title, ',');
			getline(fin, credit, ',');
			getline(fin, courseTaken[courseTakenCount].grade, '\n');

			// when we run the program, the output shows courseCredit as 
			// exact number like 3 instead of 3.0. It looks like it converted
			// to integer but it did not. It is because 3.0 is exact number so
			// it is droping .0 and just showing 3 for the output. 
			// Although in the students.txt file if we change one of the gpa to
			// number like 3.9(number that is not exact), it will print 3.9 for output. 
			courseTaken[courseTakenCount].credits = stod(credit);
			
			studentRecord.addCourse(courseTaken[courseTakenCount]);
			
			courseTakenCount++;
			getline(fin, courseTaken[courseTakenCount].number, ',');
	}
	return studentRecord;

}
void displayStudentRecord(const Student& o) {
	cout << o.toString();
}
