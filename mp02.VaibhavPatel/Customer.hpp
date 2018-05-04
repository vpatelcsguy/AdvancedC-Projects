/*    File: Customer.hpp
*    Name: Vaibhav Patel
* Revised: 9/23/2016
*  Course: CS240 - Introduction to Computing III
*
*    Desc: Customer.hpp file is a interface file.
*/
#ifndef __cppProject__Customer__
#define __cppProject__Customer__


#include <string>
using namespace std;

class Customer {
private:
   string first;
   string last;
   
public:
   /* ctor initializes the object. */
   Customer(const string& first = "na", const string& last="na");
   
   virtual string getFirst() const final;
   virtual string getLast() const final;
   virtual string getName() const final;
   
   virtual void setFirst(const string& first) final;
   virtual void setLast(const string& last) final;
   
   /* Returns the customer formatted as shown in the screen capture. */
   virtual string toString() const;
};

#endif /* defined(__cppProject__Customer__) */
