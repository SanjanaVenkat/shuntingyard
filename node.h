#include <iostream>
#include <cstring>

using namespace std;

class Node{
 public:
  Node(char op);
  ~Node();
  Node* getNext();
  char getOp();
  void setNext(Node* newnext);
 private:
  Node* next;
  char operators;
};
