/*    File: main.cpp
*    Name: Vaibhav Patel
* Revised: 9/23/2016
*  Course: CS240 - Introduction to Computing III
*
*    Desc: main.cpp file opens a new account for customers, display checking accounts, and display customers.
*/

#include "Customer.hpp"
#include "CheckingAccount.hpp"
#include "Bank.hpp"
#include <iostream>

using namespace std;

int main() {
   Bank bank;

   /* Open three accounts to the Bank. */
   bank.openAccount(new CheckingAccount(Customer("Adam", "Apple")));
   bank.openAccount(new CheckingAccount(Customer("Beatrice", "Bagel")));
   bank.openAccount(new CheckingAccount(Customer("Chris", "Cucumber")));

   cout << "Customer list:" << endl;
   bank.listCustomers(cout);
   cout << endl;
   
   cout << "Account list:" << endl;
   bank.listAccounts(cout);
   cout << endl;
   
   cout << "Bank record:" << endl;
   cout << bank.toString() << endl;
   cin.get();
   return 0;
}// end main()
