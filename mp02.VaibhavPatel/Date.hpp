/*    File: Date.hpp
*    Name: Vaibhav Patel
* Revised: 9/23/2016
*  Course: CS240 - Introduction to Computing III
*
*    Desc: Date.hpp file is a interface file.
*/
#ifndef __cppProject__Date__
#define __cppProject__Date__


#include <string>

using namespace std;

class Date {
private:
   int year;
   int month;
   int day;
   int hour;
   int min;
   int sec;
   
public:
   Date();
   virtual ~Date();
   virtual string toString() const;
};

#endif /* defined(__cppProject__Date__) */
