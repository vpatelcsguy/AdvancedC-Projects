/*    File: Name.cpp
*    Name: Vaibhav Patel
* Revised: 10/7/2016
*  Course: CS240 - Introduction to Computing III
*
*    Desc: Implementation of Name Class.
*/


#include "Name.hpp"
#include <sstream>
#include <iostream>
using namespace std;

Name::Name(const string& first, const string& last) {
   setFirst(first);
   setLast(last);
}// end Name()

/* Destructor. No dynamic memory at this time, but just in
 * case we need it in the future.
 */
Name::~Name() {}// end ~Name()

string Name::getFirst() const { return first;              }// end getFirst()
string Name::getLast() const  { return last;               }// end getLast()
string Name::getName() const  { return first + " " + last; }// end getName()

/* Returns the name formatted as: last delimiter first.
 * This is used for sorting purposes.
 */
string Name::getSortedNameWithDelimiter(const string& delimiter) const { return last + delimiter + first; }// end getSortedNameWithDelimiter()

void Name::setFirst(const string& first) { this->first = first; }// end setFirst()
void Name::setLast(const string& last)   { this->last = last;   }// end setLast()

string Name::toString() const {
   ostringstream oss;
   
   oss << getName();
   
   return oss.str();
}// end toString()
 /* Equality and ordering are based on the sorted name. */
bool Name::operator == (const Name& o) const { return getSortedNameWithDelimiter(" ") == o.getSortedNameWithDelimiter(" "); }//end
bool Name::operator != (const Name& o) const { return getSortedNameWithDelimiter(" ") != o.getSortedNameWithDelimiter(" "); }//end
bool Name::operator <  (const Name& o) const { return getSortedNameWithDelimiter(" ") < o.getSortedNameWithDelimiter(" "); }//end
bool Name::operator <= (const Name& o) const { return getSortedNameWithDelimiter(" ") <= o.getSortedNameWithDelimiter(" "); }//end
bool Name::operator >  (const Name& o) const { return getSortedNameWithDelimiter(" ") > o.getSortedNameWithDelimiter(" "); }//end
bool Name::operator >= (const Name& o) const { return getSortedNameWithDelimiter(" ") >= o.getSortedNameWithDelimiter(" "); }//end

ostream& operator <<(ostream& out, const Name& o) {
	out << o.toString();

	return out;
}// end
