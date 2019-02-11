//Sanjana Venkat
//2.11.19
//Shunting yard, user enters math expression, binary tree created and postfix, prefix, and infix are outputted
#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;
//functions
Node* pushStack(Node* stackstart, char operation[]);
void popStack(Node* stackstart);
Node* pushQueue(Node* queuestart, char operation[]);
void popQueue(Node* queuestart);
void postFix(Node* &finalstart1, Node* &finalstart2, char operation[]);
void pushS(Node* &stackstart, char* operation);
Node* popS(Node* &stackstart);
bool precedenceCheck(char op1, char op2);
void buildTree(Node* finalstack, TreeNode* &treeroot); 
void printPre(TreeNode* treeroot);
void printPost(TreeNode* treeroot);
void printIn(TreeNode* treeroot);

//outer push stack function, pushes operators to stack
Node* pushStack(Node* stackstart, char operation[]) {
  Node* first = stackstart;
  Node* current = stackstart;
  Node* prev = NULL;
  char symbol[100];
 for (int i = 0; i < strlen(operation); i++) {
   if (operation[i] == '+' || operation[i] == '-' || operation[i] == '*' || operation[i] == '/' || operation[i] == '^' || operation[i] == '(' && operation[i] == ')') {
     /*
      //strcpy(symbol, operation[i]);
      current = new Node(& operation[i]);
      //   cout << current->getOp() << endl;
      if (first == NULL) {
	first = current;
	prev = first;
      }
      else {
	current->setNext(prev);
	prev = current;
      }
    
     */
     pushS(first, & operation[i]);
   }
 }
 return first;
     
}


//inner push function, pushes anything to stack
void pushS(Node* &stackstart, char* operation) {
      //strcpy(symbol, operation[i]);
      Node* current = new Node(operation);
      //   cout << current->getOp() << endl;
      if (stackstart == NULL) {
        stackstart = current;
      }
      else {
        current->setNext(stackstart);
        stackstart = current;
      }
    
}


//outer pop stack function, pops entire stack
void popStack(Node* stackstart) {
  
  while (stackstart != NULL) {
    Node* n = popS(stackstart);
    cout << n->getOp() << " ";
  }
  cout << endl;
}

//inner pop stack function, pops top of stack
Node* popS(Node* &stackstart) {
  Node* newsstart = stackstart;
  stackstart = stackstart->getNext();
  return newsstart;
}



//pushes items into queue
Node* pushQueue(Node* queuestart, char operation[]) {
  Node* first = queuestart;
  Node* current = queuestart;
  char symbol[100];
  bool done = false;
  for (int i = 0; i < strlen(operation); i++) {
    if (done == true && operation[i] != ' ' && operation[i] != '\0') {
      continue;
    }
    else {
      done = false;
    }
   
    if (operation[i] != '+' && operation[i] != '-' && operation[i] != '*' && operation[i] != '/' && operation[i] != '^' && operation[i] != ' ' && operation[i] != '(' && operation[i] != ')') {

 
 done = true;
 
     if (current == NULL) {
       current = new Node(& operation[i]);	
	first = current;
      }
      else {
	while (current->getNext() != NULL) {
	  current = current->getNext();
	}
	Node* n = new Node(& operation[i]);
	current->setNext(n);
      }
 

   }
  }
  
 return first;
}




//pops items from queue
void popQueue(Node* queuestart) {
  Node* current = queuestart;
  while (current != NULL) {
    cout << current->getOp() << endl;
    current = current->getNext();
  }
}


//checks order of operations for which of two operators has higher precedence
bool precedenceCheck(char op1, char op2) {

  //op1 is the one at the top of the operator stack
  //op2 is the one being compared
  //when true is returned, op1 >= to op2
  //when false is returned op1 < op2

  // ^ precedence
  if (op1 == '^') {
    if (op2 == '+' || op2 == '-' || op2 == '*' || op2 == '/') {
      return true;
    }
    else if (op2 == '^') {
      return false;
    }
  }
  // * / precedence
  if (op1 == '*' || op1 == '/') {
    if (op2 == '^') {
      return false;
    }
    else if (op2 == '+' || op2 == '-' || op2 == '*' || op2 == '/') {
      return true;
    }
  }
  // + - precedence
   if (op1 == '+' || op1 == '-') {
    if (op2 == '*' || op2 == '/' || op2 == '^' || op2 == '+' || op2 == '-') {
      return false;
    }
  }


}

