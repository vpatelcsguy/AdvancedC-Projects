/*    File: Bank.cpp
*    Name: Vaibhav Patel
* Revised: 9/23/2016
*  Course: CS240 - Introduction to Computing III
*
*    Desc: Bank.cpp file has all information about customers and accounts.
*/
#include <iomanip>
#include <iostream>
#include <sstream>
#include "Bank.hpp"
using namespace std;

/* ctor initializes the accountCount to 0 and each array element to nullptr. */
Bank::Bank():accountCount(0), accounts() {}

/* Releases the objects pointed to by each element and sets the accountCount to 0.
* Not every element will have an object, so account for that in your code.
*/
Bank::~Bank() {
	for (int i = 0; i < accountCount; i++) {
		delete accounts[i];
		accounts[i] = nullptr;
	}
	accountCount = 0;
}

/* Returns the customer stored in the CheckingAccount object at the specified index. */
Customer Bank::getCustomerAtIndex(const int index) const{
	return accounts[index]->getOwner();
}

/* Returns the CheckingAccount object at the specified index. */
Account * Bank::getAccountAtIndex(const int index) const {
		return accounts[index];

}

int Bank::getAccountCount() const { return accountCount; }

/* Opens the CheckingAccount. This means adding the object to the end of the array. Recall,
* that the array holds pointers to Account (superclass), but the elements will all be of
* a subclass type (CheckingAccount here).
*
* Now, when you call this method in main(), make sure that the dynamic object you create there
* is not released in main(). The Bank should own those objects, and will release them in the
* dtor. Best way to do that is to created the dynamic anonymous object inside the argument list.
*/
void Bank::openAccount(Account* const o) {
	accounts[accountCount] = o;
	accountCount++;
	
}

/* Lists the customer portion of the Account objects. */
void Bank::listCustomers(ostream& out) {
	for (int i = 0; i < accountCount; i++) {
		Customer owner = getCustomerAtIndex(i);

		out << "\t" <<owner.getName() << endl;
	}
}

/* Lists the Account in its entirety. */
void Bank::listAccounts(ostream& out) {
	for (int i = 0; i < accountCount; i++) {
		out << "\t"<<accounts[i]->toString();
	}
}

/* This time the string is formatted differently. You just list the accounts, not the
* customers and then the accounts like last time. Refer to the screen capture for this.
*/
string Bank::toString() const { 
	ostringstream oss;
	oss << "Count: " << getAccountCount()<<endl;
	for (int i = 0; i < accountCount; i++) {
		oss << "\t(" << (i+1) << ")";
		oss << accounts[i]->toString();
	}
	return oss.str();
}