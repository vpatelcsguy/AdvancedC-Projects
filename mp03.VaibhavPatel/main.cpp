/*    File: main.cpp
*    Name: Vaibhav Patel
* Revised: 10/7/2016
*  Course: CS240 - Introduction to Computing III
*
*    Desc: main.cpp for testing ArrayList template and Name class.
*/


#include <iostream>
#include <sstream>

#include "ArrayList.hpp"
#include "Name.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
   ArrayList<Name> list;
   
   list.insert(Name("Johny", "Appleseed"));
   list.insert(Name("Tobby", "Appleseed"));
   list.insert(Name("Mary", "Appleseed"));
   
   list[0] = Name("John", "Smith");
   
   cout << "Original list: " << list << endl;
   
   Name name = list.get();
   
   cout << "First name: " << name << endl;
   
   cout  << "Is John Smith before Tobby Appleseed alphabetically? "
         << ( list.getAt(0) < list.getAt(1)? "Yes" : "No" )
         << endl
         << endl;
   
   ArrayList<Name> copyList(list);
   copyList[0] = Name("Mary", "Poppins");
   
   cout << "Copy list: " << copyList << endl << endl
         << "Original list: " << list << endl << endl;
   cin.get();
   return 0;
}// end main()
