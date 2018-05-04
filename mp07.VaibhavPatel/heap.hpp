/*    File: heap.hpp
*    Name: Vaibhav Patel
* Revised: 11/19/2016
*  Course: CS240 - Introduction to Computing III
*
*/


#ifndef Heap_hpp
#define Heap_hpp

#include <iostream>
#include <string>
#include <sstream>

using namespace std;


/* We are going to implement this Heap very specifically to only handle the 50 States.
 * Normally, this is not a good idea, since it limits the use of the heap, but let's
 * not worry about that little detail this time around.
 *
 * Better solution: A better implementation would be to make the items a dynamic
 * array, its size based on the number of nodes the Heap is to handle.
 */
const int HEAP_SIZE = 15000;


/* Class: Heap
 * Use the implementation algorithm shown in the notes.
 * The Heap class represents a Heap, offering sorting capability.
 */
template <typename E>
class Heap {
private:
   E items[HEAP_SIZE];
   int size;
   /*---------------------------------------------------------------------------------*/
   
   /* Rebuilds the heap. */
   void rebuild(int rootIndex, const int n) {
      // TODO: implement
	   if ((((rootIndex * 2) + 1) <= (n-1))) {
		   int max = 2 * rootIndex + 1;
		   if (((2 * rootIndex) + 2) <= (n-1)) {
			   if (items[max + 1] > items[max]) {
				  max =  max + 1;
			   }
			   else { max = max;
			   }
		   }
		   if (items[rootIndex] < items[max]) {
			   E t;
			   t = items[rootIndex];
			   items[rootIndex] = items[max];
			   items[max] = t;
			   rebuild(max, n);
		   }
	   }
      
   } // end rebuild()
   /*---------------------------------------------------------------------------------*/
   
   public:
   
   /* Sets the size to 0. */
   Heap()
   {
	   size = 0;
   } // end Heap()
   
   /* Does nothing this time. */
   virtual ~Heap() {} // end ~Heap()
   
   /* Returns true if the heap is empty. */
   virtual bool isEmpty() const {
      // TODO: implement
	   if (size == 0) { return true; }
	   else { return false; }
   } // end isEmpty()
   /*---------------------------------------------------------------------------------*/
   
   /* Inserts the object to the heap and reinstates the hep.
    * If the array is full, give the message "Heap is full. Object not added.", but do
    * not exit the program.
    */
   virtual void insert(const E& o) {
      // TODO: implement
	   if (size == (HEAP_SIZE)) {
		   cout << "\nHeap is full. Object not added\n";
	   }
	   else {
		   items[size] = o;
		   int child = size;
		   int parent = (child - 1) / 2;
		   while ((parent >= 0) && (items[child] > items[parent])) {
			   E temp;
			   temp = items[child];
			   items[child] = items[parent];
			   items[parent] = temp;
			   child = parent;
			   parent = (child - 1) / 2;
		   }
		   size++;
	   }
   } // end insert()
   /*---------------------------------------------------------------------------------*/
   
   /* Removes the object from the heap and rebuilds the heap. 
    * If the heap is empty give the message "Heap is empty. No object removed.", but
    * do not exit the program.
    */
   virtual void remove() {
      // TODO: implement
	   if (size == 0) {
		   cout << "\nHeap is empty. No Object removed\n";
	   }
	   else {
		   items[0] = items[size - 1];
		   size--;
		   rebuild(0, size);
	   }
      
   }// end remove()
   /*---------------------------------------------------------------------------------*/
   
   /* Performs a heap sort. */
   virtual void sort() {
      // TODO: implement
	   for (int i = size - 1; i >= 0; i--) {
		   rebuild(i, size);
	   }
	   int last = size - 1;
	   for (int i = 1; i <= size; i++) {
		   E tmp;
		   tmp = items[0];
		   items[0] = items[last];
		   items[last] = tmp;
		   last--;
		   rebuild(0, last);
	   }
      
   } // end sort()
   /*---------------------------------------------------------------------------------*/
   
   /* Returns the objects in the array formatted as:
    * items[0]
    * items[1]
    * ...
    * items[size -1]
    */
   virtual string toString() const {
      // TODO: implement
	   ostringstream oss;
	   for (int i = 0; i <= HEAP_SIZE - 1; i++) {
		   oss << items[i] << endl;
	  }
	   return oss.str();
   } // end toString()
   /*---------------------------------------------------------------------------------*/
   
};// end Heap

/* Displays the heap to the screen. Calls the o.toString(). */
template <typename E>
ostream& operator <<(ostream& out, const Heap<E>& o) {
   // TODO: implement
	out << o.toString();
	return out;
}// end <<()

#endif
