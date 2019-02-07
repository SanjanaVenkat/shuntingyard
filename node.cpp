#include <iostream>
#include <cstring>
#include "node.h"


Node::Node(char op) {
  next = NULL;
  op = operators;
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

char Node::getOp() {
  return operators;
}
