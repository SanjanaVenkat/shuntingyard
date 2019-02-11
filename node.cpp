//Sanjana Venkat
//2.11.19
//node class and tree node class functions
#include <iostream>
#include <cstring>
#include "node.h"

//node constructor
Node::Node(char* op) {
  next = NULL;
  strcpy(operators, op);
  int i = 0;
  while (operators[i] != ' ' && operators[i] != '\0') {
    i++;
  }
  operators[i] = '\0';
}
//node destructor
Node::~Node() {

  next = NULL;
}
//set next node
void Node::setNext(Node* newnext) {
  next = newnext;
}
//get next node
Node* Node::getNext() {
  return next;
}
//get operator from node
char* Node::getOp() {
  return operators;
}

//tree node constructor
TreeNode::TreeNode(char* t) {
  left = NULL;
  right = NULL;
  up = NULL;
  strcpy(treestuff, t);
}
//tree node destructor
TreeNode::~TreeNode() {
  left = NULL;
  right = NULL;
  up = NULL;
}
//set left from tree node
void TreeNode::setLeft(TreeNode* newleft) {
  left = newleft;
}
//set right from tree node
void TreeNode::setRight(TreeNode* newright) {
  right = newright;
}
//set up from tree node
void TreeNode::setUp(TreeNode* newup) {
  up = newup;
}
//get left from tree node
TreeNode* TreeNode::getLeft() {
  return left;
}
//get right from tree node
TreeNode* TreeNode::getRight() {
  return right;
}
//get up from tree node
TreeNode* TreeNode::getUp() {
  return up;
}
//get op from tree node
char* TreeNode::getOpe() {
  return treestuff;
}
