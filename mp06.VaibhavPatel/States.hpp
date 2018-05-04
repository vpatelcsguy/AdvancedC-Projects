/*    File: States.hpp
*    Name: Vaibhav Patel
* Revised: 11/19/2016
*  Course: CS240 - Introduction to Computing III
*
*/

#ifndef States_hpp
#define States_hpp

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "LinkedList.hpp"
#include "BinarySearchTree.h"

using namespace std;

/*---------------------------------------------------------------------------------
 * Class: States
 *
 * This class stores a linked list of State objects. The states are stored once in
 * the linked list, while seven binary search tree objects offer indexing into the data, one
 * per sort field.
 *---------------------------------------------------------------------------------*/
class States {
public:
   
   /*---------------------------------------------------------------------------------*/
   class State {
   public:
      string abbreviation;
      string name;
      string capital;
      int population;
      int area;
      int yearInducted;
      int orderInducted;
      
      /* Initializes the object. */
      State(string abbreviation = "", string name = "", string capital = "",
            int population = 0, int area = 0, int yearInducted = 0, int orderInducted = 0);
      
      /* Returns the state object formatted as follows:
       * Abbreviation, name and capital are left aligned, all others are right aligned. Each field should fit
       * in a column wide enough, to offer left or right alignment.
       *
       * <abbreviation><spc><name><spc><capital><spc><population><spc><area><spc><yearInducted><spc><orderInducted>
       */
      string toString() const;
      
      /* Equality means each corresponding property is the same. */
      virtual bool operator == (const State& o) const;
      virtual bool operator != (const State& o) const;
      
      /* Ordering is determined on first corresponding property pair that is different. */
      virtual bool operator <  (const State& o) const;
      virtual bool operator <= (const State& o) const;
      virtual bool operator >  (const State& o) const;
      virtual bool operator >= (const State& o) const;
      
   }; // end State
   /*---------------------------------------------------------------------------------*/
   
private:
   /* This class servers as the index used by the binary search tree objects. The class
    * has two members, the sort field and a pointer to the State data on the linked
    * list. It is a dictionary basically, with sortField being the key and state the
    * value.
    */
   template <typename K>
   class StateIndex {
   public:
      K sortField;
      State * state;
      
      StateIndex(K sortField = K(), State * state = nullptr) : sortField(sortField), state(state) {}// end StateIndex
      
      bool operator ==(const StateIndex<K>& o) const { return sortField == o.sortField; }
      bool operator !=(const StateIndex<K>& o) const { return !(*this == o);            }
      bool operator <(const StateIndex<K>& o)  const { return sortField < o.sortField;  }
      bool operator <=(const StateIndex<K>& o) const { return !(*this > o);             }
      bool operator >(const StateIndex<K>& o)  const { return o < *this;                }
      bool operator >=(const StateIndex<K>& o) const { return !( o < *this);            }
   }; // end StateIndex
   /*---------------------------------------------------------------------------------*/
   
   /* Reads from the specified file and loads the states linked list. The delimiter
    * identifies the character delimiting each field in the file.
    */
   void loadFromFile(const string& filename, const char delimiter);

   
   /* Returns true is connection is open. */
   bool didConnectToFile(ifstream& fin, const string& filename);
   
   
   /* The property representing the 50 states. */
   LinkedList<State> states;
   
   /* The seven binary search trees, one for each of the seven search fields. These trees
    * will offer an index into the linked list of State objects.
    */
   BinarySearchTree<States::StateIndex<string>>  abbreviationBst;
   BinarySearchTree<States::StateIndex<string>>  nameBst;
   BinarySearchTree<States::StateIndex<string>>  capitalBst;
   
   BinarySearchTree<States::StateIndex<int>>  populationBst;
   BinarySearchTree<States::StateIndex<int>>  areaBst;
   BinarySearchTree<States::StateIndex<int>>  yearInductedBst;
   BinarySearchTree<States::StateIndex<int>>  orderInductedBst;
   /*---------------------------------------------------------------------------------*/
   
   /* The display method to be used for displaying the contents of the linked list. 
    * The method is passed the StateIndex object which contains the key (a field value)
    * and the address of the State in the linked list. It displays the State to the screen.
    */
   template <typename K>
   static void display(StateIndex<K>& e) {
	   cout << endl;
	   cout << *e.state;
   }

   /*---------------------------------------------------------------------------------*/
   
public:
   /* The constructor loads the linked list from the file, and builds the seven
    * binary search tree objects, by traversing the linked list only once.
    */
   States(const string& filename, const char delimiter);
   
   
   /* Returns the state at the specified index. */
   State * getAt(const int index);
   
   
   /* Returns a string will current contents of the array formatted as follows:
    * Abbreviation<spc>Name<spc>Capital<spc>Population<spc>Area<spc>Year Inducted<spc>Order Inducted
    * ----------------------------------------------------------------------------------------------
    * <abbreviation><spc><name><spc><capital><spc><population><spc><area><spc><yearInducted><spc><orderInducted>
    * ...
    *
    * Note: the fields <abbreviation>,<name> and <capital> are left aligned, the others right aligned.
    */
   string toString() const;
   /*----------------------------------------------------------------------------------*/
   
   /* Equality means each corresponding state element is the same. */
   virtual bool operator == (const States& o) const;
   virtual bool operator != (const States& o) const;
   
   /* Ordering is determined on first corresponding state pair that is different. */
   virtual bool operator <  (const States& o) const;
   virtual bool operator <= (const States& o) const;
   virtual bool operator >  (const States& o) const;
   virtual bool operator >= (const States& o) const;
   /*----------------------------------------------------------------------------------*/
   
   /* Methods that list the states in the specified order. Each method uses the corresponding
    * index tree to access the states in the linked list in order.
    */
   virtual void listByAbbreviation() const;
   virtual void listByName() const;
   virtual void listByCapital() const;
   virtual void listByPopulation() const;
   virtual void listByArea() const;
   virtual void listByYearInducted() const;
   virtual void listByOrderInducted() const;

};

ostream& operator <<(ostream& out, const States::State& o);

/* Calls the toString() method of the parameter object o. */
ostream& operator <<(ostream& out, const States& o);

#endif /* States_hpp */
