/*
  Josue Montenegro
  PA2: Testing of different performace characteristics
       of a BST and AVL tree.
  CS130A
 */

#include <iostream>
#include <sstream>
#include <avl.h>
#include <bst.h>
#include <vector>
#include <algorithm>
#include <string>
#include <ctime>
using namespace std;


void Test1(int N){
  AVLTree avltree;
  BinarySearchTree bst;

  cout << "TEST1 inserts N elements in increasing order, accesses them and deletes them in the same order.\nTEST1 starting..." << endl;

  // AVL //

  cout << "------AVL------" << endl;
  int test_start = clock();

  int start_s = clock();
  for(int i=0; i<N; i++){
    avltree.Insert(i);
  }
  int stop_s = clock();
  cout << "timeInsertAVL: " << (stop_s - start_s)/double(CLOCKS_PER_SEC) << endl;


  start_s = clock();
  for (int i=0; i<N; i++){
    avltree.Access(i);
  }
  stop_s = clock();
  cout << "timeAccessAVL: " << (stop_s - start_s)/double(CLOCKS_PER_SEC) << endl;


  start_s = clock();
  for(int i=0; i<N; i++){
    avltree.Delete(i);
  }
  stop_s = clock();
  cout << "timeDeleteAVL: " << (stop_s - start_s)/double(CLOCKS_PER_SEC) << endl;

  int test_stop = clock();
  cout << "AVL Total Test Time: " << (test_stop - test_start)/double(CLOCKS_PER_SEC) << endl;

  // BST //

  cout << "------BST------" << endl;
  test_start = clock();


  start_s = clock();
  for(int i=0; i<N; i++){
    bst.Insert(i);
  }
  stop_s = clock();
  cout << "timeInsertBST: " << (stop_s - start_s)/double(CLOCKS_PER_SEC) << endl;


  start_s = clock();
  for (int i=0; i<N; i++){
    bst.Access(i);
  }
  stop_s = clock();
  cout << "timeAccessBST: " << (stop_s - start_s)/double(CLOCKS_PER_SEC) << endl;


  start_s = clock();
  for(int i=0; i<N; i++){
    bst.Delete(i);
  }
  stop_s = clock();
  cout << "timeDeleteBST: " << (stop_s - start_s)/double(CLOCKS_PER_SEC) << endl;

  test_stop = clock();
  cout << "BST Total Test Time: " << (test_stop - test_start)/double(CLOCKS_PER_SEC) << endl;

}

void Test2(int N){
  AVLTree avltree;
  BinarySearchTree bst;

  cout << "TEST2 inserts N elements in increasing order, accesses them and d\
eletes them in reverse order.\nTEST2 starting..." << endl;

  // AVL //

  cout << "------AVL------" << endl;
  int test_start = clock();

  int start_s = clock();
  for(int i=0; i<N; i++){
    avltree.Insert(i);
  }
  int stop_s = clock();
  cout << "timeInsertAVL: " << (stop_s - start_s)/double(CLOCKS_PER_SEC) << endl;


  start_s = clock();
  for (int i=0; i<N; i++){
    avltree.Access(i);
  }
  stop_s = clock();
  cout << "timeAccessAVL: " << (stop_s - start_s)/double(CLOCKS_PER_SEC) << endl;

  start_s = clock();
  for(int i=N; i>0; i--){
    avltree.Delete(i);
  }
  stop_s = clock();
  cout << "timeDeleteAVL: " << (stop_s - start_s)/double(CLOCKS_PER_SEC) << endl;

  int test_stop = clock();
  cout << "AVL Total Test Time: " << (test_stop - test_start)/double(CLOCKS_PER_SEC) << endl;

  // BST //

  cout << "------BST------" << endl;
  test_start = clock();


  start_s = clock();
  for(int i=0; i<N; i++){
    bst.Insert(i);
  }
  stop_s = clock();
  cout << "timeInsertBST: " << (stop_s - start_s)/double(CLOCKS_PER_SEC) << endl;


  start_s = clock();
  for (int i=0; i<N; i++){
    bst.Access(i);
  }
  stop_s = clock();
  cout << "timeAccessBST: " << (stop_s - start_s)/double(CLOCKS_PER_SEC) << endl;


  start_s = clock();
  for(int i=N; i>0; i--){
    bst.Delete(i);
  }
  stop_s = clock();
  cout << "timeDeleteBST: " << (stop_s - start_s)/double(CLOCKS_PER_SEC) << endl;

  test_stop = clock();
  cout << "BST Total Test Time: " << (test_stop - test_start)/double(CLOCKS_PER_SEC) << endl;

}

