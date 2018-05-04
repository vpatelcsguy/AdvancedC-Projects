/*    File: Account.cpp
*    Name: Vaibhav Patel
* Revised: 9/23/2016
*  Course: CS240 - Introduction to Computing III
*
*    Desc: Account.cpp file is a superclass of checking account. (also super class of saving account in future).
*/
#include <iomanip>
#include <iostream>
#include <sstream>
#include "Account.hpp"
#include "Date.hpp"
using namespace std;
/* The ctor assigns the owner and sets the date to the current
* date. You will use the Date() class for this.
*/
Account::Account(const Customer& owner): owner(owner){
	Date date = Date();
	dateOpened = date.toString();
}

/* The dtor does nothing for the Account. However, since the class is abstract it
* must be virtual so subclass objects can be deleted automatically.
*/
Account::~Account() {}

string Account::getDateOpened() const { return dateOpened; }
Customer Account::getOwner() const { return owner; }

/* Do not provide an implementation in Account. This is a true abstract method. */
