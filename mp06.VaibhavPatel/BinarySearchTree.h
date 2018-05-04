/*    File: BinarySearchTree.hpp
*    Name: Vaibhav Patel
* Revised: 11/19/2016
*  Course: CS240 - Introduction to Computing III
*
*/

#ifndef __cppProject__BinarySearchTree__
#define __cppProject__BinarySearchTree__

#include <iostream>
using namespace std;

/*-----------------------------------------------------------------------
 * Class: BinarySearchTree
 *
 * The class that defines the Binary Search Tree ADT.
 *----------------------------------------------------------------------*/
template <typename E>
class BinarySearchTree {
private:
   /*-----------------------------------------------------------------------
    * Class: TreeNode
    *
    * The class that represents a node on a binary tree.
    *----------------------------------------------------------------------*/
   class TreeNode {
   public:
      TreeNode * left;
      E element;
      TreeNode * right;
      
      TreeNode(TreeNode* const left, const E& e, TreeNode* const right): left(left), element(e), right(right){}
   };
   /*-----------------------------------------------------------------------*/
   
   typedef void (* FunctionPointer)(E& e);
   
   /* Memory management methods. */
   void copyTree(TreeNode *& r, TreeNode * cr) {
      /* Note: When we add exception handling to the createNode() method,
       * we should use a try/catch here to catch the exception. When that
       * happens, we must make the tree empty at that point, to avoid a
       * memory leak.
       */
      
      /* Perform a preorder tree creation. The receiving tree will
       * always have its root set to nullptr. This happens in the
       * default ctor and also in the copy ctor.
       */
      if (cr) {
         /* When we have a node to copy. */
         r = createNode(nullptr, cr->element, nullptr);
         
         copyTree(r->left, cr->left);
         copyTree(r->right, cr->right);
      }
   }// end copyTree()
   
   void releaseNode(TreeNode *& r) {
      /* Release the memory for one node. */
      r->left = r->right = nullptr;
      delete r;
      r = nullptr;
   }// end releaseNode()

   void makeEmpty(TreeNode *& r) {
      /* Releases all the nodes in the tree, using a postorder traversal. */
      if (r) {
         makeEmpty(r->left);
         makeEmpty(r->right);
         releaseNode(r);
      }
   }// end makeEmpty()
   
   TreeNode* createNode(TreeNode * const left, const E& e, TreeNode * const right) {
      /* Add exception handling in this one. Also, notice the typename at
       * the beginning of the method header. This is needed since the TreeNode
       * is an internal templated class.
       */
      return new TreeNode(left, e, right);
   }// end createNode()
   /*-----------------------------------------------------------------------*/
   /* Traversal methods. */
   void preorder(TreeNode * const r, FunctionPointer visit) const {
      /* The visit function can take on many behaviors, as needed. */
      if (r) {
         visit(r->element);
         preorder(r->left, visit);
         preorder(r->right, visit);
      }
   }// end preorder()
   
   void inorder(TreeNode * const r, FunctionPointer visit) const {
      /* The visit function can take on many behaviors, as needed. */
      if (r) {
         inorder(r->left, visit);
         visit(r->element);
         inorder(r->right, visit);
      }
   }// end inorder()

   void postorder(TreeNode * const r, FunctionPointer visit) const {
      /* The visit function can take on many behaviors, as needed. */
      if (r) {
         postorder(r->left, visit);
         postorder(r->right, visit);
         visit(r->element);
      }
   }// end postorder()

   /*-----------------------------------------------------------------------*/
   /* Tree stats methods. */
   int height(TreeNode * const r) const {
      /* The height of the tree is determined by the larger of the two heights
       * between the left and right subtrees.
       */
      if (r == nullptr) { return 0;                                          }
      else              { return 1 + max(height(r->left), height(r->right)); }
   }// end height()

   int max(const int leftHeight, const int rightHeight) const {
      return (leftHeight >= rightHeight)? leftHeight : rightHeight;
   }// end max()

   int count(TreeNode * const r) const {
      /* Count all the nodes in the tree. Use a postorder traversal,
       * although any of the three would do.
       */
      if (r == nullptr) { return 0;                                    }
      else              { return 1 + count(r->left) + count(r->right); }
   }// end count()

   int leafCount(TreeNode * const r) const {
      /* Count all the leaves in the tree. Use a postorder traversal. */
      if (r == nullptr)             { return 0;                                        }
      else if (r->left == r->right) { return 1;                                        }
      else                          { return leafCount(r->left) + leafCount(r->right); }
   }// end leafCount()

