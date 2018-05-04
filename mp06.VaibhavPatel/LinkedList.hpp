/*    File: LinkedList.hpp
*    Name: Vaibhav Patel
* Revised: 11/19/2016
*  Course: CS240 - Introduction to Computing III
*
*/

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

/* This linked list will be a bi-directional list, i.e. will have a 'previous' and
 * a 'next' pointer, thus offering two-way navigation.
 *
 * The next enhancement is that the list will make use of dummy nodes. These are
 * data nodes like the rest, but are not used during processing. They facilitate
 * efficient insert/remove operations.
 */
template <typename E>
class LinkedList {
private:
   /*----------------------------------------------------------------------------------*/
   /* A nested class is private to the outside (client), but accessible by the container
    * class (LinkedList). Its members however are still bound by the access qualifiers,
    * thus the public. This gives the LinkedList direct access to DoubleNode's members.
    */
   class DoubleNode {
   public:
      DoubleNode * previous;
      E * element;
      DoubleNode * next;
      
      DoubleNode(DoubleNode * const previous,
                 E * const element,
                 DoubleNode * const next)
      : previous(previous), element(element), next(next)
      {}
   };
   /*----------------------------------------------------------------------------------*/
   
   /* Duplicates all the elements of the parameter object to the newly created one. */
   void duplicateNodes(const LinkedList& o) {
      try {
         DoubleNode * iter = o.head;
         size = o.size;
         
         /* Duplicate the first one, since head is involved and thus cannot be part
          * of the repetition below. Duplicate the element by using the copy constructor
          * for the type. Since the element is a pointer to the object, dereference it.
          */
         head = tail = createNode(nullptr, new E(*iter->element), nullptr);
         iter = iter->next;
         
         while(iter != nullptr) {
            tail = tail->next = createNode(tail, new E(*iter->element), nullptr);
            iter = iter->next;
         }
         
      } catch (bad_alloc ba) {
         cerr << ba.what() << endl;
         exit(1);
      }
   }// end duplicateNodes()
   /*----------------------------------------------------------------------------------*/
   
   /* Releases all the nodes on the list. */
   void releaseNodes() {
      DoubleNode * del = head;
      
      while (head != nullptr) {
         head = head->next;
         
         /* Release the node at del. */
         del->previous = del->next = nullptr;
         delete del;
         
         del = head;
      }
      
      tail = nullptr;
      size = 0;
   }// end releaseNodes()
   /*----------------------------------------------------------------------------------*/
   
   /* Returns a dynamically allocated DoubleNode object. Throws a bad_alloc exception
    * if it fails to allocate the needed memory.
    */
   DoubleNode * createNode(DoubleNode * previous,
                           E * const element,
                           DoubleNode * const next) {
      return new DoubleNode(previous, element, next);
   }// end createNode()
   /*----------------------------------------------------------------------------------*/

   /* Returns a pointer to the requested node. This method should not be called if index
    * is not in range.
    */
   DoubleNode * getNodeAt(const int index) const {
      /* To make more efficient, test if index is closer to the tail. */
      DoubleNode * iter = nullptr;
      
      if      (index == size)     { iter = tail;           }
      else if (index == size - 1) { iter = tail->previous; }
      else {
         /* Start with the first data node. */
         iter = head->next;
         
         /* To make sure we skip over the correct number of nodes, start at 1. */
         for (int i = 1; i <= index; i += 1) {
            iter = iter->next;
         }
      }
      
      return iter;
   }// end getNodeAt()
   /*----------------------------------------------------------------------------------*/
   
   /* Returns a pointer to the requested node. */
   DoubleNode * getNodeContaining(E const * element) const {
      /* To make more efficient, test if the last node contains the element. */
      DoubleNode * iter = tail->previous;
      
      if (*iter->element == *element) {
         return iter;
      }
      
      /* Start with the first data node. */
      iter = head->next;
      
      /* Keep searching until you find it. */
      while (iter != tail && *iter->element != *element) {
         iter = iter->next;
      }
      
      return iter;
   }// end getNodeContaining()
   /*----------------------------------------------------------------------------------*/
   
