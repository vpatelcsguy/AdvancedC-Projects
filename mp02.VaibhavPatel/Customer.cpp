/*    File: Customer.cpp
*    Name: Vaibhav Patel
* Revised: 9/23/2016
*  Course: CS240 - Introduction to Computing III
*
*    Desc: Customer.cpp file has information about customers.
*/
#include <iomanip>
#include <iostream>
#include <sstream>
#include "Customer.hpp"
using namespace std;

/* ctor initializes the object. */
Customer::Customer(const string& first, const string& last) : first(first), last(last){}
string Customer::getFirst() const { return first; }
string Customer::getLast() const { return last; }
string Customer::getName() const { return last + ", " + first; }

void Customer::setFirst(const string& first) { this->first = first; }
void Customer::setLast(const string& last) { this->last = last; }

/* Returns the customer formatted as shown in the screen capture. */
string Customer::toString() const {
	ostringstream oss;
	oss << getName();
	return oss.str();
}