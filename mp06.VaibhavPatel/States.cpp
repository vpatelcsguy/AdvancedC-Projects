/*    File: States.cpp
*    Name: Vaibhav Patel
* Revised: 11/19/2016
*  Course: CS240 - Introduction to Computing III
*
*/

#include "States.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;


/* Initializes the object with empty strings ("") and 0's. */
States::State::State(string abbreviation, string name, string capital,
                           int population, int area, int yearInducted, int orderInducted)
                     : abbreviation(abbreviation), name(name), capital(capital),
                       population(population), area(area), yearInducted(yearInducted), orderInducted(orderInducted)
{}// end State()
/*---------------------------------------------------------------------------------*/

/* Returns the state object formatted as follows:
 * Abbreviation, name and capital are left aligned, all others are right aligned. Each field should fit
 * in a column wide enough, to offer left or right alignment.
 *
 * <abbreviation><spc><name><spc><capital><spc><population><spc><area><spc><yearInducted><spc><orderInducted>
 */
string States::State::toString() const {
   ostringstream oss;
   int colSpace = 3;
   
   oss   << left
         << setw(12) << abbreviation
         << setw(colSpace) << " "
         << setw(14) << name
         << setw(colSpace) << " "
         << setw(14) << capital
         << setw(colSpace) << " "
         << right
         << setw(12) << population
         << setw(colSpace) << " "
         << setw(8) << area
         << setw(colSpace) << " "
         << setw(13) << yearInducted
         << setw(colSpace) << " "
         << setw(14) << orderInducted
         << endl;
   
   return oss.str();

}// end toString()
/*---------------------------------------------------------------------------------*/

/* Equality means each corresponding property is the same. */
bool States::State::operator == (const State& o) const { return toString() == o.toString(); }// end ==()
bool States::State::operator != (const State& o) const { return !(*this == o);              }// end !=()

/* Ordering is determined on first corresponding property pair that is different. */
bool States::State::operator <  (const State& o) const { return toString() < o.toString(); }// end <()
bool States::State::operator <= (const State& o) const { return !(*this > o);              }// end <=()
bool States::State::operator >  (const State& o) const { return o < *this;                 }// end >()
bool States::State::operator >= (const State& o) const { return !(*this < o);              }// end
/*---------------------------------------------------------------------------------*/


/* Reads from the specified file and loads the states linked list. The delimiter
 * identifies the character delimiting each field in the file.
 */
void States::loadFromFile(const string& filename, const char delimiter) {

   int index = 0;

   string population;
   string area;
   string year;
   string order;
   ifstream fin;

   if (!didConnectToFile(fin, filename)) {
   cerr << "Error: File could not be read." << endl;
   exit(1);
   }

   while (!fin.eof() && index <= 49) {
	    State * s = new State();
		getline(fin, s->abbreviation, delimiter);
		getline(fin, s->name, delimiter);
		getline(fin, s->capital, delimiter);
		getline(fin, population, delimiter);
		getline(fin, area, delimiter);
		getline(fin, year, delimiter);
		getline(fin, order, '\n');
		s->population = stoi(population);
		s->area = stoi(area);
		s->yearInducted = stoi(year);
		s->orderInducted = stoi(order);

		states.insertAt(index, s);
		index++;
   }


   fin.close();

}// loadFromFile()
/*----------------------------------------------------------------------------------*/

bool States::didConnectToFile(ifstream& fin, const string& filename) {
   fin.open(filename);
   
   return ( fin.is_open() );
}// end didConnectToFile()
/*----------------------------------------------------------------------------------*/

/* The constructor loads the linked list from the file, and builds the seven
 * binary search tree objects, by traversing the linked list only once.
 */
States::States(const string& filename, const char delimiter) {

	loadFromFile(filename, delimiter);
	int i = 0;
	while (i <= 49) {
		State * s = states.getAt(i);
		StateIndex<string> abb;
		abb.sortField = s->abbreviation;
		abb.state = s;
		abbreviationBst.insert(abb);

		StateIndex<string> name;
		name.sortField = s->name;
		name.state = s;
		nameBst.insert(name);

		StateIndex<string> cap;
		cap.sortField = s->capital;
		cap.state = s;
		capitalBst.insert(cap);

		StateIndex<int> pop;
		pop.sortField = s->population;
		pop.state = s;
		populationBst.insert(pop);

		StateIndex<int> area;
		area.sortField = s->area;
		area.state = s;
		areaBst.insert(area);

		StateIndex<int> year;
		year.sortField = s->yearInducted;
		year.state = s;
		yearInductedBst.insert(year);

		StateIndex<int> order;
		order.sortField = s->orderInducted;
		order.state = s;
		orderInductedBst.insert(order);

		i++;
	}
}//end States()
/*----------------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------------*/

