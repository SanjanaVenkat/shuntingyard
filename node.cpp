#include <iostream>
#include <cstring>
#include "node.h"


Node::Node(char* op) {
  next = NULL;
  strcpy(operators, op);
  int i = 0;
  while (operators[i] != ' ' && operators[i] != '\0') {
    i++;
  }
  operators[i] = '\0';
}

Node::~Node() {

  next = NULL;
}

void Node::setNext(Node* newnext) {
  next = newnext;
}

Node* Node::getNext() {
  return next;
}

char* Node::getOp() {
  return operators;
}


TreeNode::TreeNode(char* t) {
  left = NULL;
  right = NULL;
  up = NULL;
  strcpy(treestuff, t);
}

TreeNode::~TreeNode() {
  left = NULL;
  right = NULL;
  up = NULL;
}

void TreeNode::setLeft(TreeNode* newleft) {
  left = newleft;
}
void TreeNode::setRight(TreeNode* newright) {
  right = newright;
}
void TreeNode::setUp(TreeNode* newup) {
  up = newup;
}

TreeNode* TreeNode::getLeft() {
  return left;
}

TreeNode* TreeNode::getRight() {
  return right;
}

TreeNode* TreeNode::getUp() {
  return up;
}

char* TreeNode::getOpe() {
  return treestuff;
}
