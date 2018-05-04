/*    File: Name.hpp
*    Name: Vaibhav Patel
* Revised: 10/7/2016
*  Course: CS240 - Introduction to Computing III
*
*    Desc: Interface file of Name.cpp
*/


#ifndef Name_hpp
#define Name_hpp

#include <string>
using namespace std;

class Name {
private:
   string first;
   string last;
   
public:
   Name(const string& first = "", const string& last = "");
   
   /* Destructor. No dynamic memory at this time, but just in
    * case we need it in the future.
    */
   virtual ~Name();
   
   virtual string getFirst() const final;
   virtual string getLast() const final;
   virtual string getName() const final;
   
   /* Returns the name formatted as: <last><delimiter><first>.
    * This is used for sorting purposes.
    */
   virtual string getSortedNameWithDelimiter(const string& delimiter) const final;
   
   virtual void setFirst(const string& first) final;
   virtual void setLast(const string& last) final;
   
   virtual string toString() const;
   
   /* The sorted name is used for all comparisons */
   virtual bool operator == (const Name& o) const;
   virtual bool operator != (const Name& o) const;
   virtual bool operator <  (const Name& o) const;
   virtual bool operator <= (const Name& o) const;
   virtual bool operator >  (const Name& o) const;
   virtual bool operator >= (const Name& o) const;
};

/* This operator function simply calls the toString(). */
ostream& operator <<(ostream& out, const Name& name);

#endif /* Name_hpp */
