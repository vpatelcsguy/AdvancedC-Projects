/*    File: main.cpp
*    Name: Vaibhav Patel
* Revised: 11/04/2016
*  Course: CS240 - Introduction to Computing III
*
*    Desc: Quick Sort. Sorting 100 numbers, then timing 10,000 numbers to sort.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int ARRAY_SIZE = 100;
const int SIZE = 10000;

/* TODO: Recursive quick sort implementation. Refer to both the book's solution and the
 * one presented in class to implement the quicksort algorithm.
 */
void qsort(int * list[], const int first, const int last);

/* TODO: Partition method of recursive quicksort algorithm. */
int partition(int * list[], const int first, const int last);

/* TODO: Swap the elements at the given indices. */
void swap(int * list[], const int index1, const int index2);

/* TODO: <<() for an array of pointers to int. */
ostream& operator <<(ostream& out, int * list[]);

int main() {
   /* Declare a dynamic array, list, of integer pointers. */
	int * * list;

   
   /* TODO: Allocate an array of ARRAY_SIZE + 1 int pointers. The extra element will contain
    * a nullptr. This nullptr will be used by the overloaded <<() function to determine the end.
    */
	list = new int * [ARRAY_SIZE + 1];

   
   /* TODO: Randomly generate ARRAY_SIZE integer values in the range 1-1000 and add to the array. */
	for (int i = 0; i <= ARRAY_SIZE - 1 ; i++) {
	 
		list[i] = new int((rand() % 1000 + 1));
   }
   
   /* TODO: Add a nullptr to the last element so the <<() knows when to stop. */
	list[ARRAY_SIZE] = nullptr;
   
   /* TODO: List the original unsorted array. */
	cout << "Unsorted List:\n";
	cout << list;

   /* TODO: sort the array using qsort(). */
	qsort(list, 0, ARRAY_SIZE-1);

   /* TODO: List the sorted list. */
	cout << "Sorted List: (Sorted numbers are from left to right then top to bottom)\n";
	cout << list;
   
   /* TODO: Release all the memory allocated to the array. */
	for (int i = 0; i <= ARRAY_SIZE - 1; i += 1) {
		delete list[i];
		list[i] = nullptr;
	}

	delete[] list;
	list = nullptr;
   
   
   /* TODO: Display the total amount of time it takes to sort a list
    * of 10000 random numbers. Use the clock() function for this. Make sure you look up
    * how to use it and see what library you need to include.
    */

   /* TODO: Randomly generate 10,000 integer values in the range 1-1000 and add to the array. */
	list = new int * [SIZE];

	for (int i = 0; i <= SIZE - 1; i++) {
		list[i] = new int((rand() % 1000 + 1));
	}

	clock_t t1 = clock();
	qsort(list, 0, SIZE-1);
	clock_t t2 = clock();
	cout << "\nTime to Sort 10000 integers\t: " << (t2 - t1) << " clocks \n";
 
   /* TODO: Release all the memory allocated to the array. */
	for (int i = 0; i <= SIZE - 1; i += 1) {
		delete list[i];
		list[i] = nullptr;
	}

	delete[] list;
	list = nullptr;

	std::cin.get();
   
   return 0;
}

/* TODO: Recursive quick sort implementation. Refer to both the book's solution and the
 * one presented in class to implement the quicksort algorithm.
 */
void qsort(int * list[], const int first, const int last) {
	int pivot;
	if (first < last) {
		pivot = partition(list, first, last);
		qsort(list, first, pivot - 1);
		qsort(list, pivot + 1, last);
	}

}// end qsort()
/*----------------------------------------------------------------------------------*/

/* TODO: Partition method of recursive quicksort algorithm. */
int partition(int * list[], const int first, const int last) {
	int * p = list[first];
	int lastS1 = first;
	int firstUnknown = first + 1;
	while (firstUnknown <= last) {
		if (*list[firstUnknown]  < *p) {
			lastS1++;
			swap(list, lastS1, firstUnknown);
		}
		firstUnknown++;
	}
	swap(list, first, lastS1);
	return lastS1;
   
}// end partition()
/*----------------------------------------------------------------------------------*/

/* TODO: Swap the elements at the given indices. */
void swap(int * list[], const int index1, const int index2) {

	int * temp;
	temp = list[index1];
	list[index1] = list[index2];
	list[index2] = temp;

 
}// end swap()
/*----------------------------------------------------------------------------------*/


/* TODO: <<() for an array of pointers to int. */
ostream& operator <<(ostream& out, int * list[]) {
	int i = 0;
	out << "[\n";
	while (list[i] != nullptr) {
		out << *list[i] << "\t\t";
		if ((i - 1) % 5 == 3) {
			out << "\n";
		}
		i++;
	}
	out << "]\n";
	return out;
}
