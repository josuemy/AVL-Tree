/*
  Josue Montenegro
  PA2: Implementation of AVL Tree
  CS130A
 */

#include <iostream>
#include <sstream>
#include "avl.h"
#include <string>

using namespace std;

/*------------------------------
        Public Methods
------------------------------*/

//inserts key 'e' into the tree and balances it
void AVLTree::Insert(const int32_t e)
{
  return Insert(e, root, root);
}

//returns true if element can be accessed
bool AVLTree::Access(const int32_t e)
{
  return Access(e, root);
}

//deletes key 'e' into the tree and balances it
void AVLTree::Delete(const int32_t e)
{
  return Delete(e, root);
}

//PreOrder traversal of the tree
string AVLTree::PrintPreOrder() const {
  result = "";
  PrintPreOrder(root);
  result.pop_back(); // gets rid of the the extra space at the end
  return result;
}

//InOrder traversal of the tree
string AVLTree::PrintInOrder() const{
  result = "";
  PrintInOrder(root);
  result.pop_back(); // gets rid of the the extra space at the end
  return result;
}

/*------------------------------
        Private Methods
------------------------------*/

/*
  returns height of the current node
*/
int AVLTree::height (AVLNode * n){
  if (n){
    return n-> height;
  }else{
    return 0; // if node is poiting to NULL
  }
}

/*
  determines the balance factor of a node by looking at
  at the height of its children
*/
int AVLTree::balFactor(AVLNode* n){
  return height(n->right) - height(n->left);
}

/*
  takes the greatest height from children and adds 1,
  it becomes current node height
*/
void AVLTree::assignHeight(AVLNode * n){
  int l = height(n->left);
  int r = height(n->right);
  n->height = (l>r ? l : r ) +1;
}

/*
  prints root -> left child -> right child
 */
void AVLTree::PrintPreOrder(AVLNode * root) const{
  if(root != NULL){
    result += to_string(root->elem) + " ";
    PrintPreOrder(root->left);
    PrintPreOrder(root->right);
  }
}

/*
  prints left child -> root -> right child
 */
void AVLTree::PrintInOrder(AVLNode * root) const{
  if(root != NULL){
    PrintInOrder(root->left);
    result += to_string(root->elem) + " ";
    PrintInOrder(root->right);
  }
}

/*
  finds element with min key on a tree
  it will be used to find the successor of a node
 */
AVLNode * AVLTree::findMin(AVLNode *t)
{
  if(t != NULL)
    while(t->left != NULL)
      t = t->left;
  return t;
}

/*
  helper function to destroy the tree,
  recursively deletes parent and then children
*/
void AVLTree::makeEmpty(AVLNode * & t)
{
  if(t != NULL) {
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;
  }
  t = NULL;
}

/*
  Performs typical BST insertion operation and balances the tree
  while the recursive calls get called of the stack
*/
void AVLTree::Insert(const int32_t e, AVLNode * & t, AVLNode * parent)
{
  //in each call we need to remember the parent to perform balanceTree
  if(root == NULL) {
    root = new AVLNode(e, NULL);
    return;
  }
  else{
      if(t == NULL) {
      t = new AVLNode(e,parent);
      return;
    }
    //checks if insertion takes place in left or right subtree
    else if(e < t->elem){
      parent = t;
      Insert(e, t->left,parent);
    }
    else if(e > t->elem){
      parent = t;
      Insert(e, t->right,parent);
    }

    //when the function recursively goes up
    //it fixes the height and assigns proper rotations

    t = balanceTree(parent); //makes sure subtree root updates
  }
}

/*
  it fixes the height of the tree with root p
  and performs proper rotations
*/
AVLNode * AVLTree::balanceTree(AVLNode * p){
  assignHeight(p);


  if(balFactor(p)==-2) // p is left heavy
    {
      if(balFactor(p->left) > 0) //balFactor > 0 = double rotation case Left Right Left
        p->left = rotateLeft(p->left); //left child points to result of its left rotation
      return rotateRight(p);
    }

  if(balFactor(p)==2) // p is right heavy
    {
      if(balFactor(p->right) < 0) //balFactor < 0 = double rotation case Right Left Right
	p->right = rotateRight(p->right); //right child points to result of its right rotation
      return rotateLeft(p);
    }
  return p; //tree didn't need to be balanced yet, height was updated
}

/*
  if n is left heavy we will rotateRight
*/
AVLNode* AVLTree::rotateRight(AVLNode * n){
  //n represents y, parent of x
  AVLNode * x = n->left;
  //we switch pointers in the right order to get right shape
  n->left = x->right;
  x->right = n;
  //we fixheight of n first since it is lower in the tree now
  assignHeight(n);
  assignHeight(x);
  return x;
}

/*
  symmetric function of rotateRight
 */
AVLNode * AVLTree::rotateLeft(AVLNode * x){
  AVLNode * n = x->right;
  x->right = n->left;
  n->left = x;
  //we fixheight of x first since it is lower in the tree now
  assignHeight(x);
  assignHeight(n);
  return n;
}

/*
  returns true if element 'e' could be found in the tree
 */
bool AVLTree::Access(const int32_t e, AVLNode * & t)
{
  if(t == NULL)
    return false;
  else if(e == t->elem)
    return true;
  else if(e < t->elem)
    return Access(e, t->left);
  else
    return Access(e, t->right);
}

/*
  deletes key 'e' on the tree, replaces it with successor
  and balances the tree if needed
 */
void AVLTree::Delete(const int32_t e, AVLNode * & t)
{
  if(t == NULL) {
    return;
  }
  //checks if deletion takes place in left or right subtree
  else if(e < t->elem) {
    Delete(e, t->left);
    t = balanceTree(t); //balances the tree wit current root 't'
  }
  else if(e > t->elem) {
    Delete(e, t->right);
    t = balanceTree(t); //balances the tree wit current root 't'
  }
  //key 'e' matches t->element so we check if 't'
  //has right and left children in oder to find
  //successor node
  else {
    if(t->left != NULL && t->right != NULL) {
      t->elem = findMin(t->right)->elem;
      Delete(t->elem, t->right);
      t = balanceTree(t); //balances the tree wit current root 't'
    }
    else {
       //node to be deleted has either left or right subtree
       //we can substitute deleted node with its left or right child
      AVLNode *oldNode = t;
      t = (t->left != NULL) ? t->left : t->right;
      delete oldNode;
      return;
    }
  }
}