//test prefix print, not from binary tree, just to test algorithm from user input 
void postFix(Node* &operatorstackstart, Node* &finalstack, char operation[]) {
  int i = 0;
  bool done = false;
  while (operation[i] != '\0') {
    if (done == true && operation[i] != ' ' && operation[i] != '\0') {
      i++;
      continue;
    }
    else {
      done = false;
    }

    //if a space, skip
    if (operation[i] == ' ') {
      i++;
      continue;
    }
    //if an operator
    else if (operation[i] == '+' || operation[i] == '-' || operation[i] == '*' || operation[i] == '/' || operation[i] == '^') {
      done = true;
      if (operatorstackstart != NULL) {
	while (operatorstackstart != NULL && precedenceCheck(*(operatorstackstart->getOp()), operation[i]) == true && *(operatorstackstart->getOp()) != '(') {
	  if (operatorstackstart != NULL) {
	Node* n = popS(operatorstackstart);

	pushS(finalstack, n->getOp());
	  }
	}
      }
   
      pushS(operatorstackstart, & operation[i]);
      i++;
    }
    //if paranthesis
    else if (operation[i] == '(') {
      pushS(operatorstackstart, & operation[i]);
      i++;
    }
    else if (operation[i] == ')') {
      while (*(operatorstackstart->getOp()) != '(') {
	Node* n = popS(operatorstackstart);
	
        pushS(finalstack, n->getOp());
	//i++;
      }
      i++;
      if (operatorstackstart != NULL) {
	Node* n = popS(operatorstackstart);
	
      }
    }
    
    
    //is a number
    
    else if (operation[i] != '+' && operation[i] != '-' && operation[i] != '*' && operation[i] != '/' && operation[i] != '^' && operation[i] != '(' && operation[i] != ')' && operation[i] != ' ' && operation[i] != '\0') {
      
      done = true;
      

      pushS(finalstack, & operation[i]);
      i++;
      
    }

    
  }

  while (operatorstackstart != NULL) {
  Node* n = popS(operatorstackstart);
  
        pushS(finalstack, n->getOp());
  }
  
  //  cout << "operator stack" << endl;
  //popStack(operatorstackstart);
  //    cout << "Prefix: " << endl;
  //popStack(finalstack);

}



//build binary tree
void buildTree(Node* finalstack, TreeNode* &treeroot) {
  TreeNode* lastOp = NULL;
  bool done = false;
  //while stack is not empty
  while (finalstack != NULL) {
    Node* t = popS(finalstack);
    //sets tree root
    if (treeroot == NULL) {
      treeroot = new TreeNode(t->getOp());
      lastOp = treeroot;
    }
    //builds rest of tree
    else {
      TreeNode* current = lastOp;
      done = false;
      while (done == false && current != NULL) {
	//sets right branches to tree to operators from top of stack, until reached a number
	if (current->getRight() == NULL) {
	TreeNode* tn = new TreeNode(t->getOp());
	if (*(t->getOp()) == '+' || *(t->getOp()) == '-' || *(t->getOp()) == '*' || *(t->getOp()) == '/' || *(t->getOp()) == '^') {
   lastOp = tn;
 }
	current->setRight(tn);
	tn->setUp(current);
	done = true;

      }
	//sets left branches to
      else if (current->getLeft() == NULL) {
	TreeNode* tn2 = new TreeNode(t->getOp());
	if (*(t->getOp()) == '+' || *(t->getOp()) == '-' || *(t->getOp()) == '*' || *(t->getOp()) =='/' || *(t->getOp()) == '^') {
  lastOp = tn2;
 }
	current->setLeft(tn2);
	tn2->setUp(current);
	done = true;

      }
	//to move up the tree if both left and right are full
      else {
	current = current->getUp();
      }
      }
      
    }
    
  }
}

//recursive prefix print from binary tree
void printPre(TreeNode* treeroot) {
  TreeNode* current = treeroot;
  if (current != NULL) {
    cout << current->getOpe() << " ";
    printPre(current->getLeft());
    printPre(current->getRight());
  }
  

}
//recursive postfix print from binary tree
void printPost(TreeNode* treeroot) {
  TreeNode* current = treeroot;
  if (current != NULL) {
    printPost(current->getLeft());
    printPost(current->getRight());
    cout << current->getOpe() << " ";
  }

}
//recursive infix print from binary tree
void printIn(TreeNode* treeroot) {
  TreeNode* current = treeroot;
  if (current != NULL) {
    //if operator, print (
    if (*(current->getOpe()) == '+' || *(current->getOpe()) == '-' || *(current->getOpe()) == '*' || *(current->getOpe()) == '/' || *(current->getOpe()) == '^' && *(current->getOpe()) == '(' && *(current->getOpe()) == ')') {
      cout << '(' << " ";
    }
    //numbers and non ( )
    printIn(current->getLeft());
    cout << current->getOpe() << " ";
    printIn(current->getRight());
    // if another operator, print )
    if (*(current->getOpe()) == '+' || *(current->getOpe()) == '-' || *(current->getOpe()) == '*' || *(current->getOpe()) == '/' || *(current->getOpe()) == '^' && *(current->getOpe()) == ')' && *(current->getOpe()) == ')') {
      cout << ')' << " ";
    }
  }
}

  //main
int main() {
  Node* stackstart = NULL;
  Node* queuestart = NULL;
  Node* operatorstackstart = NULL;
  Node* finalstack = NULL;
  TreeNode* treeroot = NULL;
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

  /*
  //  cout << "Push Stack" << endl;
  stackstart = pushStack(stackstart, operation);
  cout << "Pop Stack" << endl;
  popStack(stackstart);
  // cout << "Push Queue" << endl;
  queuestart = pushQueue(queuestart, operation);
  cout << "Pop Queue" << endl;
  popQueue(queuestart);
  */
  //functions to build tree and then output three forms
  postFix(operatorstackstart, finalstack, operation);
  cout << "Building tree" << endl;
  buildTree(finalstack, treeroot);
  cout << "Prefix: " << endl;
  printPre(treeroot);
  cout << endl;
  cout << "Postfix: " << endl;
  printPost(treeroot);
  cout << endl;
  cout << "Infix: " << endl;
  printIn(treeroot);
  cout << endl;
  return 0;
}
