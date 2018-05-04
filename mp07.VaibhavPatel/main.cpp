//
//  main.cpp
//  StudentTest
//
//  Created by Socratis Tornaritis on 11/16/16.
//  Copyright © 2016 SIUE. All rights reserved.
//

//#include "Dictionary.hpp"
#include "Heap.hpp"
#include "State.hpp"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;


/* Loads the states heap from the file. */
void loadFromFile(Heap<State>& states, const string& filename);
bool didConnectToFile(ifstream& fin, const string& filename);




int main() {
   Heap<State> states;
   
   /* Load the data into the heap. */
   loadFromFile(states, "perm15K.txt");
   
   /* List the original heap. */
   cout  << "Original heap:"
         << endl
         << states
         << endl;
   
   /* Sort the heap. */
   states.sort();
   
   /* List the sorted heap. */
   cout  << "Sorted heap:"
         << endl
         << states
         << endl;
   cin.get();
   return 0;
}// end main()

/* Reads from the specified file and loads the states linked list. The delimiter
 * identifies the character delimiting each field in the file.
 */
void loadFromFile(Heap<State>& states, const string& filename) {
   ifstream fin;
   
   if ( !didConnectToFile(fin, filename) ) {
      cerr << "Error: Unable to open file." << endl;
      exit(1);
   }
   
   string abbreviation;
   
   getline(fin, abbreviation);
   while ( !fin.eof() ) {
      
      
      /* Insert into the heap at this point */
      states.insert( State(abbreviation));
      
      getline(fin, abbreviation);
   }
   
   fin.close();
   
}// loadFromFile()
/*----------------------------------------------------------------------------------*/

/* Returns true if file was connected to. */
bool didConnectToFile(ifstream& fin, const string& filename) {
   fin.open(filename);
   
   return ( fin.is_open() );
}// end didConnectToFile()
/*----------------------------------------------------------------------------------*/