   /* Releases the node pointed to by del and sets del to nullptr. */
   void releaseNode(DoubleNode *& del) {
      del->previous = del->next = nullptr;
      
      delete del;
      del = nullptr;
   }
   /*----------------------------------------------------------------------------------*/
   
   DoubleNode * head;
   DoubleNode * tail;
   int size;
   
public:
   /* Sets the size to 0 and both head/tail pointers to dummy nodes. */
   LinkedList() : size(0) {
      head = tail = createNode(nullptr, new E(), nullptr);
      head->next = tail = createNode(head, new E(), nullptr);
   }// end LinkedList()
   /*----------------------------------------------------------------------------------*/

   /* Destructor: Releases all the dynamically allocated memory. */
   virtual ~LinkedList() {
      releaseNodes();
   }// end ~LinkedList()
   /*----------------------------------------------------------------------------------*/

   
   /* Copy constructor: Makes a duplicate of the parameter object o. */
   LinkedList(const LinkedList& o) {
      duplicateNodes(o);
   }// end LinkedList()
   /*----------------------------------------------------------------------------------*/

   
   /* Makes a duplicate of the assigned object o. */
   virtual const LinkedList& operator =(const LinkedList& o) final {
      if (this != &o) {
         releaseNodes();
         duplicateNodes(o);
      }
      
      return *this;
   }// end =()
   /*----------------------------------------------------------------------------------*/
   
   /* Returns the size of the list. */
   virtual int getSize() const final {
      return size;
   }// end getSize()
   /*----------------------------------------------------------------------------------*/
   
   /* Returns the element at the specified index. */
   virtual E * getAt(const int index) const final {
      
      if      (size == 0)                  { throw logic_error("Error: Empty list");          }
      else if (index < 0 || index >= size) { throw logic_error("Error: index out of bounds"); }
      
      return  getNodeAt(index)->element;
   }// end getAt()
   /*----------------------------------------------------------------------------------*/
   
   /* Returns the first element. */
   virtual E * getFirst() const final {
      if (size == 0) { throw logic_error("Error: Empty list"); }
      
      return getNodeAt(0)->element;
   }// end getFirst()
   /*----------------------------------------------------------------------------------*/
   
   /* Returns the last element. */
   virtual E * getLast() const final {
      if (size == 0) { throw logic_error("Error: Empty list"); }
      
      return getNodeAt(size - 1)->element;
   }// end getLast()
   /*----------------------------------------------------------------------------------*/
   
   /* Inserts the element at the specified index. */
   virtual void insertAt(const int index, E * const element) final {
      /* If size != 0, then a valid index is a must, so let's check it. */
      if (index < 0 || index > size) { throw logic_error("Error: Index out of bounds"); }
      
      /* Note, if size == 0, then index == 0 is the only acceptable index. */
      
      DoubleNode * after = getNodeAt(index);
      DoubleNode * before = after->previous;
      
      before->next = after->previous = createNode(before, element, after);
      size += 1;
   }// end insertAt()
   /*----------------------------------------------------------------------------------*/
   
   /* Inserts the element in its proper position (sorted order). */
   virtual void insert(E * const element) final {
      
      DoubleNode * before = tail->previous;
      DoubleNode * after = nullptr;
      
      if (*element > *before->element) {
         /* Check if element is after the last node, thus avoiding unnecessary traversals. */
         after = before->next;
         
      } else {
         /* Element is either the first one, or its somewhere within the list. */
         after = head->next;
         
         while (after != tail && *element > *after->element) {
            after = after->next;
         }
         before = after->previous;
      }
      
      before->next = after->previous = createNode(before, element, after);
      size += 1;
   }// end insert()
   /*----------------------------------------------------------------------------------*/

