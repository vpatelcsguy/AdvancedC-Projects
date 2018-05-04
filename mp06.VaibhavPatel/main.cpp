/*    File: main.cpp
*    Name: Vaibhav Patel
* Revised: 11/19/2016
*  Course: CS240 - Introduction to Computing III
*
*/

#include "States.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;


/*--------------------------------------------------------------------------------------------------*/
int main() {
   States states("states.txt", ',');

   
   char key;
   
   cout << "Choose option [A]bbreviation, [N]ame, [C]apital, [P]opulation, A[r]ea, [Y]ear Inducted, [O]rder Inducted, [Q]uit: ";
   cin >> key;
   key = toupper(key);
   
   while (key != 'Q') {
      switch (key) {
         case 'A':   states.listByAbbreviation();  break;
         case 'N':   states.listByName();          break;
         case 'C':   states.listByCapital();       break;
         case 'P':   states.listByPopulation();    break;
         case 'R':   states.listByArea();          break;
         case 'Y':   states.listByYearInducted();  break;
         case 'O':   states.listByOrderInducted(); break;
      }
      
      cout << endl << endl;
      cout << "Choose option [A]bbreviation, [N]ame, [C]apital, [P]opulation, A[r]ea, [Y]ear Inducted, [O]rder Inducted, [Q]uit: ";
      cin >> key;
      key = toupper(key);
   }
   
   cout << "Program ended successfully." << endl << endl;
   return 0;
}// end main()