void Test3(int N){
  AVLTree avltree;
  BinarySearchTree bst;

  //in order to randomize the elements we will insert and delete
  //we create a vector that will hold shuffled N elements to be inserted
  //and another similar vector that will hold the elements to be deleted
  vector<int> randomInsert;
  vector<int> randomDelete;
  for(int i=0; i<N; i++){
    randomInsert.push_back(i);
    randomDelete.push_back(i);
  }

  random_shuffle(randomInsert.begin(), randomInsert.end());
  random_shuffle(randomDelete.begin(), randomDelete.end());

  cout << "TEST3 inserts N elements in random order, accesses them and deletes them in random order.\nTEST3 starting..." << endl;

  // AVL //

  cout << "------AVL------" << endl;
  int test_start = clock();

  int start_s = clock();
  for(int i=0; i<N; i++){
    avltree.Insert(randomInsert[i]);
  }
  int stop_s = clock();
  cout << "timeInsertAVL: " << (stop_s - start_s)/double(CLOCKS_PER_SEC) << endl;


  start_s = clock();
  for (int i=0; i<N; i++){
    avltree.Access(randomInsert[i]);
  }
  stop_s = clock();
  cout << "timeAccessAVL: " << (stop_s - start_s)/double(CLOCKS_PER_SEC) << endl;

  start_s = clock();
  for(int i=0; i<N; i++){
    avltree.Delete(randomDelete[i]);
  }
  stop_s = clock();
  cout << "timeDeleteAVL: " << (stop_s - start_s)/double(CLOCKS_PER_SEC) << endl;

  int test_stop = clock();
  cout << "AVL Total Test Time: " << (test_stop - test_start)/double(CLOCKS_PER_SEC) << endl;

  // BST //

  cout << "------BST------" << endl;
  test_start = clock();

  start_s = clock();
  for(int i=0; i<N; i++){
    bst.Insert(randomInsert[i]);
  }
  stop_s = clock();
  cout << "timeInsertBST: " << (stop_s - start_s)/double(CLOCKS_PER_SEC) << endl;

  start_s = clock();
  for (int i=0; i<N; i++){
    bst.Access(randomInsert[i]);
  }
  stop_s = clock();
  cout << "timeAccessBST: " << (stop_s - start_s)/double(CLOCKS_PER_SEC) << endl;

  start_s = clock();
  for(int i=0; i<N; i++){
    bst.Delete(randomDelete[i]);
  }
  stop_s = clock();
  cout << "timeDeleteBST: " << (stop_s - start_s)/double(CLOCKS_PER_SEC) << endl;

  test_stop = clock();
  cout << "BST Total Test Time: " << (test_stop - test_start)/double(CLOCKS_PER_SEC) << endl;
}


int main(){

  cout << "********************************************" << endl;
  cout << "ATTENTION!!! Next tests use 1000 numbers." << endl;
  cout << "********************************************" << endl;
  Test1(1000);
  cout << "********************************************" << endl;
  Test2(1000);
  cout << "********************************************" << endl;
  Test3(1000);
  cout << "********************************************" << endl;

  cout << "ATTENTION!!! Next tests use 100000 numbers." << endl;
  cout << "********************************************" << endl;
  Test1(10000);
  cout << "********************************************" << endl;
  Test2(10000);
  cout << "********************************************" << endl;
  Test3(10000);
  cout << "********************************************" << endl;

  cout << "ATTENTION!!! Next tests use 500000 numbers." << endl;
  cout << "********************************************" << endl;
  Test1(50000);
  cout << "********************************************" << endl;
  Test2(50000);
  cout << "********************************************" << endl;
  Test3(50000);
  cout << "********************************************" << endl;

  return 0;

}
