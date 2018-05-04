/*    File: Bank.hpp
*    Name: Vaibhav Patel
* Revised: 9/23/2016
*  Course: CS240 - Introduction to Computing III
*
*    Desc: Bank.hpp file is a interface file.
*/
#ifndef __cppProject__Bank__
#define __cppProject__Bank__

#include "Customer.hpp"
#include "Account.hpp"
#include <iostream>
#include <string>

using namespace std;

const int MAX_ACCOUNTS = 200;

class Bank {
private:
   /* Here we are using polymorphic coding. The array is of pointers to Account,
    * but each element will be of a subclass. In this version just CheckingAccount
    * objects.
    */
   Account * accounts[MAX_ACCOUNTS];
   int accountCount;
   
public:
   /* ctor initializes the accountCount to 0 and each array element to nullptr. */
   Bank();
   
   /* Releases the objects pointed to by each element and sets the accountCount to 0.
    * Not every element will have an object, so account for that in your code.
    */
   virtual ~Bank();
   
   /* Returns the customer stored in the CheckingAccount object at the specified index. */
   virtual Customer getCustomerAtIndex(const int index) const final;
   
   /* Returns the CheckingAccount object at the specified index. */
   virtual Account * getAccountAtIndex(const int index) const final;
   
   virtual int getAccountCount() const final;
   
   /* Opens the CheckingAccount. This means adding the object to the end of the array. Recall,
    * that the array holds pointers to Account (superclass), but the elements will all be of
    * a subclass type (CheckingAccount here).
    *
    * Now, when you call this method in main(), make sure that the dynamic object you create there
    * is not released in main(). The Bank should own those objects, and will release them in the
    * dtor. Best way to do that is to created the dynamic anonymous object inside the argument list.
    */
   virtual void openAccount(Account* const o);
   
   /* Lists the customer portion of the Account objects. */
   virtual void listCustomers(ostream& out = cout);
   
   /* Lists the Account in its entirety. */
   virtual void listAccounts(ostream& out = cout);
   
   /* This time the string is formatted differently. You just list the accounts, not the
    * customers and then the accounts like last time. Refer to the screen capture for this.
    */
   virtual string toString() const;
};

#endif /* defined(__cppProject__Bank__) */
