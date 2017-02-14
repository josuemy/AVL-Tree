/*
  Josue Montenegro
  PA2: Implementation of AVL Tree
  CS130A
 */

#ifndef AVL_H_
#define AVL_H_

#include <string>

using namespace std;

struct AVLNode {
  int32_t elem;
  AVLNode *left;
  AVLNode *right;
  AVLNode *parent;
  int height;

AVLNode(): elem(0), left(NULL), right(NULL), height(1)  {}
AVLNode(const int32_t & e, AVLNode * p): elem(e), left(NULL), right(NULL), height(1), parent(p) {}
};

class AVLTree
{
 public:
  AVLTree (): root() {}
  virtual ~AVLTree () {makeEmpty(root);}
  void Insert (int32_t val);
  // choose smallest node on the right subtree when deleting a node with two children
  void Delete (int32_t val);
  bool Access (int32_t val);
  string PrintPreOrder () const;
  string PrintInOrder () const;

 private:

  AVLNode *root;
  mutable string result;

  int height(AVLNode * n);
  int balFactor(AVLNode* n);
  void assignHeight(AVLNode * n);
  AVLNode * balanceTree(AVLNode * p);
  AVLNode * rotateLeft(AVLNode * x);
  AVLNode * rotateRight(AVLNode * n);
  AVLNode * findMin(AVLNode *t);
  void PrintInOrder(AVLNode * root) const;
  void PrintPreOrder(AVLNode * root) const;
  void makeEmpty(AVLNode * & t);
  void Insert(const int32_t e, AVLNode * & t, AVLNode * parent);
  bool Access(const int32_t e, AVLNode * & t);
  void Delete(const int32_t e, AVLNode * & t);
};

#endif /* end of include guard: AVL_H_ */
