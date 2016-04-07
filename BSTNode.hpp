#ifndef BSTNODE_HPP
#define BSTNODE_HPP
#include <iostream>
#include <iomanip>

template<typename Data>
class BSTNode {

public:

  /** Constructor.  Initialize a BSTNode with the given Data item,
   *  no parent, and no children.
   */
  BSTNode(const Data & d) : data(d) {
    left = right = parent = 0;
  }

  BSTNode<Data>* left;
  BSTNode<Data>* right;
  BSTNode<Data>* parent;
  Data const data;   // the const Data in this node.

  /** Return the successor of this BSTNode in a BST, or 0 if none.
   ** PRECONDITION: this BSTNode is a node in a BST.
   ** POSTCONDITION:  the BST is unchanged.
   ** RETURNS: the BSTNode that is the successor of this BSTNode,
   ** or 0 if there is none.
   */ // TODO
  BSTNode<Data>* successor() {
	  //if this node has a right child then the successor is all the way
	  //left from the right child 
	  if (right != NULL)
	  {
		  BSTNode<Data>* leftest = right;
		  BSTNode<Data>* next_leftest = right; //go one past leftest to the nul
		  while (next_leftest != NULL)
		  {
			  leftest = next_leftest;
			  next_leftest = leftest->left;
		  }
		  return leftest;
		  //go all the way to the left
	  }
	  //if the right child is null then the successor will be the parent,
	  //if this node is the left child of the parent
	  //if this child is not the left child, keep looking at parents
	  // til it is left, if you go all the way to the root, and its not
	  // a left child then its greatest element and the successor should
	  // be null
	  BSTNode<Data>* leftParent = parent;
	  BSTNode<Data>* leftChild = this;
	  while (leftParent != NULL && leftParent->left != leftChild)
	  {
		  leftChild = leftParent;
		  leftParent = leftParent->parent;
	  }
	  if (leftParent == NULL)
		  return 0;

	  return leftParent;

  }

}; 

/** Overload operator<< to print a BSTNode's fields to an ostream. */
template <typename Data>
std::ostream & operator<<(std::ostream& stm, const BSTNode<Data> & n) {
  stm << '[';
  stm << std::setw(10) << &n;                 // address of the BSTNode
  stm << "; p:" << std::setw(10) << n.parent; // address of its parent
  stm << "; l:" << std::setw(10) << n.left;   // address of its left child
  stm << "; r:" << std::setw(10) << n.right;  // address of its right child
  stm << "; d:" << n.data;                    // its data field
  stm << ']';
  return stm;

}

#endif // BSTNODE_HPP