   /*-----------------------------------------------------------------------*/
   /* Operational methods. */
   bool contains(TreeNode * const r, const E& e) const {
      if (r == nullptr)          { return false;                 }
      else if (e == r->element)  { return true;                  }
      else if (e < r->element)   { return contains(r->left, e);  }
      else                       { return contains(r->right, e); }
   }// end contains()

   void insert(TreeNode *& r, const E& e) {
      /* Inserts element in an ordered fashion. Elements less than parent
       * node go left, elements greater than or equal go to the right.
       */
      if (r == nullptr)          { r = createNode(nullptr, e, nullptr); }
      else if (e < r->element)   { insert(r->left, e);                  }
      else                       { insert(r->right, e);                 }
   }// end insert()

   void remove(TreeNode *& r, const E& e) {
      if (r == nullptr)          { cerr << "Unable to remove from an empty tree." << endl; }
      else if (e == r->element)  { removeNode(r);                                          }
      else if (e < r->element)   { remove(r->left, e);                                     }
      else                       { remove(r->right, e);                                    }
   }// end remove()

   void removeNode(TreeNode *& r) {
      TreeNode* del;
      
      if ( hasTwoChildren(r) ) {
         r->element = immediateSuccessor(r->right);
      } else if ( hasLeftChildOnly(r) ) {
         del = r;
         r = r->left;
         releaseNode(del);
      } else if ( hasRightChildOnly(r) ) {
         del = r;
         r = r->right;
         releaseNode(del);
      } else if ( isLeaf(r) ) {
         releaseNode(r);
      }
   }// end removeNode()

   bool hasTwoChildren(TreeNode * const r) const {
      return (r->left != nullptr && r->right != nullptr);
   }// end hasTwoChildren()

   bool hasLeftChildOnly(TreeNode * const r) const {
      return r->right == nullptr;
   }// end hasLeftChildOnly()

   bool hasRightChildOnly(TreeNode * const r) const {
      return r->left == nullptr;
   }// end hasRightChildOnly()

   bool isLeaf(TreeNode * const r) const {
      return r->left == r->right;
   }// end isLeaf()

   E immediateSuccessor(TreeNode *& r) {
      if (r->left == nullptr) {
         E successor = r->element;
         
         TreeNode* del = r;
         r = r->right;
         releaseNode(del);
         
         return successor;
      } else {
         return immediateSuccessor(r->left);
      }
   }// end immediateSuccessor()

   /*-----------------------------------------------------------------------*/
protected:
   TreeNode * root;
   /*-----------------------------------------------------------------------*/
public:
   /* Memory management methods. */
   BinarySearchTree() : root(nullptr)
   {}// end BinaryTree()

   BinarySearchTree(const BinarySearchTree& o) : root(nullptr) {
      copyTree(root, o.root);
   }// end BinaryTree()

   ~BinarySearchTree() {
      makeEmpty(root);
   }// end ~BinaryTree()

   const BinarySearchTree& operator =(const BinarySearchTree& o) {
      if (this != & o) {
         makeEmpty(root);
         copyTree(root, o.root);
      }
      
      return *this;
   }// end =()

   virtual void makeEmpty() { makeEmpty(root); }// end makeEmpty()
   /*-----------------------------------------------------------------------*/
   /* Traversal methods. */
   virtual void preorder(FunctionPointer visit) const  { preorder(root, visit);  }// end preorder()
   virtual void inorder(FunctionPointer visit) const   { inorder(root, visit);   }// end inorder()
   virtual void postorder(FunctionPointer visit) const { postorder(root, visit); }// end postorder()
     
   /*-----------------------------------------------------------------------*/
   /* Tree stats methods */
   virtual bool isEmpty() const  { return root == nullptr; }// end isEmpty()
   virtual int height() const    { return height(root);    }// end height()
   virtual int count() const     { return count(root);     }// end count()
   virtual int leafCount() const { return leafCount(root); }// end leafCount()
   /*-----------------------------------------------------------------------*/
   /* Operational methods. */
   virtual bool contains(const E& e) const { return contains(root, e); }// end contains()
   virtual void insert(const E& e)         { insert(root, e);          }// end insert()
   virtual void remove(const E& e)         { remove(root, e);          }// end remove()
};
/*-----------------------------------------------------------------------*/

#endif /* defined(__cppProject__BinarySearchTree__) */
