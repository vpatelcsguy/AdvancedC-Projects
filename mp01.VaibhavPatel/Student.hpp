/*    File: Student.cpp
*    Name: Vaibhav Patel
*  Course: CS240 - Introduction to Computing III
*
*    Desc: File provided by  instructor.
*/
//  Created by Socratis Tornaritis on 8/29/16.
//  Copyright © 2016 SIUE. All rights reserved.

#ifndef Student_hpp
#define Student_hpp

#include <string>
using namespace std;


/*-----------------------------------------------------------------------------
 * struct: Name
 * Represents a name
 *---------------------------------------------------------------------------*/
struct Name {
   string first;
   string last;
};

/*-----------------------------------------------------------------------------
 * struct: Address
 * Represents an address
 *---------------------------------------------------------------------------*/
struct Address {
   string address1;
   string address2;
   string city;
   string state;
   string zipcode;
};

/*-----------------------------------------------------------------------------
 * struct: Course
 * Represents a course
 *---------------------------------------------------------------------------*/
struct Course {
   string number;
   string title;
   double credits;
   string grade;
};


/*-----------------------------------------------------------------------------
 * class: Student
 * Represents a student
 *---------------------------------------------------------------------------*/
class Student {
private:
   Name name;
   Address campusAddress;
   Address homeAddress;
   string major;
   Course courseTaken[100];
   int coursesTakenCount;
   
public:
   Student(const Name& name, const string& major, const Address& campusAddress);
   
   Name getName() const;
   Address getCampusAddress() const;
   Address getHomeAddress() const;
   string getMajor() const;
   
   /* Assume index is valid (0 <= index <= coursesTakenCount - 1) */
   Course getCourse(const int index) const;
   int getCoursesTakenCount() const;
   
   
   void setName(const Name& name);
   void setCampusAddress(const Address& campusAddress);
   void setHomeAddress(const Address& homeAddress);
   void setMajor(const string& major);
   
   string toString() const;
   
   /* Adds the course to the end of the array. */
   void addCourse(const Course& course);
   
   /* Returns the gpa of all the courses taken. */
   double getCumulativeGpa() const;
};

#endif /* Student_hpp */
