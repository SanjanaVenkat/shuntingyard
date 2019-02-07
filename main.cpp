#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

Node* pushStack(Node* stackstart, char operation[]);
void popStack(Node* stackstart);
Node* pushQueue(Node* queuestart, char operation[]);
void popQueue(Node* queuestart);


Node* pushStack(Node* stackstart, char operation[]) {
  Node* first = stackstart;
  Node* current = stackstart;
  Node* prev = NULL;
  char symbol;
 for (int i = 0; i < strlen(operation); i++) {
    if (operation[i] == '+' || operation[i] == '-' || operation[i] == '*' || operation[i] == '/' || operation[i] == '^') {
      symbol = operation[i];
      current = new Node(symbol);
      cout << current->getOp() << endl;
      if (first == NULL) {
	first = current;
	prev = first;
      }
      else {
	current->setNext(prev);
	prev = current;
      }
    }
  }
 return current;
}

void popStack(Node* stackstart) {
  Node* current = stackstart;
  while (current != NULL) {
    cout << current->getOp() << endl;
    current = current->getNext();
  }
}

Node* pushQueue(Node* queuestart, char operation[]) {
  Node* first = queuestart;
  Node* current = queuestart;
  char symbol;
 for (int i = 0; i < strlen(operation); i++) {
    if (operation[i] != '+' && operation[i] != '-' && operation[i] != '*' && operation[i] != '/' && operation[i] != '^' && operation[i] != ' ') {
      symbol = operation[i];
      if (current == NULL) {
	current = new Node(symbol);
	first = current;
      }
      else {
	while (current->getNext() != NULL) {
	  current = current->getNext();
	}
	Node* n = new Node(symbol);
	current->setNext(n);
      }
    }
  }
 return first;
}



void popQueue(Node* queuestart) {
  Node* current = queuestart;
  while (current != NULL) {
    cout << current->getOp() << endl;
    current = current->getNext();
  }
}



int main() {
  Node* stackstart = NULL;
  Node* queuestart = NULL;
  char response[10];
  char operation[1000];
  char pop[] = "POP";
  char push[] = "PUSH";
  char quit[] = "QUIT";
  cout << "Enter operation" << endl;
  cin.getline(operation, sizeof(operation));
  /*for (int i = 0; i < strlen(operation); i++) {
    if (operation[i] == '+' || operation[i] == '-' || operation[i] == '*' || operation[i] == '/' || operation[i] == '^') {
    cout << operation[i];
    }
  }
cout << endl;
  */
  cout << "Method 1 " << endl;
  stackstart = pushStack(stackstart, operation);
  cout << "Method 2" << endl;
  popStack(stackstart);
  cout << "Method 3" << endl;
  queuestart = pushStack(queuestart, operation);
  cout << "Method 4" << endl;
  popQueue(queuestart);
  return 0;
}
