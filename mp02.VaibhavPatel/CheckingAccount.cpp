/*    File: CheckingAccount.cpp
*    Name: Vaibhav Patel
* Revised: 9/23/2016
*  Course: CS240 - Introduction to Computing III
*
*    Desc: CheckingAccount.cpp file has an information about customers who have checking account.
*/
#include <iomanip>
#include <iostream>
#include <sstream>
#include "CheckingAccount.hpp"
#include <stdio.h>
#include <cstdlib>
using namespace std;

/* The ctor sets the owner by passing it to the parent class. Randomly
* generates the account number which always starts with a '9' and is
* followed by four randomly generated numbers in the range 0-9.
*
* Random generation is accomplished with the rand() function of the
* <stdio.h> library. This function returns a number in the range
* 0 - MAX_INT.
*/
CheckingAccount::CheckingAccount(const Customer& owner):Account(owner), accountNumber( 90000+(rand()%10000)) {}

int CheckingAccount::getAccountNumber() const { return accountNumber; }

/* Since the Account version is pure, this one will add the Account specific
* fields (dateOpened, owner) using the standard format we have been using.
* Refer to the screen capture for details.
*/
string CheckingAccount::toString() const {
	Customer owner = getOwner();
	ostringstream oss;
	oss <<"[" << getAccountNumber() << "]"
		<< "[" << getDateOpened() << "]"
		<< "[" << owner.getName() << "]"
		<<endl;
	return oss.str();
}