//everything needs to be char*
//need to change stack and binode

#include <iostream>
#include <cstring>
#include <cctype>
#include "Stack.h"
#include "BiNode.h"
#include "Tree.h"

using namespace std;

void printPostfix(BiNode* node);
void printInfix(BiNode* node);
void printPrefix(BiNode* node);
void makeTree(Tree* tree, Stack* in);
void charToStack(char* in, Stack* stack);
void flipStack(Stack* in, Stack* out);
void inToPost(Stack* input, Stack* opers, Stack* postfix);
int isHigher(char* oper1, char* oper2);

int main(){
  //stacks for shunting yard
  Stack* stack1 = new Stack();
  Stack* stack2 = new Stack();
  Stack* opers = new Stack();


  char* infix = new char[20];
  char* postfix = new char[20];
  char* prefix = new char[20];
  char* quit = new char[20];
  strcpy(infix, "infix");
  strcpy(postfix, "postfix");
  strcpy(prefix, "prefix");
  strcpy(quit, "quit");
  
  //read in equation
  cout << "Enter expression: " << endl;
  char* in = new char[256];
  cin.get(in, 256);
  cin.get();

  charToStack(in, stack1);
  flipStack(stack1, stack2);
  //  cout << "3: " << stack2->peek() << endl;
  //while(stack2->isfull() == 0){
  //cout << "oper: " << stack2->peek() << endl;
  //stack2->pop();
  //}

  inToPost(stack2, opers, stack1);
  //cout << "Made it!" << endl;

  flipStack(stack1, stack2);

  //make tree
  Tree* tree = new Tree();
  makeTree(tree, stack2); 

  char* input2 = new char[256];
  
  bool done = false;
  while(!done){
    cout << "'infix' 'prefix' 'postfix' 'quit'" << endl;
    cin.get(input2, 256);
    cin.get();

    for(int i = 0; i < strlen(input2); i++ ){
      input2[i] = tolower(input2[i]);
    }

    if(strcmp(input2, postfix) == 0){
      printPostfix(tree->peek());
      cout << endl;
    }
    else if(strcmp(input2, prefix) == 0){
      printPrefix(tree->peek());
      cout << endl;
    }
    else if(strcmp(input2, infix) == 0){
      printInfix(tree->peek());
      cout << endl;
    }
    else if(strcmp(input2, quit) == 0){
      done = true; 
      delete stack1;
      delete stack2;
      delete opers;
      delete tree;
      delete [] in;
      delete [] infix;
      delete [] prefix;
      delete [] postfix;
      delete [] quit;
    }
  }
  
  return 0;
}
void printPostfix(BiNode* node){
  if(node != NULL){
    printPostfix(node->getLeft());
    printPostfix(node->getRight());
    cout << node->getData();
  }
}

void printPrefix(BiNode* node){
  if(node != NULL){
    cout << node->getData();
    printPrefix(node->getLeft());
    printPrefix(node->getRight());
  }
}

void printInfix(BiNode* node){
  if(node != NULL){
    char* cur = node->getData();
    if(strcmp(cur, "*") == 0 || strcmp(cur, "/") == 0 || strcmp(cur, "+") == 0 || strcmp(cur, "-") == 0 || strcmp(cur, "^") == 0){
      cout << "(";
    }
    printInfix(node->getLeft());
    cout << cur;
    printInfix(node->getRight());
    if(strcmp(cur, "*") == 0 || strcmp(cur, "/") == 0 || strcmp(cur, "+") == 0 || strcmp(cur, "-") == 0 || strcmp(cur, "^") == 0){
      cout << ")";
    }  
  }
}

void makeTree(Tree* tree, Stack* in){
  while(in->isempty() != 0){
    char* cur = in->pop();
    BiNode* node = new BiNode(cur);
    if(strcmp(cur, "*") == 0 || strcmp(cur, "/") == 0 || strcmp(cur, "+") == 0 || strcmp(cur, "-") == 0 || strcmp(cur, "^") == 0){
      BiNode* right = tree->pop();
      BiNode* left = tree->pop();
      node->setRight(right);
      node->setLeft(left);
      tree->push(node);
    }
    else{
      tree->push(node);
    }
  }
}

//make sure stacks are empty
void flipStack(Stack* in, Stack* out){
  while(in->isempty() != 0){
    out->push(in->peek());
    in->pop();
  }
}

//converts char array into Stack, top value is first word
void charToStack(char* in, Stack* stack){
  char* str;
  str = strtok(in, " ");
  while(str != NULL){
    //cout << "str: " << str << endl;
    stack->push(str);
    str = strtok(NULL, " ");
  }
}

//uses shunting yard algorithm to convert from infix notation to postfix notation using Stacks
void inToPost(Stack* infix, Stack* opers, Stack* postfix){
  while(infix->isfull() == 0){
    char* cur = infix->pop();
    //cout << "cur: " << cur << endl;
    //is +-*/^
    if(strcmp(cur, "*") == 0 || strcmp(cur, "/") == 0 || strcmp(cur, "+") == 0 || strcmp(cur, "-") == 0 || strcmp(cur, "^") == 0){
      if(opers->isfull() == 0){
	//if oper is higher precedence
	if(isHigher(cur, opers->peek()) == 3){
	  opers->push(cur);
	}
	//if oper is lower or equal precedence
	else{
	  while(isHigher(cur, opers->peek()) != 3 && opers->isfull() == 0){
	    //  cout << "cur: " << cur << " oper: " << opers->peek() << endl;
	    postfix->push(opers->peek());
	    opers->pop();
	  }
	  opers->push(cur);
	}
      }
      else{
	opers->push(cur);
      }
    }
    //is (
    else if(strcmp(cur, "(") == 0){
      opers->push(cur);
      //cout << opers->isempty() << endl;
    }
    //is (
    else if(strcmp(cur, ")") == 0){
      //cout << "It's a )" << endl;
      while(strcmp(opers->peek(), "(") != 0){
	
	postfix->push(opers->peek());
	//cout << "oper on top: " << opers->peek() << endl;
	opers->pop();
	//cout << "yay" << endl;
	//cout << opers->isempty() << endl;
	//cout << "new top: " << opers->peek() << endl;
      }

      
      opers->pop();
    }
    //is a number
    else{
      postfix->push(cur);
    }
  }
  //add remaining operaators to postfix
  while(opers->isfull() == 0){
    postfix->push(opers->pop());
  }
}
	    
//returns 1 if oper1 is lower precedence
//returns 2 if same
//returns 3 if greater or parentheses
int isHigher(char* oper1, char* oper2){
  if(oper2 == NULL || strcmp(oper2, "(") == 0 || strcmp(oper2, ")") == 0){
    return 3;
  }
  else if(strcmp(oper1, "^") == 0){
    return 3;
  }
  else if((strcmp(oper1, "*") == 0 || strcmp(oper1, "/") == 0) && (strcmp(oper2, "-") == 0 || strcmp(oper2, "+") == 0)){
    return 3;
  }
  else if((strcmp(oper1, "*") == 0 || strcmp(oper1, "/") == 0) && (strcmp(oper2, "*") == 0 || strcmp(oper2, "/") == 0)){
    return 2;
  }
  else if((strcmp(oper1, "-") == 0 || strcmp(oper1, "+") == 0) && (strcmp(oper2, "-") == 0 || strcmp(oper2, "+") == 0)){
    return 2;
  }
  else{
    return 1;
  }
}

