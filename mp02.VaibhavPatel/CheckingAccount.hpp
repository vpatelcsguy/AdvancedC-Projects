/*    File: CheckingAccount.hpp
*    Name: Vaibhav Patel
* Revised: 9/23/2016
*  Course: CS240 - Introduction to Computing III
*
*    Desc: CheckingAccount.hpp file is a interface file.
*/
#ifndef __cppProject__CheckingAccount__
#define __cppProject__CheckingAccount__

#include "Customer.hpp"
#include "Account.hpp"
#include <string>

using namespace std;


class CheckingAccount : public Account {
private:
   int accountNumber;   // 9nnnn - n randomly generated (0-9)
   
public:
   /* The ctor sets the owner by passing it to the parent class. Randomly
    * generates the account number which always starts with a '9' and is
    * followed by four randomly generated numbers in the range 0-9.
    *
    * Random generation is accomplished with the rand() function of the
    * <stdio.h> library. This function returns a number in the range
    * 0 - MAX_INT.
    */
   CheckingAccount(const Customer& owner);
   
   virtual int getAccountNumber() const final;
   
   /* Since the Account version is pure, this one will add the Account specific
    * fields (dateOpened, owner) using the standard format we have been using.
    * Refer to the screen capture for details.
    */
   virtual string toString() const;
};
#endif /* defined(__cppProject__CheckingAccount__) */
