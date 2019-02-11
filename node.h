//Sanjana Venkat
//2.11.19
//node class and tree node class
#include <iostream>
#include <cstring>

using namespace std;
//node class for stack and queue
class Node{
 public:
  Node(char* op);
  ~Node();
  Node* getNext();
  char* getOp();
  void setNext(Node* newnext);
 private:
  Node* next;
  char operators[1000];
};

//tree node class for binary tree
class TreeNode{
public:
  TreeNode(char* t);
  ~TreeNode();
  TreeNode* getLeft();
  void setLeft(TreeNode* newleft);
  TreeNode* getRight();
  void setRight(TreeNode* newright);
  TreeNode* getUp();
  void setUp(TreeNode* newup);
  char* getOpe();
private:
  TreeNode* left;
  TreeNode* right;
  TreeNode* up;
  char treestuff[1000];
};
