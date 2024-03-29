#ifndef BST_HPP
#define BST_HPP
#include "BSTNode.hpp"
#include "BSTIterator.hpp"
#include <iostream>

template<typename Data>
class BST {

protected:

  /** Pointer to the root of this BST, or 0 if the BST is empty */
  BSTNode<Data>* root;
  /** Number of Data items stored in this BST. */
  unsigned int isize;

  /** Height of this BST. */
  unsigned int iheight;
  
public:

  /** define iterator as an aliased typename for BSTIterator<Data>. */
  typedef BSTIterator<Data> iterator;

  /** Default constructor.
      Initialize an empty BST.
   */
  BST() : root(nullptr), isize(0), iheight(0) {  }


  /** Default destructor.
      Delete every node in this BST.
   */ // TODO
  virtual ~BST() {
	  deleteAll(root);
	  isize = 0;
	  iheight = 0;
  }

  /** Given a reference to a Data item, insert a copy of it in this BST.
   *  Return  true if the item was added to this BST
   *  as a result of this call to insert,
   *  false if an item equal to this one was already in this BST.
   *  Note: This function should use only the '<' operator when comparing
   *  Data items. (should not use ==, >, <=, >=)  For the reasoning
   *  behind this, see the assignment writeup.
   */ // TODO
  virtual bool insert(const Data& item) {
	  BSTNode<Data>* current = root;
	  BSTNode<Data>* next = root;
	  unsigned int currentheight = 0;
	  if (root == NULL) {
		  root = new BSTNode<Data>(item);
		  ++isize;
		  iheight = 0;
		  return true;
	  }
	  while (next != NULL)
	  {
		  current = next;
		  if (current->data < item)
			  next = current->right;
		  else if (item < current->data)
			  next = current->left;
		  else 
			  return false;

		  ++currentheight;
	  }
	  if (current->data < item) {
		  current->right = new BSTNode<Data>(item);
		  current->right->parent = current;

	  }
	  else
	  {
		  current->left = new BSTNode<Data>(item);
		  current->left->parent = current;
	  }
	  ++isize;
	  iheight = std::max<unsigned int>(iheight, currentheight);
	  return true;
  }


  /** Find a Data item in the BST.
   *  Return an iterator pointing to the item, or pointing past
   *  the last node in the BST if not found.
   *  Note: This function should use only the '<' operator when comparing
   *  Data items. (should not use ==, >, <=, >=).  For the reasoning
   *  behind this, see the assignment writeup.
   */ // TODO
  iterator find(const Data& item) const {
	  BSTNode<Data>* current = root; 
	  BSTNode<Data>* next = root;

	  while (next != NULL)
	  {
		  current = next;
		  if (current->data < item)
			  next = current->right;
		  else if (item < current->data)
			  next = current->left;
		  else 
			return typename BST<Data>::iterator(current);
	  }
	  return end();
  }

  
  /** Return the number of items currently in the BST.
   */ // TODO
  unsigned int size() const {
	  return isize;

  }
  
  /** Return the height of the BST.
   */ // TODO
  unsigned int height() const {
	  return iheight;
  }


  /** Return true if the BST is empty, else false.
   */ // TODO
  bool empty() const {
	  if (isize == 0)
		  return true;
	  return false;
  }

  /** Return an iterator pointing to the first item in the BST (not the root).
   */ // TODO
  iterator begin() const {
	   return typename BST<Data>::iterator(first(root));
  }

  /** Return an iterator pointing past the last item in the BST.
   */
  iterator end() const {
    return typename BST<Data>::iterator(0);
  }

  /** Perform an inorder traversal of this BST.
   */
  void inorder() const {
    inorder(root);
  }


private:
	///**Recursive height 'helper' function

	///** gets the height from the input node to the bottom of the tree
	//if the input is the root, you will get the height of the whole tree
	//*/
	//unsigned int height(BSTNode<Data>* n)  const {
	//	if (n == NULL)
	//		return 0;
	//	return 1 + std::max(height(n->left), height(n->right));
	//}

  /** Recursive inorder traversal 'helper' function */

  /** Inorder traverse BST, print out the data of each node in ascending order.
      Implementing inorder and deleteAll base on the pseudo code is an easy way to get started.
   */ // TODO
  void inorder(BSTNode<Data>* n) const {
	  if (n == NULL)
		  return;

	  inorder(n->left);
	  std::cout << n->data << std::endl;
	  inorder(n->right);
    /* Pseudo Code:
      if current node is null: return;
      recursively traverse left sub-tree
      print current node data
      recursively traverse right sub-tree
    */
  }

  /** Find the first element of the BST
   */ 
  static BSTNode<Data>* first(BSTNode<Data>* root) {
    if(root == 0) return 0;
    while(root->left != 0) root = root->left;
    return root;
  }

  /** do a postorder traversal, deleting nodes
   */ // TODO
  static void deleteAll(BSTNode<Data>* n) {

	  if (n == NULL)
		  return;
	  deleteAll(n->left);
	  deleteAll(n->right);
	  delete n;
    /* Pseudo Code:
      if current node is null: return;
      recursively delete left sub-tree
      recursively delete right sub-tree
      delete current node
    */
  }


 };


#endif //BST_HPP
