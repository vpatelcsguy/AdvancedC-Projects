/*    File: ArrayList.hpp
*    Name: Vaibhav Patel
* Revised: 10/7/2016
*  Course: CS240 - Introduction to Computing III
*
*    Desc: ArrayList.hpp template file using inline coding.
*/


#ifndef ArrayList_hpp
#define ArrayList_hpp

#include <string>
#include <iostream>
#include <sstream>
#include "Name.hpp"

using namespace std;
template <typename E>
class ArrayList {
private:

	E * array; 
	int size;

	void resize() {

		try {

			E * temp = createArray(size + 1);
			for (int i = 0; i <= size - 1; i += 1) {
				temp[i] = array[i];
			}
			delete[] array;

			array = temp;

			temp = nullptr;
			size += 1;

		}
		catch (bad_alloc ba) {
			cerr << ba.what() << endl;
			exit(1);
		}

	}

	void duplicateElements(const ArrayList& o) {
		size = o.size;
		array = createArray(size);

		for (int i = 0; i <= size - 1; i += 1) {
			array[i] = o.array[i];

		}
	}

	void releaseElements() {

		delete[] array;
		array = nullptr;
		size = 0;
	}
	E * createArray(const int newSize) {
		return new E[newSize];
	}

public:
	
	ArrayList() : size(0), array(nullptr) {}

	virtual ~ArrayList() {
		releaseElements();
	}

	ArrayList(const ArrayList& o) {
		duplicateElements(o);
	}

	virtual const ArrayList& operator =(const ArrayList& o) final {
		if (this != &o) {
			releaseElements();
			duplicateElements(o);
		}

		return *this;
	}

	virtual int getSize() const final {
		return size;
	}

	virtual E getAt(const int index) const final {

		if (index >= 0 && index <= size - 1) {
			return array[index];

		}
		else if (array == nullptr) {
			throw logic_error("Error: Empty array");

		}
		else {
			throw logic_error("Error: index out of bounds");
		}
	}

	virtual E get() const final {
		if (array == nullptr) {
			throw logic_error("Error: Empty array");
		}

		return array[0];
	}

	virtual void insertAt(const int index, E const name) final {
		resize();

		for (int i = size - 2; i >= index; i -= 1) {
			array[i + 1] = array[i];
		}

		array[index] = name;
	}

	virtual void insert(E const name) final {
		resize();

		array[size - 1] = name;

	}

	virtual string toString() const {
		ostringstream oss;

		oss << "[" << endl;

		for (int i = 0; i <= size - 1; i += 1) {
			oss << "\t" << array[i] << endl;
		}

		oss << "]";

		return oss.str();
	}

	virtual E & operator [] (const int index) const final {
		if (index >= 0 && index <= size - 1) {
			return array[index];

		}
		else {
			throw logic_error("Error: index out of bounds");
		}
	}

	virtual bool operator == (const ArrayList& o) const {
		bool equal = size == o.size;

		if (equal) {
			string thisName;
			string thatName;

			int i = 0;

			while (equal) {
				thisName = array[i].getName();
				thatName = o.array[i].getName();

				equal = equal &&  thisName == thatName;
				i += 1;
			}
		}
		return equal;
	}
	virtual bool operator != (const ArrayList& o) const { return !(*this == o); }
	virtual bool operator <  (const ArrayList& o) const { return size < o.size; }
	virtual bool operator <= (const ArrayList& o) const { return size <= o.size; }
	virtual bool operator >  (const ArrayList& o) const { return o < *this; }
	virtual bool operator >= (const ArrayList& o) const { return o <= *this; }
/*----------------------------------------------------------------------------------*/

};

template <typename E>
ostream& operator <<(ostream& out, const ArrayList<E>& o) {
	out << o.toString();

	return out;
}
#endif /* ArrayList_hpp */