/* Returns the state at the specified index. */
States::State * States::getAt(const int index) {
   return states.getAt(index);
}// end getAt()
/*----------------------------------------------------------------------------------*/

/* Returns a string with the current contents of the array formatted as follows:
 * Abbreviation<spc>Name<spc>Capital<spc>Population<spc>Area<spc>Year Inducted<spc>Order Inducted
 * ----------------------------------------------------------------------------------------------
 * <abbreviation><spc><name><spc><capital><spc><population><spc><area><spc><yearInducted><spc><orderInducted>
 * ...
 *
 * Note: the fields <abbreviation>,<name> and <capital> are left aligned, the others right aligned.
 */
string States::toString() const {
   ostringstream oss;
   int colSpace = 3;
   
   oss   << left
         << setw(12) << "Abbreviation"
         << setw(colSpace) << " "
         << setw(14) << "Name"
         << setw(colSpace) << " "
         << setw(14) << "Capital"
         << setw(colSpace) << " "
         << right
         << setw(12) << "Population"
         << setw(colSpace) << " "
         << setw(8) << "Area"
         << setw(colSpace) << " "
         << setw(13) << "Year Inducted"
         << setw(colSpace) << " "
         << setw(14) << "Order Inducted"
         << endl
         << setfill('-')
         << setw(105) << "-"
         << setfill(' ')
         << endl;
    oss << "[" << endl;
    for (int i = 0; i <= 49; i++) {
 	   oss << states.getAt(i);
      }
	oss << "]" << endl;
   
   return oss.str();
   
}// end toString()
/*----------------------------------------------------------------------------------*/

/* Equality means each corresponding state element is the same. */
bool States::operator == (const States& o) const {
	bool iter;
	int i = 0;
	while (iter = true) {
		iter = this->states[i] == o.states[i];
		i++;
	}
	return iter;
   
}// end ==()
/*----------------------------------------------------------------------------------*/

bool States::operator != (const States& o) const { return !(*this == o); }// end !=()
/*----------------------------------------------------------------------------------*/

/* Ordering is determined on first corresponding state pair that is different. */
bool States::operator <  (const States& o) const {
	bool iter;
	int i = 0;
	while (iter = true) {
		iter = this->states[i] < o.states[i];
		i++;
	}
	return iter;

}// end <()
/*----------------------------------------------------------------------------------*/

bool States::operator <= (const States& o) const { return !(*this > o); }// end <=()
bool States::operator >  (const States& o) const { return o < *this;    }// end >()
bool States::operator >= (const States& o) const { return !(*this < o); }// end >=()
/*----------------------------------------------------------------------------------*/

/* Methods that list the states in the specified order. Each method uses the corresponding
 * index tree to access the states in the linked list in order.
 */
void States::listByAbbreviation() const {
	abbreviationBst.inorder(display<string>);
}// end listByAbbreviation()

void States::listByName() const {
	nameBst.inorder(display<string>);
}// end listByName()

void States::listByCapital() const {
	capitalBst.inorder(display<string>);
}// end listByCapital()

void States::listByPopulation() const {
	populationBst.inorder(display<int>);
}// end listByPopulation()

void States::listByArea() const {
	areaBst.inorder(display<int>);
}// end listByArea()

void States::listByYearInducted() const {
	yearInductedBst.inorder(display<int>);
}// listByYearInducted()

void States::listByOrderInducted() const {
	orderInductedBst.inorder(display<int>);
}// end listByOrderInducted()
/*---------------------------------------------------------------------------------*/

ostream& operator <<(ostream& out, const States::State& o) {
   out << o.toString();
   
   return out;
}// end <<()
/*---------------------------------------------------------------------------------*/

ostream& operator <<(ostream& out, const States& o) {
   out << o.toString();
   
   return out;
}// end <<()
/*---------------------------------------------------------------------------------*/