   /* Removes the element at the specified index. */
   virtual void removeAt(const int index) final {
      if (size == 0)                       { throw logic_error("Error: Empty list");          }
      else if (index < 0 || index >= size) { throw logic_error("Error: index out of bounds"); }
      
      /* Position the del pointer on the node being removed. */
      DoubleNode * del = getNodeAt(index);
      DoubleNode * before = del->previous;
      DoubleNode * after = del->next;
      
      /* First remove the node from the list. */
      before->next = after;
      after->previous = before;
      
      /* Now, release the node itself. */
      releaseNode(del);
      size -= 1;
   }// end removeAt()
   /*----------------------------------------------------------------------------------*/

   /* Removes the specified element. */
   virtual void remove(E * const element) final {
      if (size == 0) { throw logic_error("Error: Empty list"); }
      
      DoubleNode * del = getNodeContaining(element);
      
      /* If we did not find it, then throw an exception. */
      if (del == tail) { throw logic_error("Error: Element not found."); }
      
      /* Let's remove the node we just found. */
      DoubleNode * before = del->previous;
      DoubleNode * after = del->next;
      
      /* First remove the node from the list. */
      before->next = after;
      after->previous = before;
      
      /* Now, release the node itself. */
      releaseNode(del);
      size -= 1;
   }// end remove()
   /*----------------------------------------------------------------------------------*/
   
   /* Will return the object formatted as:
    * [
    *   element1
    *   element2
    *   ...
    *   elementN
    * ]
    */
   virtual string toString() const {
      ostringstream oss;
      DoubleNode * iter = head->next;
      
      oss << "[" << endl;
      
      while (iter != tail) {
         oss << "\t" << *iter->element << endl;
         iter = iter->next;
      }
      
      oss << "]";
      
      return oss.str();
   }// end toString()
   /*----------------------------------------------------------------------------------*/
   
   /* Overloaded operators */
   
   /* Returns the address of the element at the specified index. The operator will
    * validate the index for proper range and throw a logic_error exception if
    * the index is out of bounds.
    *
    * The return type is always a reference to the element type.
    */
   virtual E * & operator [] (const int index) const final {
      if (size == 0)                       { throw logic_error("Error: Empty list");          }
      else if (index < 0 || index >= size) { throw logic_error("Error: index out of bounds"); }
      
      return getNodeAt(index)->element;
   }// end []()
   /*----------------------------------------------------------------------------------*/
   
   /* Equality means the size is the same, and each corresponding element is the same. */
   virtual bool operator == (const LinkedList& o) const {
      bool equal = (size == o.size);
      
      /* Check each element for equality. */
      DoubleNode * iter = head->next;
      DoubleNode * citer = o.head->next;
      
      while (iter != tail && equal) {
         equal = *iter->element == *citer->element;
         
         iter = iter->next;
         citer = citer->next;
      }
      
      return equal;
   }// end ==()
   /*----------------------------------------------------------------------------------*/
   
   virtual bool operator != (const LinkedList& o) const { return !(*this == o); }// end !=()
   
   /* The ordering opearators are based on size alone. */
   virtual bool operator <  (const LinkedList& o) const { return size < o.size; }// end <()
   virtual bool operator <= (const LinkedList& o) const { return !(*this > o);  }// end <=()
   virtual bool operator >  (const LinkedList& o) const { return o < *this;     }// end >()
   virtual bool operator >= (const LinkedList& o) const { return !(*this < o);  }// end >=()
   /*----------------------------------------------------------------------------------*/
   
}; // end LinkedList

/*----------------------------------------------------------------------------------*/

template <typename E>
ostream& operator <<(ostream& out, const LinkedList<E>& o) {
   out << o.toString();
   
   return out;
}// end <<()
/*----------------------------------------------------------------------------------*/

#endif /* LinkedList_hpp */
